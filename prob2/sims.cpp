#include "sims.h"
#include "Student.h"
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

sims::sims() {}

//function to insert the students from the file in the list
void sims::add_student_from_file(fstream& myfile)
{
	string line;
	myfile.seekg(0, ios::beg);
	while (getline(myfile, line))
	{
		
		stringstream ss(line);
		string name, student_ID, birth_year, department, tel;
		getline(ss, name, ';');
		getline(ss, student_ID, ';');
		getline(ss, birth_year, ';');
		getline(ss, department, ';');
		getline(ss, tel, ';');

		Student s(name, student_ID, birth_year, department, tel);
		student_list.push_back(s);
	}
	cout << "DEBUG Number of students in list: " << student_list.size() << endl;
	myfile.clear();
	myfile.seekp(0, ios::end);
}

//method to insert a student
	void sims::insert_student(fstream& myfile)
	{
		//asking the user for informations on the student
		cout << "\n- Insert student -\n";
		cout << "Name ? ";
		string name;
		do {
			cin >> name;
			if(name.length()>15 || name=="")
			cout << "Invalid input. Please try again ";
		} while (name.length() > 15 || name == "");

		cout << "Student ID (10 digits) ? ";
		string student_ID;
		bool found; 

		do {
			found = false;
			cin >> student_ID;
			if (student_ID.length() != 10 || student_ID =="")
			{
				cout << "Invalid input. Please try again ";
			}

			//checking if a student already has the same student ID
			for (Student s : student_list)
			{
				if (student_ID == s.getStudentID())
				{
					cout << "Error : already inserted. Please provide an other student ID\n";
					found = true;
				}
			}
		} while (student_ID.length() != 10 || student_ID == ""||found == true);

		cout << "Birth year (4 digits) ? ";
		string birth_year;
		do {
			cin >> birth_year;
			if (birth_year.length() != 4 || birth_year == "")
			{
				cout << "Invalid input. Please try again ";
			}
		} while (birth_year.length() != 4 || birth_year == "");
	

		cout << "Department ? ";
		string department;
		cin.ignore(); 
		getline(cin, department);

		cout << "Tel (12 digits) ? ";
		string tel;
		do {
			cin >> tel;
			if (tel.length() >12 || tel == "")
			{
				cout << "Invalid input. Please try again";
			}
		} while (tel.length() > 12 || tel == "");

		Student s(name, student_ID, birth_year, department, tel);
		student_list.push_back(s);
		cout << "\nStudent successfully added in the list";

		//cout << "\nDEBUG Number of students in list: " << student_list.size() << endl;

		myfile.seekp(0, ios::end); 
		myfile << name << ";"
			<< student_ID << ";"
			<< birth_year << ";"
			<< department << ";"
			<< tel << endl;
		cout << "\nStudent successfully added in the file";
	
	};

