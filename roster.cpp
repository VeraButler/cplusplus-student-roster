
#include <iostream>
#include <iomanip>
// inlcude all header files except degree.h
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

// using std 
using std::cout;
using std::cerr;
using std::stoi;
using std::to_string;
using std::left;




//default constructor
Roster::Roster() {
	// set defaults to nothing
	this->capacity = 0; 
	this->lastIndex = -1; // empty
	this->classRosterArray = nullptr; 
}

// paramaterized constructor
Roster::Roster(int newCapacity) 
{
	// capacity, lastIndex for classRosterArray
	this->capacity = newCapacity;
	this->lastIndex = -1;// empty

	// create new Student * [newCapacity] to hold the Roster array
	this->classRosterArray = new Student * [newCapacity];
}

//RUBRIC E3A: The public void add(string studentID, string firstName, string lastName,
// string emailAddress, int age, int grade1, int grade2, int grade3, Degree degreeType)

/*
public void add(string studentID, string firstName, string lastName, string emailAddress,
int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, < degree program >)
that sets the instance variables from part D1 and updates the roster.

NOTE: I came up with a different solution that only uses one parameter but meets the specs of the project.
*/
void Roster::add(string row) {
	/*
	RUBRIC E2B:
	Each student object is correctly added to the classRosterArray.
	*/
	if (lastIndex < capacity) {
		// increment lastIndex so it is no longer empty
		lastIndex++;
		// rowLength for is used for accessing last element in classRosterArry
		int rowLength = studentData[lastIndex].length();
		int darray[Student::numberOfDaysToCompleteCourseArraySize];//A temporay array to hold number of days for each Student
		//Test if fiction or nonfiction - cannot create anything of type 'Student'
		//Make the appropriate object now using constructor
		/*
		RUBRIC E2:
		The student object for each student in the data table is correctly
		created and uses each of the given subclasses. 
		classRosterArray is correctly populated.
		*/
		if (row[rowLength - 1] == 'K' )
		{
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegreeType(NETWORK);
		}
		else if (row[rowLength - 1] == 'Y') {
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegreeType(SECURITY);
		}
		else if (row[rowLength - 1] == 'E') {
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
		}
		else
		{
			cerr << "INVALID DEGREE TYPE!  EXITING NOW!\n";
			exit(-1);
		}
		/*
		RUBRIC E2A:
		The pointer operations are correctly applied when parsing each set 
		of data listed in the studentData table.
		*/

		// add through each 'student string' delimiting on the COMMA
		// then extract each subtring and set each field

		//Set the ID
		int rhs = studentData[lastIndex].find(",");
		//cout << studentData[lastIndex].substr(0, rhs) << ' ';
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

		//read firstName
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//read lastName
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));
		// found=str.find('.');
		//if (found != std::string::npos)
		//	std::cout << "Period found at: " << found << '\n';

		//read email
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		//read age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
		classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

		//read each numberOfDaysToCompleteCourse
		//NOTE THAT EACH DAY MUST BE CONVERTED TO A INT
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
		darray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
		darray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		//cout << studentData[lastIndex].substr(lhs, rhs - lhs) << ' ';
		darray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//set the days
		classRosterArray[lastIndex]->setNumberOfDaysToCompleteCourse(darray);
	}
	else
	{
		cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!\n FIX: classRosterArraySize in roster.h line 8. \nEXITING NOW!";
		exit(-1);
	}
}


// RUBRIC E3B: The public void remove(string studentID) that 
// removes students from the roster by student ID is correctly defined.
void Roster::remove(string studentID)
{
	// boolean for found
	bool found = false;
	// loop through classRosterArray to find student by ID
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			// delete student row
			delete this->classRosterArray[i];
			// Move last student to this position - no gaps in array
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			//decrement last index to match current size
			lastIndex--;
			// output student removed
			cout << "Student: " << studentID << " successfully removed.\n\n";
			cout << "NEW ROSTER: \n";
			printAll();
			cout << "\n\n";
		}
	}
	if (!found) cout << "No Student found with that ID." << "\n";
}


/*
RUBRIC E3C: 

The public void printAll() that prints a complete tab-separated
list of student data uses correct accessor functions appropriately. 

The printAll() correctly loops through all the students in 
the student list and correctly calls the print() function for each student.
*/
void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

/*
RUBRIC E3D: A public void printAverageDaysInCourse(string studentID) 
correctly prints a student�s average number of days in the 3 courses 
by student ID. 

The student is correctly identified by the student-ID parameter.
*/
void Roster::printAverageDaysInCourse(string studentID)
{
	// boolean for found
	bool found = false;
	// loop through classRosterArray to find student by ID
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID) // student found
		{
			found = true;
			int* d = classRosterArray[i]->getNumberOfDaysToCompleteCourse();
			cout << "AVERAGE NUMBER OF DAYS TO COMPLETE EACH COURSE FOR SID " << studentID << " is: " << (d[0] + d[1] + d[2]) / 3 << "\n\n";
		}
	}
	if(!found) cout << "No Student found with that ID." << "\n";
}

