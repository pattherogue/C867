#include "roster.h"
#include <iostream>

int main() {
    // Print out course title, programming language, WGU student ID, and name
    std::cout << "Course Title: Scripting and Programming - Applications - C867" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: [Your WGU Student ID]" << std::endl;
    std::cout << "Name: [Paolo Gomez]" << std::endl << std::endl;

    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,[Paolo],[Gomez],[pgome81@wgu.edu],[28],[daysInCourse1],[daysInCourse2],[daysInCourse3],SOFTWARE"
    };

    Roster classRoster;

    // Add each student to classRoster
    for (const auto& data : studentData) {
        classRoster.parseAndAddStudent(data);
    }

    // Demonstrate required functionality
    std::cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    std::cout << "Displaying invalid emails:" << std::endl;
    classRoster.printInvalidEmails();
    std::cout << std::endl;

    // Print average days in course for each student
    std::cout << "Average days in course:" << std::endl;
    for (const auto& data : studentData) {
        std::string studentID = data.substr(0, data.find(','));
        classRoster.printAverageDaysInCourse(studentID);
    }
    std::cout << std::endl;

    std::cout << "Showing students in degree program: SOFTWARE" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << std::endl;

    std::cout << "Removing student with ID A3:" << std::endl;
    classRoster.remove("A3");
    std::cout << std::endl;

    std::cout << "Displaying all students:" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    std::cout << "Trying to remove student with ID A3 again:" << std::endl;
    classRoster.remove("A3");
    std::cout << std::endl;

    // Destructor is automatically called for classRoster when main() ends

    return 0;
}