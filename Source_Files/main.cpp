#include "roster.h"
// main.cpp
// Braydan Coffing for C867 Scripting and Programming - Applications

int main()
{
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Braydan,Coffing,bcoff22@wgu.edu,32,15,35,50,SOFTWARE"
    };

    const int numStudents = 5;
    Roster roster;

    cout << "Course: C867 (Scripting and Programming Applications)" << std::endl;
    cout << "Programming Language: C++" << std::endl;
    cout << "WGU Student ID: 010568155" << std::endl;
    cout << "Name: Braydan Coffing \n" << std::endl;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
    cout << "All students: " << std::endl;
    roster.printAll();
    cout << std::endl;

    cout << "Invalid emails: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;

    cout << "Average days in course: " << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
    roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID());
    } 
    cout << std::endl;

    cout << "Degree program: SOFTWARE" << std::endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    cout << "Removing student with ID A3:" << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;

    cout << "Remove again:" << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;
    
    system("pause");
    return 0;
}

/*
 F. Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
 1. Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
 2. Create an instance of the Roster class called classRoster.
 3. Add each student to classRoster.
 4. Convert the following pseudo code to complete the rest of the  main() function:
 classRoster.printAll();
 classRoster.printInvalidEmails();

 //loop through classRosterArray and for each element:
 classRoster.printAverageDaysInCourse(current_object's student id);

 classRoster.printByDegreeProgram(SOFTWARE);
 classRoster.remove("A3");
 classRoster.printAll();
 classRoster.remove("A3");
 //expected: the above line should print a message saying such a student with this ID was not found.
*/