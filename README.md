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

### **🔹 Experiment 3A: Process Handling**

- Demonstrates **fork()** and **execlp()** for process creation and execution.
- Uses **wait()** to synchronize the parent and child process.

### **🔹 Experiment 3B: File Handling**

- Uses **stat()** to retrieve file metadata (permissions, size, owner ID, etc.).

### **🔹 Experiment 3C: Directory Handling**

- Uses **opendir(), readdir(), closedir()** to list files in a directory.

### **🔹 Experiment 4: Shared Memory Communication**

- Implements **Inter-Process Communication (IPC)** using shared memory.
- Demonstrates how memory can be shared between different processes.

- The **`shared_writer.c`** program:
  - Creates a shared memory segment.
  - Writes user input into the shared memory.

---




