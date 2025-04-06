# OS Lab Experiments

This repository contains C programming lab experiments for college coursework. The experiments cover topics such as process handling, file operations, and directory manipulation. The documentation is generated using **Doxygen**.

## 📂 Repository Structure

```
/YourRepo
│── src/                  # Contains all C program experiments
│   ├── exp3_a.c          # Experiment 3A - Process creation and execution
│   ├── exp3_b.c          # Experiment 3B - File handling using stat()
│   ├── exp3_c.c          # Experiment 3C - Directory handling using opendir(), readdir()
│   ├── exp4_shr_writer.c # Experiment 4 - Shared memory communication (Writer)
│   ├── exp4_shr_reader.c # Experiment 4 - Shared memory communication (Reader)
│   ├── exp5.c            # Experiment 5 - Producer-Consumer problem using Semaphores
│   ├── exp6_a.c          # Experiment 6A - FCFS Scheduling
│   ├── exp6_b.c          # Experiment 6B - SJF Scheduling
│   ├── exp6_c.c          # Experiment 6C - Round Robin Scheduling
│   ├── exp6_d.c          # Experiment 6D - Priority Scheduling
│── README.md             # This file
│── Doxyfile              # Configuration file for Doxygen
│── docs/                 # Auto-generated documentation (after running Doxygen)
```

## 🛠️ Setup and Usage

### **1️⃣ Cloning the Repository**

To clone this repository, run:

```sh
git clone https://github.com/ajasdaison/OS-LAB.git
```

### **2️⃣ Compiling the Programs**

Navigate to the `src/` directory and compile any program using **gcc**:

```sh
cd src
gcc exp3_a.c -o exp3_a
./exp3_a
```

### **3️⃣ Generating Documentation (Doxygen)**

Ensure **Doxygen** is installed, then run:

```sh
doxygen Doxyfile
```

This will generate documentation inside the `docs/` folder.

To view the documentation, open:

```
open docs/html/index.html
```

in a web browser.

## 📜 Experiments Overview

### [**🔗 Experiment 3A: Process Handling**](src/exp3_a.c)

- Demonstrates **fork()** and **execlp()** for process creation and execution.
- Uses **wait()** to synchronize the parent and child process.

### [**🔗 Experiment 3B: File Handling**](src/exp3_b.c)

- Uses **stat()** to retrieve file metadata (permissions, size, owner ID, etc.).

### [**🔗 Experiment 3C: Directory Handling**](src/exp3_c.c)

- Uses **opendir(), readdir(), closedir()** to list files in a directory.

### **🔹 Experiment 4: Shared Memory Communication**

- Implements **Inter-Process Communication (IPC)** using shared memory.
- Demonstrates how memory can be shared between different processes.

- The [**`🔗shared_writer.c`**](src/exp4_shr_writer) program:
  - Creates a shared memory segment.
  - Writes user input into the shared memory.

- The [**`🔗exp4_shr_reader.c`**](src/exp4_shr_reader) program:
  - Reads data from the shared memory.
  - Displays the content written by another process.
  - Detaches and removes the shared memory segment after reading.

### [**🔗 Experiment 5: Producer-Consumer Problem using Semaphores**](src/exp5.c)

- Demonstrates synchronization between multiple processes using semaphores.
- Implements a **producer-consumer** model with a shared buffer of size 3.
- Uses **mutex**, **full**, and **empty** semaphores to coordinate buffer access.
- The producer adds items to the buffer, while the consumer removes them, preventing race conditions.
-The **`exp5.c`** program:
  - Uses **binary and counting semaphores** for mutual exclusion and synchronization.
  - Implements **wait()** and **signal()** operations.
  - Allows the user to choose between producing or consuming an item.


### [**🔗 Experiment 6A: FCFS (First Come First Serve) Scheduling**](src/exp6_a.c)
 
- Implements basic FCFS scheduling.
- Calculates waiting time and turnaround time.
- Displays average waiting and turnaround times.

### [**🔗 Experiment 6B: SJF (Shortest Job First) Scheduling**](src/exp6_b.c)

- Implements non-preemptive SJF scheduling.
- Sorts processes by burst time before calculating waiting and turnaround times.
- Displays sorted process execution order and averages.

### [**🔗 Experiment 6C: Round Robin Scheduling**](src/exp6_c.c)

- Uses time slicing to switch between processes.
- Calculates completion time, waiting time, and turnaround time.
- Accepts user-defined time quantum for the scheduler.

### [**🔗 Experiment 6D: Priority Scheduling**](src/exp6_d.c)

- Processes are scheduled based on user-defined priorities.
- Lower numerical value = higher priority.
- Calculates and displays waiting and turnaround times.
- Shows process order after sorting by priority.

---




