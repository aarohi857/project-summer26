#include <crow.h>
#include "TaskManager.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

// Custom CORS Middleware to allow requests from the static HTML frontend
struct CORS {
    struct context {};
    void before_handle(crow::request& /*req*/, crow::response& /*res*/, context& /*ctx*/) {
    }
    void after_handle(crow::request& req, crow::response& res, context& /*ctx*/) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        res.add_header("Access-Control-Allow-Headers", "Content-Type");
        if (req.method == crow::HTTPMethod::OPTIONS) {
            res.code = 204;
            res.end();
        }
    }
};

int main() {
    crow::App<CORS> app;
    TaskManager manager("tasks_db.json");

    std::cout << "Task Scheduler Backend starting..." << std::endl;

    // GET / - Root route to prevent 404 on base URL
    CROW_ROUTE(app, "/")
    ([]() {
        return crow::response(200, "C++ Task Scheduler API is Live and Running!");
    });

    // GET /tasks - Get sorted or unsorted pending tasks
    CROW_ROUTE(app, "/tasks")
    ([&manager](const crow::request& req) {
        char* sortBy = req.url_params.get("sortBy");
        std::vector<Task> tasks;
        if (sortBy != nullptr && std::string(sortBy) != "") {
            tasks = manager.getSortedTasks(sortBy);
        } else {
            tasks = manager.getAllTasks();
        }

        std::vector<crow::json::wvalue> pendingJson;
        for (const auto& task : tasks) {
            if (task.status == "Pending") {
                pendingJson.push_back(task.to_json());
            }
        }
        
        crow::json::wvalue response;
        if (pendingJson.empty()) {
            response = crow::json::wvalue::list();
        } else {
            response = std::move(pendingJson);
        }
        
        crow::response res(response.dump());
        res.add_header("Content-Type", "application/json");
        return res;
    });

    // GET /completedTasks - Get sorted or unsorted completed tasks
    CROW_ROUTE(app, "/completedTasks")
    ([&manager](const crow::request& req) {
        char* sortBy = req.url_params.get("sortBy");
        std::vector<Task> tasks;
        if (sortBy != nullptr && std::string(sortBy) != "") {
            tasks = manager.getSortedTasks(sortBy);
        } else {
            tasks = manager.getAllTasks();
        }

        std::vector<crow::json::wvalue> completedJson;
        for (const auto& task : tasks) {
            if (task.status == "Completed") {
                completedJson.push_back(task.to_json());
            }
        }

        crow::json::wvalue response;
        if (completedJson.empty()) {
            response = crow::json::wvalue::list();
        } else {
            response = std::move(completedJson);
        }
        
        crow::response res(response.dump());
        res.add_header("Content-Type", "application/json");
        return res;
    });

    // POST /tasks - Create a new task
    CROW_ROUTE(app, "/tasks").methods(crow::HTTPMethod::POST)
    ([&manager](const crow::request& req) {
        auto bodyJson = crow::json::load(req.body);
        if (!bodyJson) {
            return crow::response(400, "Invalid JSON body");
        }

        Task t = Task::from_json(bodyJson);
        Task created = manager.addTask(t);
        
        crow::response res(201, created.to_json().dump());
        res.add_header("Content-Type", "application/json");
        return res;
    });

    // PUT /tasks/{id} - Update an existing task
    CROW_ROUTE(app, "/tasks/<int>").methods(crow::HTTPMethod::PUT)
    ([&manager](const crow::request& req, int id) {
        auto bodyJson = crow::json::load(req.body);
        if (!bodyJson) {
            return crow::response(400, "Invalid JSON body");
        }

        Task t = Task::from_json(bodyJson);
        bool success = manager.updateTask(id, t);
        if (success) {
            return crow::response(200, "Task updated successfully");
        }
        return crow::response(404, "Task not found");
    });

    // DELETE /tasks/{id} - Delete a task
    CROW_ROUTE(app, "/tasks/<int>").methods(crow::HTTPMethod::DELETE)
    ([&manager](int id) {
        bool success = manager.deleteTask(id);
        if (success) {
            return crow::response(200, "Task deleted successfully");
        }
        return crow::response(404, "Task not found");
    });

    // GET /search - Search tasks by ID or Title
    CROW_ROUTE(app, "/search")
    ([&manager](const crow::request& req) {
        char* q = req.url_params.get("q");
        if (q == nullptr || std::string(q).empty()) {
            crow::json::wvalue emptyList = crow::json::wvalue::list();
            crow::response res(emptyList.dump());
            res.add_header("Content-Type", "application/json");
            return res;
        }

        std::string queryStr(q);
        std::vector<Task> results;

        bool isNumber = !queryStr.empty() && std::all_of(queryStr.begin(), queryStr.end(), ::isdigit);
        if (isNumber) {
            int id = std::stoi(queryStr);
            bool found = false;
            Task t = manager.searchById(id, found);
            if (found) {
                results.push_back(t);
            }
        } else {
            results = manager.searchByName(queryStr);
        }

        std::vector<crow::json::wvalue> resultsJson;
        for (const auto& task : results) {
            resultsJson.push_back(task.to_json());
        }

        crow::json::wvalue response;
        if (resultsJson.empty()) {
            response = crow::json::wvalue::list();
        } else {
            response = std::move(resultsJson);
        }
        
        crow::response res(response.dump());
        res.add_header("Content-Type", "application/json");
        return res;
    });

    // GET /statistics - Get tasks breakdown metrics
    CROW_ROUTE(app, "/statistics")
    ([&manager]() {
        crow::response res(manager.getStatistics().dump());
        res.add_header("Content-Type", "application/json");
        return res;
    });

    // POST /executePriorityTask - Pop & complete highest priority task
    CROW_ROUTE(app, "/executePriorityTask").methods(crow::HTTPMethod::POST)
    ([&manager]() {
        bool success = false;
        Task t = manager.executeHighestPriorityTask(success);
        if (success) {
            crow::response res(200, t.to_json().dump());
            res.add_header("Content-Type", "application/json");
            return res;
        }
        crow::json::wvalue errResponse;
        errResponse["error"] = "No pending tasks available in the priority queue";
        crow::response res(400, errResponse.dump());
        res.add_header("Content-Type", "application/json");
        return res;
    });

    // POST /completeTask - Mark a task as completed
    CROW_ROUTE(app, "/completeTask").methods(crow::HTTPMethod::POST)
    ([&manager](const crow::request& req) {
        auto bodyJson = crow::json::load(req.body);
        if (!bodyJson || !bodyJson.has("id")) {
            return crow::response(400, "Invalid JSON body or missing task ID");
        }

        int id = bodyJson["id"].i();
        bool success = manager.completeTask(id);
        if (success) {
            return crow::response(200, "Task marked as completed");
        }
        return crow::response(404, "Task not found");
    });

    // Render environment port assignment
    char* portStr = std::getenv("PORT");
    int port = portStr ? std::stoi(portStr) : 18080;
    app.port(port).multithreaded().run();
}
