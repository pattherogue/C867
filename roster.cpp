#include "roster.h"
#include <iostream>
#include <sstream>

Roster::Roster() : lastIndex(-1) {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, 
                 std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
                 int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, 
                                                age, daysInCourse, degreeProgram);
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            classRosterArray[lastIndex--] = nullptr;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll() const {
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            std::cout << "Student ID: " << studentID << ", average days in course is: " << average << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << studentID << " not found." << std::endl;
}

void Roster::printInvalidEmails() const {
    for (int i = 0; i <= lastIndex; ++i) {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || 
            email.find('.') == std::string::npos || 
            email.find(' ') != std::string::npos) {
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::parseAndAddStudent(const std::string& studentData) {
    std::istringstream ss(studentData);
    std::string token;
    std::string data[9];
    int index = 0;
    
    while (std::getline(ss, token, ',')) {
        data[index++] = token;
    }
    
    DegreeProgram degreeProgram;
    if (data[8] == "SECURITY") degreeProgram = SECURITY;
    else if (data[8] == "NETWORK") degreeProgram = NETWORK;
    else if (data[8] == "SOFTWARE") degreeProgram = SOFTWARE;
    
    add(data[0], data[1], data[2], data[3], std::stoi(data[4]), 
        std::stoi(data[5]), std::stoi(data[6]), std::stoi(data[7]), degreeProgram);
}