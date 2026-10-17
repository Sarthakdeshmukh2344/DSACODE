# SarthakDeshmukh
## Project Description: Computer Process Scheduling System Using a Linked List

### 1. Introduction

The Computer Process Scheduling System is a simple C++ project that manages computer processes using a linked list. It uses the FCFS (First Come, First Served) scheduling algorithm to execute processes in the order they are added.

### 2. Objectives

- To manage computer processes easily.
- To store process details using a linked list.
- To calculate waiting time and turnaround time.
- To search and delete processes using Process ID.
- To calculate average waiting time and turnaround time.

### 3. Features

1. Add Process: Add a new process with its ID, name, and burst time.
2. Display Processes: View all process details.
3. Schedule Processes: Execute FCFS scheduling and calculate timings.
4. Search Process: Find a process using its ID.
5. Delete Process: Remove a process from the list.
6. Exit: Close the program and free memory.

### 4. Technologies Used

- Programming Language: C++
- Data Structure: Singly Linked List
- Concepts: Structures, pointers, functions, loops, and dynamic memory allocation.

### 5. Working of the Project

The program displays a menu with different options. The user selects an option to add, display, search, or delete processes. The FCFS algorithm calculates each process's waiting time and turnaround time based on the order in which processes were added.

### 6. Data Structure Used

The project uses a singly linked list, where each node stores the Process ID, Process Name, Burst Time, Waiting Time, Turnaround Time, and a pointer to the next node.

### 7. Advantages

- Easy process management.
- Prevents duplicate Process IDs.
- Calculates scheduling times automatically.
- Allows dynamic addition and deletion of processes.

### 8. Limitations

- Process data is lost when the program closes.
- Only the FCFS scheduling algorithm is implemented.
- The program uses a console-based interface.

### 9. Future Enhancements

Priority scheduling, Round Robin scheduling, database storage, and a graphical user interface can be added in the future.

### 10. Conclusion

The Computer Process Scheduling System helps manage processes and calculate scheduling times using C++. It demonstrates the use of linked lists and introduces basic CPU scheduling concepts.
