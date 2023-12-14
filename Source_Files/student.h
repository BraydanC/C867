#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
// student.h
// Braydan Coffing for C867 Scripting and Programming - Applications

class Student
{
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysArraySize];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
	~Student(); //destructor

/*getters (accessors)*/
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

/*setters (mutators)*/
	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader(); /*displays a header to follow data*/

	void print(); /*displays specific student's data*/
};

/*
 1. Create the class Student in the files student.h and student.cpp, which includes each of the following variables:
 - student ID
 - first name
 - last name
 - email address
 - age
 - array of number of days to complete each course
 - degree program
 */