#pragma once
#include "student.h"
// roster.h
// Braydan Coffing for C867 Scripting and Programming - Applications

class Roster {

public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents]; //not declared dynamically

public:
	//parse method parses set of comma delimted strings and extracts data
	void parse(string row);
	//pulls student data and creates student object in roster
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int days1,
		int days2,
		int days3,
		DegreeProgram degreeProgram);
	void printAll(); //calls the print() method in Student class for each student
	void printByDegreeProgram(DegreeProgram studentData); //DegreeProgram is passed in
	void printInvalidEmails(); //Each student's ID requires an @ and ., should not include a space " "
	void printAverageDaysInCourse(string studentID); //Prints students average days in course
	void removeStudentByID(string studentID); //Removes student A3 per requirements
	~Roster();
};