# Library Management System in C++

A robust, object-oriented command-line application built in C++ designed to manage a book library collection efficiently. This project demonstrates core OOP principles, STL containers, and clean input/output handling in C++.

## Features

- **Add Books**: Register new books with a title, author, and publication year.
- **Display Catalog**: View the full list of books currently stored in the library.
- **Search Books**: Look up books by title using partial or exact string matching.
- **Remove Books**: Delete specific books from the catalog by their title.
- **Interactive Console Menu**: A user-friendly, loop-driven interface with built-in input error handling.

## Technologies & Concepts Used

- **Object-Oriented Programming (OOP)**: Classes (`Book`, `Library`), encapsulation, and constructors.
- **C++ Standard Template Library (STL)**: 
  - Dynamic arrays using `std::vector`
  - Algorithms using `std::remove_if` for safe object removal
- **Input Stream Management**: Robust handling of mixed `cin` and `getline` operations to prevent buffer issues.

## How to Compile and Run

1. Clone or download the source code (`main.cpp`).
2. Open your terminal or command prompt in the project directory.
3. Compile the code using a C++ compiler (such as `g++`):
   ```bash
   g++ library.cpp 

Run the executable:

   Windows: library.exe <br>
   Linux / macOS:: ./library
