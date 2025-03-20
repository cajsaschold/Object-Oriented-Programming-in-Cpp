# Object Oriented Programming in C++
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


## Electrical Circuit Simulation
**Folder:** Circuit_Simulation
- Implements a circuit simulation framework using object-oriented programming (OOP) principles in C++.
- Defines an abstract base class (Component) for electrical components, with derived classes for Battery, Resistor, and Capacitor.
- Supports polymorphism, allowing components to be handled generically within a Circuit class.
- Uses dynamic memory management to store and manipulate electrical components in a circuit.
- Simulates electrical behavior over time with numerical integration (step() method).
- Prints circuit status and component values at specified intervals.

**Files:**
- component.h / component.cc – Defines the base Component class and derived classes (Battery, Resistor, Capacitor).
- circuit.h / circuit.cc – Implements the Circuit class, managing component connections and simulation.
- battery.cc – Defines the behavior of a battery in the circuit.
- resistor.cc – Implements Ohm’s Law for resistors.
- capacitor.cc – Models capacitive charge storage and current flow.
- main.cc – Entry point for executing the circuit simulation.

## Text Editor Implementation
**Folder:** Text_Editor
- Implements a basic text editor in C++ with functions for string manipulation and text processing.
- Utilizes dynamic memory management and efficient string operations for handling user input.
- Encapsulates text-processing logic within modular functions, improving code readability and maintainability.
- Provides functionality for inserting, deleting, searching, and modifying text dynamically.
- Uses object-oriented programming (OOP) principles to structure text operations efficiently.

**Files:**
- text_editor.cc – Main file handling user interactions and command processing.
- text_functions.cc – Implements core text manipulation functions, such as search, replace, and formatting.
