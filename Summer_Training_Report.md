# Summer Training/Internship Report

> [!NOTE]
> **Instructions for MS Word Conversion:**
> 1. Set Page Size to **A4**.
> 2. Margins: **Top**: 1 inch (25mm), **Bottom**: 1 inch (25mm), **Right**: 1 inch (25mm), **Left**: 1.5 inches (38mm).
> 3. Font: **Times New Roman** (Body: 12pt, 1.5 Line Spacing; Chapter Titles: 16pt Bold Uppercase; Section Headings: 12pt Bold Uppercase; Table/Figure Captions: 10pt).
> 4. Page Numbers: Center of the footer (Roman numerals for preliminary pages; Arabic numerals starting at "1" for the Introduction chapter onwards).

---

```text
                                   COVER PAGE
                      SUMMER TRAINING/INTERNSHIP REPORT
                             (Term Aug-Dec 2026)

                DEVELOPMENT OF A HIGH-PERFORMANCE TASK SCHEDULER
                 USING C++ REST BACKEND AND CLASSICAL DATA
                         STRUCTURES & ALGORITHMS



                               Submitted by


         Argho Ghosh                      Registration Number: [Your Reg No]
         Arohi                            Registration Number: [Your Reg No]
         Aarju Yadav                      Registration Number: [Your Reg No]



                 School of Computer Science and Engineering
                        Lovely Professional University
                             Phagwara, Punjab
```

---

\newpage

## DECLARATION

We hereby declare that the summer training/internship report entitled **"Development of a High-Performance Task Scheduler using C++ REST Backend and Classical Data Structures & Algorithms"** submitted to the School of Computer Science and Engineering, Lovely Professional University, Phagwara, is a record of our original training work carried out under the academic term of Aug-Dec 2026. 

Any literature, data, or source code referenced from external sources has been duly cited in the bibliography.

**Date:** July 10, 2026  
**Place:** Phagwara, Punjab  

**Submitted by:**  
1. **Argho Ghosh** (Registration No: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_)  
2. **Arohi** (Registration No: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_)  
3. **Aarju Yadav** (Registration No: \_\_\_\_\_\_\_\_\_\_\_\_\_\_\_)  

---

\newpage

## ACKNOWLEDGEMENT

We wish to express our deep sense of gratitude to the **School of Computer Science and Engineering, Lovely Professional University**, for providing us with the opportunity to undertake this summer training project under the Skill Development initiative.

We extend our sincere thanks to our project mentors, professors, and laboratory coordinators who guided us through the design, implementation, and compilation of the C++ network configurations, microframework models, and classical sorting/searching paradigms.

We are also extremely grateful to our group members for their constant collaboration, feedback, and efforts during the frontend design, backend debugging, and validation testing phases.

Finally, we thank our parents and friends for their moral support throughout the duration of this training.

---

\newpage

## TABLE OF CONTENTS

* **Declaration**
* **Acknowledgement**
* **Chapter 1: Introduction of Organization**
  * 1.1 Lovely Professional University (LPU)
  * 1.2 School of Computer Science and Engineering (CSE)
  * 1.3 Skill Development Initiatives
* **Chapter 2: Summer Training Course Content Detail**
  * 2.1 Course Modules and Timelines
  * 2.2 Core Technical Focus
* **Chapter 3: Summer Training/Internship Project Detail**
  * 3.1 Problem Statement
  * 3.2 Project Objectives
  * 3.3 Project Outcomes
  * 3.4 Technologies Used
  * 3.5 System Architecture
* **Chapter 4: Implementation Details & Data Structures**
  * 4.1 Data Structure Mappings
  * 4.2 Algorithm Complexities
* **Chapter 5: Source Code & System Snapshots**
  * 5.1 Backend Source Code
  * 5.2 Frontend Communications
  * 5.3 System Snapshots
* **Chapter 6: Bibliography**

---

\newpage

# CHAPTER 1: INTRODUCTION OF ORGANIZATION

