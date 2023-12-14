#include "roster.h"
// roster.cpp
// Braydan Coffing for C867 Scripting and Programming - Applications

void Roster::parse(string studentdata) //Parses each row one at a time
{
	int rhs = studentdata.find(',');//find the comma, return index
	string sID = studentdata.substr(0, rhs);//extract substring in front of comma

	int lhs = rhs + 1;//move past previous comma
	rhs = studentdata.find(',', lhs);
	string fn = studentdata.substr(lhs, rhs - lhs);//first name

	lhs = rhs + 1;//continue
	rhs = studentdata.find(',', lhs);
	string ln = studentdata.substr(lhs, rhs - lhs);//last name

	lhs = rhs + 1; //continue
	rhs = studentdata.find(",", lhs);
	string email = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1; //continue
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1; //continue
	rhs = studentdata.find(",", lhs);
	int days1 = stod(studentdata.substr(lhs, rhs - lhs));//first number of days

	lhs = rhs + 1; //continue
	rhs = studentdata.find(",", lhs);
	int days2 = stod(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1; //continue
	rhs = studentdata.find(",", lhs);
	int days3 = stod(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);

	DegreeProgram degreeProgram = SECURITY;

	if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') degreeProgram = SECURITY;
	else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') degreeProgram = SOFTWARE;
	else if (studentdata.at(lhs) == 'N') degreeProgram = NETWORK;

	add(sID, fn, ln, email, age, days1, days2, days3, degreeProgram); //Days will go in separately
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
	int darr[3] = { days1,days2,days3 };
	//Makes new student object
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, darr, degreeProgram);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->print();
	}
}

//displays only students that match Degree Program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

//Student emails must include an '@' and '.', and can't include a space ' '
void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = (classRosterArray[i]->getEmailAddress());
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
		{
			any = true;
			cout << email << ": " << classRosterArray[i]->getFirstName() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

//print average number of days in course per student
void Roster::printAverageDaysInCourse(string studentID) 
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID) 
		{
			cout << classRosterArray[i]->getID() << ": ";
			cout << (classRosterArray[i]->getDays()[0]
				+ classRosterArray[i]->getDays()[1]
				+ classRosterArray[i]->getDays()[2]) / 3 << std::endl;
		}
	}
}

void Roster::removeStudentByID(string studentID) //Student to be removed comes in as parameter
{
	bool success = false; 
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true; //means it's found
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i]; //swap with last student
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--; //last book no longer visible
			//didn't delete, just not visible
		}
	}
	if (success)
	{
		cout << studentID << " removed from table." << std::endl << std::endl;
		this->printAll(); //displays students, removed one should not display
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	cout << "Destructor called!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student ID #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

/*
 E. Create a Roster class (roster.cpp) by doing the following:
 1. Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
 2. Create a student object for each student in the data table and populate classRosterArray.
 a. Parse each set of data identified in the “studentData Table.”
 b. Add each student object to classRosterArray.
 3. Define the following functions:
 a. public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
 b. public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
 c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
 d. public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
 e. public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.

 Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

 F. public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type
 */