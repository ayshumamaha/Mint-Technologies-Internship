# Task 3 – Concurrency and Multithreading

## Overview

This project demonstrates **multithreading and synchronization in C** using the POSIX Threads library.

The program performs a large number of counter operations using both single-threaded and multi-threaded execution. A mutex is used to protect the shared counter and prevent race conditions when multiple threads access the same data.

## Objectives

* Understand multithreading in C.
* Create and manage POSIX threads.
* Use mutexes for synchronization.
* Protect shared data from race conditions.
* Compare single-thread and multi-thread execution.
* Understand critical sections.
* Perform a basic execution-time benchmark.

## Technologies Used

* **Language:** C
* **Compiler:** GCC
* **Library:** POSIX Threads (`pthread`)
* **Standard:** C11-compatible C compiler
* **Operating System:** Linux / WSL / POSIX-compatible environment

## Features

### Multiple Threads

The program creates multiple worker threads to divide the workload.

### Shared Resource

All worker threads update a common counter.

### Mutex Synchronization

A mutex is used to ensure that only one thread modifies the shared counter at a time.

### Benchmarking

The program compares the execution time of:

* Single-thread execution
* Multi-thread execution

The workload contains **1,000,000 operations**.

## Synchronization Approach

The shared counter represents a critical section because multiple threads attempt to modify the same memory location.

The program follows:

```text
Lock Mutex
    ↓
Update Shared Counter
    ↓
Unlock Mutex
```

This prevents simultaneous modifications from causing inconsistent results.

## Program Workflow

```text
Initialize Mutex
       ↓
Run Single-Thread Test
       ↓
Run Multi-Thread Test
       ↓
Create Worker Threads
       ↓
Perform Operations
       ↓
Synchronize Using Mutex
       ↓
Join Worker Threads
       ↓
Compare Execution Times
       ↓
Destroy Mutex
```

## Compilation

Because the program uses POSIX threads:

```bash
gcc task3.c -o task3 -pthread
```

## Execution

```bash
./task3
```

## Expected Result

The program reports the final counter value and execution time for both single-threaded and multi-threaded execution.

The exact execution time depends on the processor, operating system, compiler, system load, and number of available CPU cores.

## Important Note

The multi-threaded version uses a mutex to maintain correctness. Removing synchronization from the shared counter would introduce the possibility of a race condition.

## Learning Outcomes

This task provides practical experience with concurrent programming in C. It demonstrates thread creation, thread joining, mutex synchronization, shared-resource management, critical sections, and basic performance benchmarking.

---

**Author:** M. Ayshwarya
