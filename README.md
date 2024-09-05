# Student Roster Management System

## Course Information
- **Course Title**: Scripting and Programming - Applications - C867
- **Programming Language**: C++
- **Student ID**: 012249526
- **Student Name**: Paolo Gomez

## Project Overview
This C++ application manages a roster of students and their associated details for a fictional university course. It includes functionalities to:
- Add, remove, and print student details
- Calculate average days in course
- Filter students by degree program

## Files Included
- `degree.h`: Defines an enumerated data type `DegreeProgram`
- `student.h`: Header file for the `Student` class
- `student.cpp`: Implementation file for the `Student` class
- `roster.h`: Header file for the `Roster` class
- `roster.cpp`: Implementation file for the `Roster` class
- `main.cpp`: Contains the main function that drives the program

## Setup and Compilation
1. **Clone the repository**:
   ```bash
   git clone URL_OF_YOUR_REPOSITORY
   ```
2. **Navigate to the project directory**:
   ```bash
   cd path_to_project
   ```
3. **Compile the program** using any C++ compiler, e.g., `g++`:
   ```bash
   g++ -o StudentRoster main.cpp student.cpp roster.cpp
   ```
4. **Run the program**:
   ```bash
   ./StudentRoster
   ```

## Features
- Add student records to the roster
- Print all student details
- Identify and display invalid email addresses
- Calculate and display the average number of days each student takes to complete their courses
- Display students by specific degree programs
- Remove students by ID and handle errors for non-existent IDs

## License
This project is licensed under the terms of the MIT license.
