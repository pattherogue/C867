#include "student.h"
#include <iostream>

// Constructor implementation
Student::Student(std::string studentID, std::string firstName, std::string lastName, 
                 std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

// Accessor (getter) function implementations
std::string Student::getStudentID() const { return studentID; }
std::string Student::getFirstName() const { return firstName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
const int* Student::getDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// Mutator (setter) function implementations
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print function implementation
void Student::print() const {
    std::cout << studentID << "\t";
    std::cout << "First Name: " << firstName << "\t";
    std::cout << "Last Name: " << lastName << "\t";
    std::cout << "Age: " << age << "\t";
    std::cout << "daysInCourse: {" << daysInCourse[0] << ", " 
              << daysInCourse[1] << ", " << daysInCourse[2] << "} ";
    std::cout << "Degree Program: ";
    switch(degreeProgram) {
        case SECURITY: std::cout << "SECURITY"; break;
        case NETWORK: std::cout << "NETWORK"; break;
        case SOFTWARE: std::cout << "SOFTWARE"; break;
    }
    std::cout << std::endl;
}