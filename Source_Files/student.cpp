#include "student.h"
// student.cpp
// Braydan Coffing for C867 Scripting and Programming - Applications

Student::Student()//parameterless constructor - sets to default values
{
	//(pointer_name)->(variable_name)
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->emailAddress = "";
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram:: SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram)
{
	//(pointer_name)->(variable_name)
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} // destructor does nothing because nothing is created dynamically but write it anyway; always write the desctructor

//Getters (accessors)
string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age;  }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Setters (mutators), requires incoming parameter
void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int days[])
{
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()/*use to print header*/
{
	cout << "Output format: StudentID|FirstName|LastName|Age|DaysInCourse|DegreeProgram\n";
}

void Student::print()
{
	cout << this->getID() << '\t'; /*Tab separates output and getters*/
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t';
	cout << "daysInCourse: {" << this->getDays()[0] << ", " << this->getDays()[1] << ", " << this->getDays()[2] << "}" << '\t'; //grabs days individually instead of with pointer to collate into {}
	cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << '\n'; /*degreeProgram to a string instead of int*/
};

/*
 2. Create each of the following functions in the Student class:
 a. an accessor (i.e., getter) for each instance variable from part D1
 b. a mutator (i.e., setter) for each instance variable from part D1
 c. All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
 d. constructor using all of the input parameters provided in the table
 e. print() to print specific student data
 */