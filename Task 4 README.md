# Task 4 – Advanced Command-Line Interface Engine

## Overview

This project implements an **interactive command-line interface (CLI) in C**.

The application accepts commands from the user, parses the input, validates the requested operation, performs the corresponding action, and displays the result. It provides a simple key-value management system through an interactive terminal interface.

## Objectives

* Build an interactive CLI application in C.
* Process user input using standard C functions.
* Parse commands and arguments.
* Implement command-based data operations.
* Handle invalid input.
* Implement an interactive command loop.
* Provide clear user feedback.

## Technologies Used

* **Language:** C
* **Compiler:** GCC / Clang
* **Standard:** C11-compatible C compiler
* **Input Handling:** `fgets()`
* **Command Parsing:** `sscanf()`
* **String Processing:** C Standard Library

## Supported Commands

| Command             | Description                 |
| ------------------- | --------------------------- |
| `SET <key> <value>` | Stores or updates a value   |
| `GET <key>`         | Retrieves a stored value    |
| `DELETE <key>`      | Deletes a stored key        |
| `LIST`              | Displays all stored entries |
| `HELP`              | Displays available commands |
| `EXIT`              | Terminates the application  |

## Program Workflow

```text
Display CLI Prompt
       ↓
Read User Input
       ↓
Parse Command
       ↓
Validate Input
       ↓
Execute Requested Operation
       ↓
Display Result
       ↓
Return to CLI Prompt
       ↓
EXIT → Terminate Program
```

## Input Handling

The program uses `fgets()` to safely read complete lines from the terminal. The input is then processed using string comparison and formatted scanning to identify the command and its arguments.

Invalid commands or incorrect syntax are rejected with an appropriate message, and the user is instructed to use the `HELP` command when necessary.

## Compilation

```bash
gcc task4.c -o task4
```

## Execution

```bash
./task4
```

On Windows:

```bash
task4.exe
```

## Example Session

```text
CLI> SET name Aishwarya
Stored: name = Aishwarya

CLI> SET project C Programming
Stored: project = C Programming

CLI> GET name
name = Aishwarya

CLI> LIST

CLI> DELETE name
Deleted: name

CLI> HELP

CLI> EXIT
Exiting CLI...
```

## Learning Outcomes

This task provides practical experience in building interactive command-line applications. It demonstrates string handling, input processing, command parsing, validation, data manipulation, and user-oriented program design in C.

---

**Author:** M. Ayshwarya
