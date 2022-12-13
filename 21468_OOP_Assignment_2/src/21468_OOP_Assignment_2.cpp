//============================================================================
// Name        : 21468_OOP_Assignment_2.cpp
// Author      : Om Panchwate
// Version     :
// Copyright   : PICT OOP Assignments
/* Description :
Develop a program in C++ to create a database of student’s
information system containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other.
Construct the database with suitable member functions. Make use of constructor,
default constructor, copy constructor, destructor, static member functions, friend class,
this pointer, inline code and dynamic memory allocation operators-new and delete as well as
exception handling.*/
//============================================================================

#include <iostream>
using namespace std;
#define MAX_SIZE 20

class Student
{
private:
	string name;
	int roll_no;
	int cls;
	string division;
	string dob;
	string address;
	string tel_no;

public:
	static int count;

	Student(){
		name = "";
		roll_no = 0;
		cls = 0;
		division = "";
		dob = "";
		address = "";
		tel_no = "";
	}

	// Copy Constructor
	Student(Student &std){
			name = std.name;
			roll_no = std.roll_no;
			cls = std.cls;
			division = std.division;
			dob = std.dob;
			address = std.address;
			tel_no = std.tel_no;

			count++;
		}


	void addStudent()
	{
		cout<<"---Add the student details---"<<endl;
		cout<<"Enter the name : ";
		cin>>name;
		cout<<"Enter Roll number : ";
		cin>>roll_no;
		cout<<"Enter Class : ";
		cin>>cls;
		cout<<"Enter Division : ";
		cin>>division;
		cout<<"Enter DOB: ";
		cin>>dob;
		cout<<"Enter Address : ";
		cin>>address;
		cout<<"Enter Telephone number : ";
		cin>>tel_no;

		Student::count++;
	}

	void display()
	{
		cout<<"\nName = "<<name<<endl;
		cout<<"Roll no. = "<<roll_no<<endl;
		cout<<"class = "<<cls<<endl;
		cout<<"Division = "<<division<<endl;
		cout<<"Date of Birth (DD/MM/YYYY = "<<dob<<endl;
		cout<<"Address = "<<address<<endl;
		cout<<"Telephone = "<<tel_no<<endl<<endl;
	}

	~Student()
	{
        cout<<"Deleting the data..."<<endl;
	}
};

int Student::count = 0;


int main() {

	Student* student = new Student[MAX_SIZE];

	//MENU
	bool exit= false;
	int option ;
    while(exit != true){
		cout<<"Select the options : "<<endl;
		cout<<"1) Add Student "<<endl;
		cout<<"2) Display Student"<<endl;
		cout<<"3) Total Students"<<endl;
		cout<<"4) Clear data and Exit...\n"<<endl;
		cout<<"Enter your choice : ";
		cin>>option;

		switch(option)
		{
			case 1 : student[Student::count].addStudent();
					break;

			case 2 :for(int i = 0; i < Student::count; i++)
						student[i].display();
					break;

			case 3 : cout<<"Total Students : "<<Student::count<<endl;
					break;

			case 4 : cout<<"Exit..."<<endl;
			        delete student;
                    exit = true;
					break;

			default : cout<<"Invalid input"<<endl;
		}
    }

	return 0;
}