/*
RUBRIC E3E:
A public void printInvalidEmails() correctly verifies student email
addresses and displays all invalid email addresses to the user.
*/
void Roster::printInvalidEmails()
{
	// boolean value for valid email
	bool valid = true;
	cout << "DISPLAYING ALL INVALID EMAIL ENTRIES:\n";
	// loop1 to find and print invalid email
	for (int i = 0; i <= sizeof(classRosterArray); i++)
	{
		// get email
		string e = classRosterArray[i]->getEmailAddress();
		//cout << "email " << i << ":" << e << "\n";
		//cout << "@ = true" << e.find("@");
		//cout << "space " << isspace(e[i]);

		if (!e.find("@") || !e.find("."))
		{
			valid = false;
			cout << "Student ID " << classRosterArray[i]->getStudentID() << "INVALID EMAIL \n";
			cout << "email[" << e << "]. " << "is missing an @ symbol or a period. ";
		}
		else {
			//loop to find spaces
			for (int j = 0; j <= e.length(); j++) {
				valid = false;
				if (isspace(e[j]) > 0) {
					cout << "Student ID: " << classRosterArray[i]->getStudentID() << ": ";
					cout << "has an invalid email " << "[" << e << "]. " << " All emails must exclude spaces.\n";
				}
			}
		}
	}
	if (valid == true) {
		cout << "All emails are valid.\n";
	}

}

/*
RUBRIC E3F:

A public void printByDegreeProgram (int degreeProgram) correctly prints out
student information for a degree program specified by an enumerated type.

*/
void Roster::printByDegreeProgram(Degree degreeProgram)
{
	cout << "PRINTING BY " << degreeTypeStrings[degreeProgram] << " DEGREE: \n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeType() == degreeProgram) this->classRosterArray[i]->print();
	}
}
/*
RUBRIC F2:
The instance of the Roster class called classRoster is correctly created.

RUBRIC F4:
All pseudo code is correctly converted to complete the rest of the main()
function and is in order.

*/
Roster::~Roster()//destroys all the students
{
	for (int i = 0; i < classRosterArraySize; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}

int main() //MAIN - this is where the program runs
{
	/*
	RUBRIC F1
	The course title, programming language used, student ID, and student name
	are all correctly printed at the top.
	*/
	cout << "Course: C867\nProgramming Language: C++\nStudentID: 000929765\nStudent Name: Vera Butler\n\n";
	Roster* ros = new Roster(classRosterArraySize); //create the roster
	cout << "Parsing data and adding students...\n";
	/*
	RUBRIC F3: All students are added to the classRoster
	*/
	for (int i = 0; i < classRosterArraySize; i++)
	{
		ros->add(studentData[i]);//add EACH LINE, TURN THEM INTO STUDENTS, AND ADD THEM TO ROSTER
	}

	cout << "DISPLAYING ALL STUDENTS:\n";
	// make table more readable
	cout << left << "SID";
	cout << left << "  " << "FIRST";
	cout << left << "     " << "LAST";
	cout << left << "     " << "EMAIL";
	cout << left << "			       " << "AGE";
	cout << left << "       " << "D1";
	cout << left << "        " << "D2";
	cout << left << "        " << "D3";
	cout << left << "        " << "DEGREE\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";
	ros->printAll(); //DISPLAY ALL STUDENTS IN ROSTER

	/*cout << "Removing F4:\n";//REMOVE SAME ITEM TWICE TO CHECK ERROR CONDITION
	if (ros->remove("F4")) ros->printAll();
	else cout << "Student not found!\n";*/

	ros->printByDegreeProgram(NETWORK);
	ros->printByDegreeProgram(SECURITY);
	ros->printByDegreeProgram(SOFTWARE);

	cout << "\nPrinting all invalid email addresses...\n";
	//cout << "---------------------------------\n";
	ros->printInvalidEmails();

	// print average
	cout << "\nPrinting average number of days to complete course...\n";
	ros->printAverageDaysInCourse("A1");
	
	// remove
	cout << "Removing student A1:\n";
	ros->remove("A1"); // if studentID is found printAll is called
	// print DONE
	cout << "DONE. \n";
	/*
	RUBRIC F5:

	The Roster memory is released by calling the destructor.
	*/
	//ros->~Roster();

	system("pause");//NEEDED ONLY TO HOLD CONSOLE WINDOW UP IF USING VSTUDIO
	return 0;

}