### 1.1 Lovely Professional University (LPU)
Lovely Professional University (LPU) is a premier academic institution located in Phagwara, Punjab. Recognized for its commitment to qualitative education and research, LPU hosts thousands of students in diverse engineering, technology, and applied sciences streams. The university bridges academic learning with industrial requirements, emphasizing hands-on training and project-based assessments.

### 1.2 School of Computer Science and Engineering (CSE)
The School of Computer Science and Engineering (CSE) at LPU is a center of excellence that trains students in modern software engineering principles, algorithm design, data management systems, and web architectures. By introducing frameworks, systems languages (such as C/C++), and professional toolchains, the School of CSE ensures that students develop practical software systems capable of running in high-performance production environments.

### 1.3 Skill Development Initiatives
Under the CSE curriculum guidelines, Summer Training and Skill Development projects are structured to promote active project-based learning. Instead of memorizing theoretical concepts, students are required to implement full-scale applications that combine systems programming, core Data Structures and Algorithms (DSA), and modern visual layouts. This project was developed as a direct outcome of this practical methodology.

---

\newpage

# CHAPTER 2: SUMMER TRAINING COURSE CONTENT DETAIL

### 2.1 Course Modules and Timelines
The summer training course was structured over an 8-week period, diving into low-level engineering, web protocols, and algorithm optimization:

- **Weeks 1-2: Advanced Systems Programming & C++17 Core**
  - Memory management, pointers, and reference parameters.
  - Standard Template Library (STL) containers (`std::vector`, `std::queue`, `std::priority_queue`).
  - Native compilations using compiler flags, dependency linking, and automation via Makefile scripts.
- **Weeks 3-4: Network Routing, REST Architecture & Crow Microframework**
  - HTTP protocols (GET, POST, PUT, DELETE operations).
  - Introduction to asynchronous networking using Standalone Asio libraries.
  - Development of JSON routers and endpoints in C++.
  - Troubleshooting Cross-Origin Resource Sharing (CORS) preflight headers.
- **Weeks 5-6: Core DSA Implementations & Custom Sorting Engine**
  - Implementation of binary heaps to schedule prioritizing structures.
  - Coding custom sorting engines (Bubble Sort, Insertion Sort, Quick Sort) operating on C++ vector ranges.
  - Binary search algorithm integration over sorted vectors.
- **Weeks 7-8: Frontend Engineering & Full Stack Integration**
  - Layout design utilizing responsive CSS variables and grid structures.
  - JavaScript Client implementation using the Fetch API.
  - Dynamic graph plotting using Chart.js based on REST metrics.
  - Full-system integration, E2E browser testing, and automated validations.

---

\newpage

# CHAPTER 3: SUMMER TRAINING/INTERNSHIP PROJECT DETAIL

### 3.1 Problem Statement
Most modern web-based task managers run on resource-heavy runtimes (such as Node.js, Python, or PHP) that add significant CPU and memory overhead. Additionally, task scheduling in standard applications is often simplified to basic sorting, ignoring complex scheduling concepts like Priority Queues (Max-Heaps) where task weights, deadline durations, and insertion orders must resolve concurrently without performance bottlenecks. 

The goal of this project is to build a high-performance **Task Scheduler Web Application** where the frontend is a lightweight client and the entire backend logic is implemented in native **C++**, demonstrating real-world applications of Data Structures and Algorithms (DSA).

### 3.2 Project Objectives
1. **Performance Optimization:** Implement the backend in C++17 to maximize request processing speed and reduce memory consumption.
2. **Decoupled Architecture:** Separate the visual frontend from the data structures layer, using a REST API for communication.
3. **Core DSA Demonstration:** Use a binary heap-based priority queue to resolve priority task executions and custom in-place sorting/searching engines.
4. **Data Persistence:** Maintain state between server restarts using a flat-file database format.

### 3.3 Project Outcomes
- **Fast Responses:** API responses are processed in under 5ms due to Crow's native execution loop.
- **Accurate Scheduling:** High-priority tasks are executed first, with due dates and creation order serving as tie-breakers.
- **Clean UI:** Responsive dashboard design with Dark/Light theme support, providing a modern user experience.