//method to search for a student
	void sims::search_student(fstream& myfile)
	{
		myfile.clear();  
		myfile.seekg(0);  
		cout << "\n- Search -\n";
		cout << "1. Search by name"
			<< "\n2. Search by student ID (10 digits)"
			<< "\n3. Search by admission year (4 digits)"
			<< "\n4. Search by birth year (4 digits)"
			<< "\n5. Search by department name"
			<< "\n6. List all"
			<<"\n>";
		int choice;
		do {
			cin >> choice;
			if (choice == 0 || choice > 6)
			{
				cout << "Input error, please try again";
			}
		} while (choice == 0 || choice > 6);
		switch (choice)
		{
			//search by name
		case 1:{
			//cout << "DEBUG Number of students in list: " << student_list.size() << endl;
			cout << "Name keyword ? ";
			string keyword;
			cin >> keyword;
			bool found = false;
			for (Student s : student_list)
			{
				if (s.getName() == keyword) {
					cout << "\nName             Student ID       Dept                 Birth Year            Tel" << endl;
					cout << s.getName() << "             ";
					cout << s.getStudentID() << "         ";
					cout << s.getDept() << "          ";
					cout << s.getBY() << "         ";
					cout << s.getTel() << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "\nstudent not found";
			}
			break;
		}

			  //search by student ID
		case 2: {
			//cout << "DEBUG Number of students in list: " << student_list.size() << endl;
			cout << "Student ID keyword ? ";
			string keyword;
			cin >> keyword;
			bool found = false;
			for (Student s : student_list)
			{
				if (s.getStudentID() == keyword)
				{
					cout << "\nName             Student ID       Dept                 Birth Year      Tel" << endl;
					cout << s.getName() << "             ";
					cout << s.getStudentID() << "         ";
					cout << s.getDept() << "          ";
					cout << s.getBY() << "         ";
					cout << s.getTel() << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "\nstudent not found";
			}
			break;
		}
			  //search by admission year
		case 3 : 
		{
			cout << "Admission year keyword ? ";
			string keyword;
			cin >> keyword;
			bool found = false;
			for (Student s : student_list)
			{
				if (s.getStudentID().substr(0, 4) == keyword)
				{
					cout << "\nName             Student ID       Dept                 Birth Year      Tel" << endl;
					cout << s.getName() << "             ";
					cout << s.getStudentID() << "         ";
					cout << s.getDept() << "          ";
					cout << s.getBY() << "         ";
					cout << s.getTel() << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "\nstudent not found";
			}
			break;
		}

			//search by birth year
		case 4 :
		{
			cout << "Birth year keyword ? ";
			string keyword;
			cin >> keyword;
			bool found = false;
			for (Student s : student_list)
			{
				if (s.getBY() == keyword)
				{
					cout << "\nName             Student ID       Dept                 Birth Year      Tel" << endl;
					cout << s.getName() << "             ";
					cout << s.getStudentID() << "         ";
					cout << s.getDept() << "          ";
					cout << s.getBY() << "         ";
					cout << s.getTel() << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "\nstudent not found";
			}
			break;
		}

		// search by department name
		case 5:
		{
			cout << "Department name keyword ? ";
			string keyword;
			cin >> keyword;
			bool found = false;
			for (Student s : student_list)
			{
				if (s.getBY() == keyword)
				{
					cout << "\nName             Student ID       Dept                 Birth Year      Tel" << endl;
					cout << s.getName() << "             ";
					cout << s.getStudentID() << "         ";
					cout << s.getDept() << "          ";
					cout << s.getBY() << "         ";
					cout << s.getTel() << endl;
					found = true;
					break;
				}
			}
			if (found == false)
			{
				cout << "\nstudent not found";
			}
			break;
		}
		case 6 :
		{
			cout << "\nListing all the students\n";
			student_list.sort(sims::sort_by_name);
			display_list();
			cout << "\Choose a sorting option\n";
			sorting_option(myfile);
		}
		default : 
		{
			cout << "Invalid input";
		}
		
	}
}

//method to display the list of students
void sims::display_list()
{
	cout << "\nName             Student ID       Dept                 Birth Year              Tel" << endl;
	for (Student s : student_list)
	{
		cout << s.getName() << "           ";
		cout << s.getStudentID() << "             ";
		cout << s.getDept() << "               ";
		cout << s.getBY() << "          ";
		cout << s.getTel() << endl;
	}
}	

//method to sort the student 
void sims::sorting_option(fstream& myfile)
{
	cout << "\n-Sorting Option"
		<< "\n1. Sort by name"
		<< "\n2. Sort by Student ID"
		<< "\n3. Sort by Birth Year"
		<< "\n4. Sort by Department"
		<< "\n>";
	int choice;
	cin >> choice;
	switch (choice)
	{
		
	case 1 : //sort by name
	{
		student_list.sort(sims::sort_by_name);
		display_list();
		break;
	}
	case 2 : //sort by student id
	{
		student_list.sort(sims::sort_by_id);
		display_list();
		break;
	}
	case 3 : //sort by birth year
	{
		student_list.sort(sims::sort_by_by);
		display_list();
		break;
	}
	case 4 : //sort by department name
	{
		student_list.sort(sims::sort_by_deptname);
		display_list();
		break;
	}
		default:
			cout << "Invalid input";
		break;
	}
}

bool sims::sort_by_name(const Student& a, const Student& b)
{
	return a.getName() < b.getName();
}

bool sims::sort_by_id(const Student& a, const Student& b)
{
	return a.getStudentID() < b.getStudentID();
}

bool sims::sort_by_by(const Student& a, const Student& b)
{
	return a.getBY() < b.getBY();
}

bool sims::sort_by_deptname(const Student& a, const Student& b)
{
	return a.getDept() < b.getDept();
}


