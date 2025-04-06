# OS Lab Experiments

This repository contains C programming lab experiments for college coursework. The experiments cover topics such as process handling, file operations, and directory manipulation. The documentation is generated using **Doxygen**.

## 📂 Repository Structure

```
/OS-LAB
│── src/                  # Contains all C program experiments
│   ├── exp2_a.sh         # Experiment 2A: Check Even or Odd
│   ├── exp2_b.sh         # Experiment 2B: Find the Bigger of Two Numbers 
│   ├── exp2_c.sh         # Experiment 2C: Factorial Using While Loop
│   ├── exp2_d.sh         # Experiment 2D: Simple Calculator 
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
│   ├── exp7_a.c          # Experiment 7A: First Fit Memory Allocation
│   ├── exp7_b.c          # Experiment 7B: Worst Fit Memory Allocation
│   ├── exp7_c.c          # Experiment 7C: Best Fit Memory Allocation
│   ├── exp8.c            # Experiment 8: FIFO Page Replacement
│   ├── exp9.c            # Experiment 9: Banker's Algorithm
│   ├── exp10_a.c         # Experiment 10A - FCFS Disk Scheduling
│   ├── exp10_b.c         # Experiment 10B - SCAN Disk Scheduling
│   ├── exp10_c.c         # Experiment 10C - C-SCAN Disk Scheduling
│── CMakeLists.txt        # CMake Setup
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

### [**🔗 Experiment 2A: Check Even or Odd**](src/exp2_a.sh)

Checks whether a given number is even or odd.
Takes input from the user and uses modulus operation.

### [**🔗 Experiment 2B: Find the Bigger of Two Numbers**](src/exp2_b.sh)

Compares two numbers and prints the larger one.

### [**🔗 Experiment 2C: Factorial Using While Loop**](src/exp2_c.sh)

Calculates the factorial of a number using a while loop.
Uses basic arithmetic with expr.

### [**🔗 Experiment 2D: Simple Calculator**](src/exp2_d.sh)

Implements a simple calculator using case statement.
Supports addition, subtraction, multiplication, division.

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

- The [**`🔗shared_writer.c`**](src/exp4_shr_writer.c) program:
  - Creates a shared memory segment.
  - Writes user input into the shared memory.

- The [**`🔗exp4_shr_reader.c`**](src/exp4_shr_reader.c) program:
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

### [**🔗 Experiment 7A: First Fit Memory Allocation**](src/exp7_a.c)

Allocates memory to the first block that is large enough.
Marks blocks as used once a process is allocated.
Reports processes that couldn’t be allocated due to insufficient block size.

### [**🔗 Experiment 7B: Worst Fit Memory Allocation**](src/exp7_b.c)

Sorts memory blocks in descending order.
Allocates each process to the largest available block (worst fit).
Ensures large blocks are filled first, aiming to leave more usable small spaces.
Displays allocation status of all processes.

### [**🔗 Experiment 7C: Best Fit Memory Allocation**](src/exp7_c.c)

Sorts memory blocks in ascending order.
Allocates memory to the smallest block that fits the process.
Ensures minimum internal fragmentation.
Displays memory partitioning and allocation decisions.

### [**🔗 Experiment 8: FIFO Page Replacement**](src/exp8.c)

Simulates the First-In-First-Out (FIFO) page replacement strategy.
Displays the state of frames after each page reference.
Calculates and prints the total number of page faults.

### [**🔗 Experiment 9: Banker's Algorithm**](src/exp9.c)

Implements the Banker's Algorithm for safe resource allocation.
Computes the Need matrix and determines the safe sequence.
Identifies whether the system is in a safe or unsafe state.

### **💿 Disk Scheduling Experiments**

### [**🔗 Experiment 10A: FCFS Disk Scheduling**](src/exp10_a.c)

- Implements First-Come First-Serve (FCFS) disk scheduling algorithm.
- Calculates seek time for each disk request in the given order.
- Displays disk head movement and computes:
    - Total Seek Time
    - Average Seek Time

### [**🔗 Experiment 10B: SCAN Disk Scheduling (Elevator Algorithm)**](src/exp10_b.c)

- Simulates SCAN (Elevator) disk scheduling algorithm.
- Moves disk arm from current head position to 0, then to end of the list.
- Displays track traversal in the SCAN direction.
- Outputs:

   - Track Traversal
   - Seek Differences
   - Total and Average Head Movement

### [**🔗 Experiment 10C: C-SCAN Disk Scheduling**](src/exp10_c.c)

- Implements C-SCAN (Circular SCAN) algorithm.
- Moves the head to the end of the disk, wraps around to 0, and continues.
- Requests are handled in one direction only.
- Output includes:

   - Track Traversal Order
   - Seek Difference between tracks
   - Total and Average Head Movement

---




