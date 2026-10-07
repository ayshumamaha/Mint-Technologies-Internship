# Task 5 – Testing, Build Management and Production-Ready C Project

## Overview

This project demonstrates how a C program can be organized and tested using a structured development approach.

The implementation contains calculator functions for basic arithmetic operations together with an automated test suite. The project can be compiled using a standard C compiler and can also be organized as a CMake-based project for structured build management.

## Objectives

* Develop a structured C program.
* Separate application logic and testing concepts.
* Implement automated tests.
* Validate normal and edge-case inputs.
* Handle division-by-zero errors.
* Use a C compiler for compilation.
* Introduce CMake-based build management.
* Generate clear test results.

## Technologies Used

* **Language:** C
* **Standard:** C11
* **Compiler:** GCC / Clang
* **Build System:** CMake
* **Testing:** CTest / Custom C Test Suite
* **Operating System:** Windows / Linux / WSL

## Features

The calculator implementation supports:

* Addition
* Subtraction
* Multiplication
* Division
* Division-by-zero detection
* Negative-number testing
* Zero-value testing
* Automated test reporting

## Project Structure

For the structured version of the project:

```text
task5/
├── CMakeLists.txt
├── README.md
├── include/
│   └── calculator.h
├── src/
│   └── calculator.c
└── tests/
    └── test_calculator.c
```

A single-file version can also be used when a simple compiler-based implementation is required.

## Testing Approach

The test suite verifies both normal operations and error conditions.

| Test                   | Expected Result    |
| ---------------------- | ------------------ |
| Addition               | Correct sum        |
| Subtraction            | Correct difference |
| Multiplication         | Correct product    |
| Division               | Correct quotient   |
| Division by zero       | Error detected     |
| Negative values        | Correct result     |
| Multiplication by zero | Result equals zero |

## Program Workflow

```text
Compile Source Code
       ↓
Execute Test Suite
       ↓
Run Individual Test Cases
       ↓
Compare Expected and Actual Results
       ↓
Record PASS / FAIL
       ↓
Generate Test Summary
       ↓
Return Success or Failure Status
```

## Compilation – Single File

If using the single-file version:

```bash
gcc task5.c -o task5 -lm
```

Run:

```bash
./task5
```

On Windows:

```bash
gcc task5.c -o task5.exe -lm
```

## CMake Build

For the multi-file version:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running Tests

```bash
ctest --output-on-failure
```

The test system reports whether the test suite completed successfully.

## Expected Result

A successful execution should display individual test results such as:

```text
[PASS] Addition Test
[PASS] Subtraction Test
[PASS] Multiplication Test
[PASS] Division Test
[PASS] Division by Zero Detection
```

followed by a summary of passed and failed tests.

## Learning Outcomes

This task demonstrates how C projects can be developed using structured source organization, automated testing, build management, and documentation. It also introduces the importance of validating both normal program behavior and error conditions before considering an implementation complete.

---

**Author:** M. Ayshwarya
