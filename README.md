# Car-Dealership-Database
Car Dealership Hash Table Project
Overview

This project is a C++ program that simulates a simple car dealership management system. The program utilizes a hash table implemented as a two-dimensional array of vectors to efficiently store, manage, and retrieve information about cars based on their purchase date. The goal of this project is to handle large volumes of data efficiently, enabling quick searches and data retrieval based on specific dates.
Features

    Hash Table Implementation: Utilizes a hash table to index and store car objects based on purchase dates.
    Efficient Data Management: Designed to handle large datasets with optimized search and retrieval operations using bitwise operations.
    Car Management: Allows users to add, search, and print information about cars in the dealership.
    Persistent Storage: Saves all car information to an output file, allowing data to persist across program runs.
    Input Validation: Ensures that all user inputs are validated and within acceptable ranges.

Requirements

    C++ Compiler: Ensure that you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).
    Development Environment: You can use any C++ IDE (e.g., Visual Studio, CLion) or a text editor with a terminal.

Usage

    Menu Options:
        Add a Car: Allows you to add a new car to the hash table by entering details such as the model, condition, price, color, year, and purchase date.
        Search for Cars: Search for cars based on their purchase date. The program will retrieve and display all cars that match the specified date.
        Print All Cars: Prints out all the cars currently stored in the hash table.
        Exit: Exit the program, saving all car information to the output file.

    File Structure:
        data.txt: Input file that the program reads from. Initially empty but populated with data during program execution.
        output.txt: Output file where all car data is stored after the program runs.

Hashing Function

The program uses a custom hashing function hashIt(targetDate) that uses bitwise operations to generate an index for the hash table. The hashing algorithm ensures that the cars are distributed evenly across the hash table's vectors, optimizing search and retrieval operations.
Contributing

If you have any suggestions or improvements, feel free to open an issue or submit a pull request.

Acknowledgments

    Special thanks to Professor Robert Schmicker for guidance on this project.
    Project developed in collaboration with Richard Hurley.
