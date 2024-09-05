#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>

class Roster {
private:
    Student* classRosterArray[5]; // Array of pointers to hold Student objects
    int lastIndex; // To keep track of the last added student

public:
    Roster(); // Constructor
    ~Roster(); // Destructor

    void add(std::string studentID, std::string firstName, std::string lastName, 
             std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
             int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    
    // Helper function to parse the student data string
    void parseAndAddStudent(const std::string& studentData);
};

#endif // ROSTER_H