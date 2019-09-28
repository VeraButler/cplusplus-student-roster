#ifndef ROSTER_H_
#include <string>
#include <iostream>
#include "student.h"

using std::string;

const int classRosterArraySize = 5;
// create an array of pointers classRosterArray - initialize with nullptr
string* classRosterArray[classRosterArraySize] = { nullptr, nullptr, nullptr, nullptr, nullptr };

//Create a student object for each student in the data table using the subclasses
/*NetworkStudent netStudent;
SecurityStudent secStudent;
SoftwareStudent sofStudent;*/

/*
The classRosterArray is the data 
structure (attribute, instance 
variable) of the Roster class. 
It is the array of pointers 
mentioned in the instructions. 
It would be declared in the roster.h
file, as part of the Roster class 
definition. As such, it can be used 
by all the member functions of the 
Roster class, because it is a 
member variable of the Roster class.
*/

// RUBRIC A: Personal information 
//in the last item of the studentData table is complete.
const string studentData[classRosterArraySize] = 
{ 
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Vera,Butler,vbutle5@wgu.edu,32,12,13,45,SOFTWARE" };

// RUBRIC F2: The instance of 
// the Roster class called classRoster is correctly created.

// populate classRosterArray as Roster
//Roster stores a collection of student information
class Roster {
public:
	// variables needed for functions
	int lastIndex;
	int capacity;

	/*
	RUBRIC E1: 
	The array of pointers created to hold the data in the studentData table 
	is complete and correct.
	*/
	Student** classRosterArray; //classRosterArray is an array of pointers to students

	// Define add, rmove, printAll, printDaysInCourse, printValidEmails, printByDegreeProgram
	void add(string datarow);
	void remove(string studentID);

	/*printAll() prints a complete tab-separated list of student data using accessor 
	functions with the provided format: 
	1 [tab] First Name: John 
	[tab] Last Name: Smith 
	[tab] Age: 20 
	[tab]daysInCourse: {35, 40, 55} Degree Program: Security. 
	
	The printAll() function should loop through all  the students in classRosterArray 
	and call the print() function for each student.*/
	void printAll();

	/*
	public void printDaysInCourse(string studentID) that correctly prints a student�s 
	average number of days in the three courses. The student is identified by the studentID parameter.
	*/
	void printAverageDaysInCourse(string studentID);

	/*
	public void printInvalidEmails() that verifies student email addresses and 
	displays all invalid email addresses to the user
	*/
	void printInvalidEmails();

	/*public void printByDegreeProgram(int degreeProgram)*/
	void printByDegreeProgram(Degree degreeProgam);



	//empty cnstructor creates a roster & intiliaizes all fields to default values
	Roster();
	//this contructor does the same as above but additionally sets the max size
	Roster(int newCapacity);
	//Destructor destroys the roster, releasing any resources it requested dynamically
	~Roster();
	
};

#endif //ROSTER_H_