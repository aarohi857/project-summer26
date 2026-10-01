# 🚀 High-Performance Task Scheduler

A lightweight, high-performance web application designed for task scheduling and optimization. The application features a native **C++17 REST backend** powered by the Crow Microframework and Standalone Asio, paired with a clean, dynamic visual interface.

---

## 🛠️ Key Features & Technical Highlights

* **High-Performance C++ Backend:** Sub-5ms response handling utilizing Crow HTTP framework.
* **Data Structures & Algorithms (DSA):**
  * **Priority Queue (Max-Heap):** Dynamically schedules tasks using priority weights, due dates, and FIFO tie-breakers.
  * **Custom In-Place Sorting Engine:** Custom algorithms for Quick Sort (by Due Date), Insertion Sort (by Priority), and Bubble Sort (by Title).
  * **Binary Search:** Direct lookup for task query resolution by ID.
* **Flat-File Persistence:** Automatic state saving and dynamic JSON synchronization.
* **Modern Responsive Dashboard:** Glassmorphism UI, real-time metrics tracking via Chart.js, dark/light theme switching, and live notifications.

---

## 🏗️ System Architecture

```text
[Frontend Client (HTML/CSS/JS)] 
          │ 
          ▼ (HTTP / REST API requests) 
  [Crow Web Router] 
          │ 
          ▼ (De-serialization) 
    [TaskManager] ───► (Quick Sort / Insertion Sort / Binary Search) 
          │ 
          ├─► [PriorityManager] ───► (Max-Heap Priority Queue) 
          │ 
          ▼ (File Stream I/O) 
  [tasks_db.json]
