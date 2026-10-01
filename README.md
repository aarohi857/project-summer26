High-Performance Task SchedulerA lightweight, high-performance web application designed for task scheduling and optimization. The application features a native C++17 REST backend powered by the Crow Microframework and Standalone Asio, paired with a clean, dynamic, glassmorphic visual interface built with modern HTML5, CSS3, JavaScript, and Chart.js.🛠️ Key Features & Technical HighlightsHigh-Performance C++ Backend: Sub-5ms response handling utilizing Crow HTTP framework.Data Structures & Algorithms (DSA):Priority Queue (Max-Heap): Dynamically schedules tasks using priority weights, due dates, and FIFO tie-breakers.Custom In-Place Sorting Engine: Custom algorithms for Quick Sort (by Due Date), Insertion Sort (by Priority), and Bubble Sort (by Title).Binary Search: $O(\log N)$ fast lookup for task query resolution by ID.Flat-File Database Persistence: Automatic state saving and dynamic JSON synchronization using standard streams.Modern Responsive Dashboard: Glassmorphism UI, real-time metrics tracking via Chart.js, dynamic category management, dark/light theme switching, and live notifications.🏗️ System Architecture[Frontend Client (HTML/CSS/JS)] 
          │ 
          ▼ (HTTP / REST API requests)
  [Crow Web Router]
          │
          ▼ (De-serialization)
    [TaskManager] ───► (Quick Sort / Insertion Sort / Binary Search)
          │
          ├─► [PriorityManager] ──► (Max-Heap Priority Queue)
          │
          ▼ (File Stream I/O)
    [tasks_db.json]
🚀 Getting StartedPrerequisitesC++ Compiler: Supporting C++17 (g++ or clang++)Build Automation: make (optional)Dependencies: Crow C++ Microframework and AsioRunning the BackendNavigate to the Backend folder:cd Backend
Compile and run the server using make:make run
(Or compile directly using g++ -std=c++17 main.cpp TaskManager.cpp PriorityManager.cpp FileManager.cpp -o scheduler -lpthread)The REST API server will start on http://localhost:18080.Running the FrontendOpen Frontend/index.html directly in any web browser, or serve it using a local static file server.📄 API Endpoints SummaryMethodEndpointDescriptionGET/tasksRetrieve all active tasks (Supports query params ?sortBy=dueDate/priority/title)POST/tasksCreate a new task entryPUT/tasks/<id>Update an existing taskDELETE/tasks/<id>Delete a taskGET/tasks/nextFetch the highest-priority task from the Max-Heap👨‍💻 Team MembersArgho GhoshArohiAarju YadavSchool of Computer Science and Engineering, Lovely Professional University, Phagwara, Punjab.
