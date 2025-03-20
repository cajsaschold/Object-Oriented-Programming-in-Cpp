# TDDE18
The assignments from the course "Programming C++" at LiU

## Time Class Implementation:  
**Folder:** Cpp_Time_OperatorOverloading

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