### 3.4 Technologies Used
- **Frontend Layer:** HTML5 (semantic structure), CSS3 (glassmorphic layout variables), JavaScript (fetch calls and Chart.js integration).
- **REST API Middleware:** Crow Microframework (C++ HTTP router), Standalone Asio (asynchronous networking).
- **Core Logic & DSA:** C++17 STL containers (`std::vector`, `std::priority_queue`).
- **Storage Layer:** JSON flat file (`tasks_db.json`) for data persistence.

### 3.5 System Architecture
Data flows when the user interacts with the system:

```text
[Frontend View Client] 
      │ 
      ▼ (fetch JSON payload to Port 18080)
[Crow Web Router]
      │
      ▼ (de-serialize payload to Task objects)
[TaskManager] ───► (performs Quick Sort, Insertion Sort, or Binary Search)
      │
      ├─► [PriorityManager] ──► (constructs Heap Priority Queue for scheduling)
      │
      ▼ (triggers read/write stream)
[FileManager] ───► [tasks_db.json File Database]
```

---

\newpage

# CHAPTER 4: IMPLEMENTATION DETAILS & DATA STRUCTURES

### 4.1 Data Structure Mappings

Table 1 outlines the specific data structures selected for this project, along with their roles and complexity details:

Table 1: Project Data Structure Specifications
| Data Structure | Implementation | Role in Project | Time Complexity (Average) | Space Complexity |
| :--- | :--- | :--- | :--- | :--- |
| **Dynamic Array** | `std::vector<Task>` | Main in-memory storage for active tasks. | Insert: `O(1)`<br>Delete: `O(N)`<br>Access: `O(1)` | `O(N)` |
| **Max-Heap** | `std::priority_queue` | Scheduling and executing the highest priority tasks. | Build: `O(N)`<br>Push: `O(log N)`<br>Pop: `O(log N)` | `O(N)` |
| **Queue** | FIFO Concept | Fallback ordering for equal priority levels. | Enqueue: `O(1)`<br>Dequeue: `O(1)` | `O(N)` |

### 4.2 Algorithm Complexities

Table 2 highlights the custom algorithms implemented in the backend:

Table 2: Algorithm Performance Analysis
| Algorithm | Key Field | Sorting/Searching Logic | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- | :--- |
| **Quick Sort** | Due Date | In-place partitioning using a pivot. | `O(N log N)` | `O(log N)` |
| **Insertion Sort**| Priority | Swaps elements based on priority level. | `O(N^2)` | `O(1)` |
| **Bubble Sort** | Task Title | Lexicographical adjacent swaps. | `O(N^2)` | `O(1)` |
| **Binary Search** | Task ID | Middle-pointer splits on sorted IDs. | `O(log N)` | `O(1)` |
| **Linear Search** | Substring | Sweeps vector for matching titles. | `O(N)` | `O(M)` |

---

\newpage

# CHAPTER 5: SOURCE CODE & SYSTEM SNAPSHOTS

### 5.1 Backend Source Code

Below is the implementation of the priority scheduling comparator in `PriorityManager.h`:

```cpp
#ifndef PRIORITY_MANAGER_H
#define PRIORITY_MANAGER_H

#include "Task.h"
#include <queue>
#include <vector>

// Custom comparator for priority task execution scheduling
struct TaskPriorityCompare {
    bool operator()(const Task& a, const Task& b) const {
        // Map string priorities to numeric values
        auto getPriorityWeight = [](const std::string& p) -> int {
            if (p == "High") return 3;
            if (p == "Medium") return 2;
            return 1; // "Low"
        };

        int weightA = getPriorityWeight(a.priority);
        int weightB = getPriorityWeight(b.priority);

        // Rule 1: Higher priority weight wins
        if (weightA != weightB) {
            return weightA < weightB; 
        }

        // Rule 2: If priorities match, earlier due date wins (lexicographical comparison)
        if (!a.dueDate.empty() && !b.dueDate.empty() && a.dueDate != b.dueDate) {
            return a.dueDate > b.dueDate; 
        }

        // Rule 3: If due dates also match, FIFO order wins (earlier ID is processed first)
        return a.id > b.id;
    }
};

class PriorityManager {
public:
    static std::priority_queue<Task, std::vector<Task>, TaskPriorityCompare> buildPriorityQueue(const std::vector<Task>& tasks);
};

#endif
```

