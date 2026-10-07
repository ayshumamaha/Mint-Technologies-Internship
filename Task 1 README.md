# Task 1 – Core Data Structures and Dynamic Memory Management

## Overview

This project demonstrates the implementation of a **hash table in C** using structures, pointers, dynamic memory allocation, and linked-list-based collision handling.

The program provides a simple key-value storage mechanism where values can be inserted, searched, updated, deleted, and displayed. Dynamic memory is used to allocate storage for keys and values at runtime, while proper memory deallocation is performed during deletion and final cleanup.

## Objectives

* Implement a hash table using C structures.
* Understand pointers and dynamic memory allocation.
* Implement key-value storage.
* Handle hash collisions using separate chaining.
* Perform insertion, searching, updating, and deletion.
* Manage dynamically allocated memory safely.
* Demonstrate complete memory cleanup.

## Technologies Used

* **Language:** C
* **Compiler:** GCC / Clang
* **Concepts:** Structures, pointers, dynamic memory, hashing, linked lists
* **Standard:** C11-compatible C compiler

## Features

### Hash Table

The program uses a fixed-size hash table containing multiple buckets. A hash function converts each key into a bucket index.

### Collision Handling

Multiple keys may generate the same hash value. The implementation handles these collisions using **separate chaining**, where entries are connected using linked lists.

### Dynamic Memory Management

Memory for keys, values, and entries is allocated using `malloc()` and released using `free()`.

### CRUD Operations

The program supports:

* `SET` – Insert or update a value
* `GET` – Search for a value
* `DELETE` – Remove an entry
* `LIST/DISPLAY` – Display stored entries

## Program Workflow

```text
Initialize Hash Table
        ↓
Generate Hash Index
        ↓
Insert Key-Value Pair
        ↓
Handle Collision if Required
        ↓
Search / Update / Delete
        ↓
Display Stored Data
        ↓
Free Allocated Memory
        ↓
Program Termination
```

## Compilation

```bash
gcc task1.c -o task1
```

## Execution

```bash
./task1
```

On Windows:

```bash
task1.exe
```

## Expected Result

The program creates several key-value pairs, searches for a stored value, updates an existing value, deletes an entry, displays the remaining data, and finally releases all dynamically allocated memory.

## Learning Outcomes

This task provides practical understanding of data structures and memory management in C. It demonstrates how pointers, structures, dynamic allocation, hashing, and linked lists can be combined to build a functional in-memory storage system.

---

**Author:** M. Ayshwarya
