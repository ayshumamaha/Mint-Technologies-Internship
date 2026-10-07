# Task 2 – File I/O, Serialization and Disk Storage

## Overview

This project demonstrates **file handling and persistent data storage in C** using binary file operations.

The program maintains a collection of records in memory and provides functionality to save the complete database to a binary file and restore it later. This demonstrates the difference between temporary in-memory data and persistent disk storage.

## Objectives

* Understand file handling in C.
* Work with binary files.
* Use `fopen()`, `fwrite()`, `fread()`, and `fclose()`.
* Store structured data permanently.
* Restore previously saved records.
* Handle file-opening and file-reading errors.
* Demonstrate basic data serialization.

## Technologies Used

* **Language:** C
* **Compiler:** GCC / Clang
* **Standard:** C11-compatible C compiler
* **File Format:** Binary
* **Storage File:** `store.bin`

## Features

### Record Management

Each record contains:

* Record ID
* Name
* Category
* Numeric value

### Binary Storage

The database is written to a binary file using `fwrite()` and restored using `fread()`.

### Persistent Data

Once the database is saved, the information remains available in `store.bin` even after the program terminates.

### Error Handling

The program checks whether the storage file can be opened and whether read/write operations complete successfully.

## Program Workflow

```text
Create Database
      ↓
Add Records
      ↓
Store Records in Memory
      ↓
Save Database to store.bin
      ↓
Program/File Session Ends
      ↓
Open store.bin
      ↓
Read Binary Data
      ↓
Restore Database
      ↓
Display Records
```

## Compilation

```bash
gcc task2.c -o task2
```

## Execution

```bash
./task2
```

On Windows:

```bash
task2.exe
```

## Generated File

When the program is executed, it creates:

```text
store.bin
```

This file contains the serialized database data.

## Expected Result

The program creates multiple records, displays them, saves them to the binary storage file, loads the stored information again, and displays the restored records.

## Learning Outcomes

This task provides practical experience with C file handling and binary data storage. It demonstrates how structured information can be transferred between memory and persistent storage and introduces the basic principles behind serialization and database storage.

---

**Author:** M. Ayshwarya
