# TDDE18
The assignments from the course "Programming C++" at LiU

## Time Class Implementation:  
**Folder:** Time_OperatorOverloading

- Operator overloading for arithmetic (+, -, ++, --) and comparison (==, !=, <, >).
- Arithmetic operations to increment, decrement, add, or subtract seconds from a time instance.
- Input/output handling using overloaded << and >> for easy stream-based interaction.
- Comparison operators (==, !=, <, >, <=, >=) for logical time comparisons.
- Time validation & formatting, ensuring time values are valid and providing a to_string() function for human-readable output.
- AM/PM conversion support for both 24-hour and 12-hour formats.
- Unit testing with Catch2 to validate all functionality, ensuring correctness through automated test cases.

**Files:**  
- time.h – Defines the Time class, including member functions and operator overloads.
- time_test.cc – Contains unit tests to verify the correctness of the Time class.
- catch.hpp – The Catch2 testing framework for structured and modular testing.
- Lab2.cc – Core implementation of the lab assignment, demonstrating time operations in practice.

## Sorted List Implementation
**Folder:** SortedList_Overloading
- Implements a Sorted List data structure using dynamic memory allocation and linked list operations.
- Supports insert, remove, clear, and lookup operations while maintaining sorted order.
- Uses operator overloading for assignment (=) and copy/move constructors.
- Includes size tracking with get_size() and is_empty() methods.
- Provides string conversion functions (list_to_string() and print()) for debugging and visualization.
- Ensures memory safety by implementing a proper destructor and deep copy/move semantics.
- Unit testing with Catch2 framework, verifying all methods through structured test cases.

**Files:**  
- sorted_list.h – Defines the Sorted_List class, including member functions, operator overloads, and private linked list structure.
- sorted_list.cc – Implements the Sorted_List class methods, handling insertions, deletions, and traversal.
- test_sorted_list.cc – Unit tests for Sorted_List, ensuring correctness of all operations.
- test_main.cc – Main test runner for executing Catch2-based test cases.
- catch.hpp – The Catch2 testing framework for modular and structured unit testing.