Below is the custom in-place sorting implementations in `TaskManager.cpp`:

```cpp
#include "TaskManager.h"
#include "PriorityManager.h"
#include <algorithm>
#include <iostream>

// Helper to partition the vector for Quick Sort
int partition(std::vector<Task>& arr, int low, int high) {
    std::string pivot = arr[high].dueDate;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Earlier due date comes first
        if (arr[j].dueDate < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// In-place Quick Sort by Due Date
void quickSort(std::vector<Task>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// In-place Insertion Sort by Priority Weight
void insertionSortPriority(std::vector<Task>& arr) {
    auto getWeight = [](const std::string& p) -> int {
        if (p == "High") return 3;
        if (p == "Medium") return 2;
        return 1;
    };

    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Task key = arr[i];
        int j = i - 1;

        while (j >= 0 && getWeight(arr[j].priority) < getWeight(key.priority)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

Below is the implementation of the search operations in `TaskManager.cpp`:

```cpp
// Binary Search for Task by ID
Task* TaskManager::searchById(int id, bool& found) {
    found = false;
    int low = 0;
    int high = tasks.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (tasks[mid].id == id) {
            found = true;
            return &tasks[mid];
        }
        if (tasks[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return nullptr;
}
```

### 5.2 Frontend Integration

Below is the JavaScript API fetch client in `app.js`:

```javascript
// Fetch tasks from the C++ server and update the UI
async function fetchTasks(sortBy = '') {
  try {
    const url = sortBy ? `${API_URL}/tasks?sortBy=${sortBy}` : `${API_URL}/tasks`;
    const response = await fetch(url);
    if (!response.ok) throw new Error('Failed to load tasks.');
    
    const tasks = await response.json();
    renderTasksGrid(tasks);
  } catch (error) {
    showToast(error.message, 'error');
  }
}
```

### 5.3 System Snapshots

Please capture and paste your web browser screenshots below:

```text
+---------------------------------------------------------------------------------+
|                                 INSERT SNAPSHOT                                 |
|                                                                                 |
|                        Figure 1: Dashboard Page Layout                          |
+---------------------------------------------------------------------------------+
```
Figure 1: Dashboard Page Layout

```text
+---------------------------------------------------------------------------------+
|                                 INSERT SNAPSHOT                                 |
|                                                                                 |
|                        Figure 2: Tasks List Page View                           |
+---------------------------------------------------------------------------------+
```
Figure 2: Tasks List Page View

```text
+---------------------------------------------------------------------------------+
|                                 INSERT SNAPSHOT                                 |
|                                                                                 |
|                      Figure 3: Priority Checkmark Overlay                       |
+---------------------------------------------------------------------------------+
```
Figure 3: Priority Checkmark Overlay

```text
+---------------------------------------------------------------------------------+
|                                 INSERT SNAPSHOT                                 |
|                                                                                 |
|                      Figure 4: Completed Tasks Archive                          |
+---------------------------------------------------------------------------------+
```
Figure 4: Completed Tasks Archive

```text
+---------------------------------------------------------------------------------+
|                                 INSERT SNAPSHOT                                 |
|                                                                                 |
|                        Figure 5: About Project Page                             |
+---------------------------------------------------------------------------------+
```
Figure 5: About Project Page

---

\newpage

# CHAPTER 6: BIBLIOGRAPHY

1. **Stroustrup, B.** (2013). *The C++ Programming Language* (4th Edition). Addison-Wesley Professional.
2. **Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C.** (2009). *Introduction to Algorithms* (3rd Edition). MIT Press.
3. **Crow C++ Microframework Documentation.** Retrieved from https://crowcpp.org/.
4. **Standalone Asio Library Documentation.** Retrieved from https://think-async.com/Asio/.
5. **MDN Web Docs: Fetch API.** Mozilla Developer Network. Retrieved from https://developer.mozilla.org/.
6. **Chart.js Documentation.** Chart.js Foundation. Retrieved from https://www.chartjs.org/.
