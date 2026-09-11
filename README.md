#  Arbitrary Precision Calculator (APC)

A **menu-free command-line Arbitrary Precision Calculator (APC)** developed in **C** to perform arithmetic operations on very large integers that exceed the storage capacity of standard C integer data types.

The project uses a **Doubly Linked List** to represent each decimal digit of a number and implements **Addition, Subtraction, Multiplication, and Division** using separate modular functions.

---

## 📌 Table of Contents

* [Project Overview](#-project-overview)
* [Features](#-features)
* [Project Objectives](#-project-objectives)
* [Technologies Used](#-technologies-used)
* [Project Structure](#-project-structure)
* [System Requirements](#-system-requirements)
* [Compilation](#-compilation)
* [Running the Project](#-running-the-project)
* [Supported Operations](#-supported-operations)
* [Functional Description](#-functional-description)
* [Data Structure](#-data-structure)
* [Input Validation](#-input-validation)
* [Workflow](#-workflow)
* [Sample Execution](#-sample-execution)
* [Algorithm Overview](#-algorithm-overview)
* [Future Enhancements](#-future-enhancements)
* [Learning Outcomes](#-learning-outcomes)
* [Author](#-author)

---

## 📌 Project Overview

The **Arbitrary Precision Calculator** is a C-based application designed to perform arithmetic operations on integers of arbitrary length.

Instead of storing the complete number in an `int`, `long`, or other built-in numeric type, each decimal digit is stored in a node of a **Doubly Linked List**.

The project supports:

* Addition
* Subtraction
* Multiplication
* Division

The calculator accepts operands and an operator through **command-line arguments**. The input format is:

```text
./a.out <operand1> <operator> <operand2>
```

For example:

```text
./a.out 12345678901234567890 + 98765432109876543210
```

The project defines separate arithmetic functions for all four operations in `apc.h`.

---

## ✨ Features

* ➕ Addition of large integers
* ➖ Subtraction of large integers
* ✖️ Multiplication of large integers
* ➗ Division of large integers
* 🔗 Doubly linked list implementation
* 🔢 Arbitrary-length integer support
* ✅ Command-line argument validation
* 🔍 Operand comparison
* 🧹 Leading-zero removal
* 💾 Dynamic memory allocation
* 🧩 Modular programming
* 🛠️ Makefile-based compilation
* ⚠️ Division-by-zero validation

---

## 🎯 Project Objectives

* To implement **arbitrary precision arithmetic** in C.
* To understand the practical implementation of **doubly linked lists**.
* To perform arithmetic operations without relying on standard integer limits.
* To strengthen understanding of **pointers and dynamic memory allocation**.
* To implement modular and reusable C functions.
* To practice **command-line argument handling**.
* To implement input validation and error handling.

---

## 🛠️ Technologies Used

| Technology                    | Usage                           |
| ----------------------------- | ------------------------------- |
| **C**                         | Core programming language       |
| **Doubly Linked List**        | Representation of large numbers |
| **Pointers**                  | Linked-list manipulation        |
| **Dynamic Memory Allocation** | Creating and deleting nodes     |
| **File Modules**              | Separating functionality        |
| **GCC**                       | Compilation                     |
| **Makefile**                  | Automated build process         |

The node structure contains `prev`, `data`, and `next` members, allowing traversal in both directions.

---

## 📁 Project Structure

```text
APC/
│
├── main-2.c
├── apc(1).c
├── apc(1).h
├── add(1).c
├── sub(1).c
├── mul(1).c
├── div(1).c
├── makefile(1)
└── README.md
```

### File Description

| File          | Description                                                     |
| ------------- | --------------------------------------------------------------- |
| `main-2.c`    | Handles command-line input and selects the arithmetic operation |
| `apc(1).h`    | Contains structures, macros, and function declarations          |
| `apc(1).c`    | Contains common linked-list and validation functions            |
| `add(1).c`    | Implements addition                                             |
| `sub(1).c`    | Implements subtraction                                          |
| `mul(1).c`    | Implements multiplication                                       |
| `div(1).c`    | Implements division                                             |
| `makefile(1)` | Automates compilation                                           |

The header file defines the arithmetic functions and common linked-list utility functions.

---

## 💻 System Requirements

* GCC Compiler
* Linux / Ubuntu / WSL / macOS
* Command-line terminal
* Basic knowledge of C programming
* Understanding of linked lists

---

## ⚙️ Compilation

### Using Makefile

The project includes a Makefile that automatically converts `.c` files into object files and links them into `a.out`.

Run:

```bash
make
```

The Makefile uses:

```bash
gcc -o a.out *.o
```

to generate the executable.

### Manual Compilation

You can also compile the source files using:

```bash
gcc *.c -o a.out
```

---

## ▶️ Running the Project

The program accepts three command-line arguments:

```text
./a.out <operand1> <operator> <operand2>
```

### Addition

```bash
./a.out 12345678901234567890 + 98765432109876543210
```

### Subtraction

```bash
./a.out 98765432109876543210 - 12345678901234567890
```

### Multiplication

```bash
./a.out 123456789 x 456
```

### Division

```bash
./a.out 987654321 / 123
```

The program validates that exactly three command-line arguments are provided and accepts `+`, `-`, `x`, `X`, and `/` as operators.

---

## 🔧 Supported Operations

### 1. ➕ Addition

Addition is performed digit by digit starting from the least significant digit.

The program uses a **carry** when the sum of two digits is greater than 9.

For example:

```text
   999
 + 123
 -----
  1122
```

The implementation traverses the input lists from their tail nodes and inserts each calculated digit at the beginning of the result list.

---

### 2. ➖ Subtraction

Subtraction uses the standard borrowing technique.

The smaller positive number is subtracted from the larger positive number. The caller determines whether the final result needs a negative sign.

Example:

```text
   1000
 -  456
 ------
    544
```

The program compares both operands before subtraction and determines which operand is larger.

---

### 3. ✖️ Multiplication

Multiplication uses a method similar to traditional **school multiplication**.

Each digit of one number is multiplied by each digit of the other number and placed in the appropriate result position.

Example:

```text
     123
   × 456
   -----
     738
    615
   492
   -----
   56088
```

The implementation uses dynamically allocated integer arrays to temporarily store digits and intermediate multiplication results.

---

### 4. ➗ Division

Division is implemented using **long division with repeated subtraction**.

The program processes the dividend digit by digit, builds the current remainder, and repeatedly subtracts the divisor to determine each quotient digit.

Example:

```text
1000 / 10 = 100
```

Division by zero is checked before the division operation is performed.

---

## 🔗 Data Structure

The project uses a **Doubly Linked List**.

Each node contains:

```c
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
```

This allows the program to move both forward and backward through the digits.

For example, the number:

```text
12345
```

is represented as:

```text
NULL <- [1] <-> [2] <-> [3] <-> [4] <-> [5] -> NULL
```

The `tail` pointer is useful for arithmetic operations such as addition and subtraction because calculations begin from the least significant digit.

---

## ✅ Input Validation

The application validates command-line arguments before performing calculations.

Validation includes:

* Checking the number of arguments.
* Checking whether the operator is valid.
* Checking whether operands contain only digits.
* Checking for empty operands.
* Checking for division by zero.

The validation function accepts `+`, `-`, `x`, `X`, and `/` operators and verifies that both operands contain only decimal digits.

---

## 🧹 Leading Zero Handling

The program removes unnecessary leading zeros while preserving a single zero when the actual value is zero.

For example:

```text
0000012345
```

becomes:

```text
12345
```

The project implements this using the `remove_pre_zeros()` function.

---

## 🔍 Operand Comparison

Before subtraction, the program compares the lengths and corresponding digits of the two numbers.

The comparison function returns:

```text
SAME      → Both operands are equal
OPERAND1  → First operand is larger
OPERAND2  → Second operand is larger
```

This allows the subtraction operation to correctly determine which number should be subtracted from the other.

---

## 🔄 Workflow

```text
                    Start
                      |
                      v
            Read Command-Line Arguments
                      |
                      v
              Validate Input
                      |
                      v
             Create Linked Lists
                      |
                      v
              Remove Leading Zeros
                      |
                      v
               Select Operator
                      |
        +-------------+-------------+
        |             |             |
        v             v             v
      Add           Subtract     Multiply
        |             |             |
        +-------------+-------------+
                      |
                      v
                  Divide
                      |
                      v
              Generate Result
                      |
                      v
                Print Result
                      |
                      v
              Free Allocated Memory
                      |
                      v
                    Exit
```

The main program creates separate linked lists for the two operands and selects the appropriate arithmetic function based on the supplied operator.

---

## 🖥️ Sample Execution

### Addition

```text
$ ./a.out 12345678901234567890 + 98765432109876543210

Result: 111111111011111111100
```

### Subtraction

```text
$ ./a.out 1000000000000 - 123456789

Result: 999876543211
```

### Multiplication

```text
$ ./a.out 123456789 x 456

Result: 56088888884
```

### Division

```text
$ ./a.out 1000 / 10

Result: 100
```

### Division by Zero

```text
$ ./a.out 100 / 0

Error: Division by zero
```

---

## 🧠 Algorithm Overview

### Addition

```text
1. Start from the tail of both linked lists.
2. Add corresponding digits.
3. Add the carry from the previous operation.
4. Store sum % 10 in the result.
5. Calculate carry = sum / 10.
6. Continue until both lists and carry are exhausted.
```

### Subtraction

```text
1. Compare the two operands.
2. Start from the least significant digit.
3. Subtract corresponding digits and borrow.
4. If the result is negative, add 10 and set borrow.
5. Insert the calculated digit into the result.
6. Remove unnecessary leading zeros.
```

### Multiplication

```text
1. Convert the linked-list digits into arrays.
2. Multiply each digit of the first operand
   with each digit of the second operand.
3. Store intermediate results.
4. Propagate carries.
5. Remove leading zeros.
6. Store the final result in a linked list.
```

### Division

```text
1. Process dividend digits from left to right.
2. Build the current remainder.
3. Repeatedly subtract the divisor.
4. Count the number of successful subtractions.
5. Store the count as the quotient digit.
6. Continue until all dividend digits are processed.
```

---

## 🧩 Memory Management

The project uses dynamic memory allocation to create linked-list nodes.

Functions include:

```c
malloc()
calloc()
free()
```

The complete linked lists are released using the `delete_list()` function after the operation is completed.

---

## 📚 Learning Outcomes

Through this project, I gained practical experience in:

* **C Programming**
* **Data Structures**
* **Doubly Linked Lists**
* **Pointers**
* **Structures**
* **Dynamic Memory Allocation**
* **Command-Line Arguments**
* **File/Module Organization**
* **Arithmetic Algorithms**
* **Input Validation**
* **Memory Management**
* **Debugging and Error Handling**
* **Makefile and GCC Compilation**

---

## 🚀 Future Enhancements

Possible future improvements include:

* Add support for decimal/floating-point numbers.
* Add modulus (`%`) operation.
* Improve division efficiency.
* Support negative input operands directly.
* Add automated test cases.
* Improve error messages.
* Add a menu-driven interface.
* Optimize multiplication for extremely large numbers.
* Add unit testing for each arithmetic operation.

---

## 👨‍💻 Author

**Darshuu**

### 📌 Project

**Arbitrary Precision Calculator (APC)**

### 💻 Language

**C Programming**

### 🧠 Concepts

**Data Structures | Doubly Linked List | Pointers | Dynamic Memory Allocation | Algorithms**

---

⭐ If you find this project useful, feel free to star the repository!
