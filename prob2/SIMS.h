#pragma once
#include <string>
#include <fstream>
#include <list>
#include "Student.h"


class sims
{
	std::list<Student> student_list;
	public:
		sims(); //constructor
		void insert_student(fstream& myfile); //method to insert a student (details in sims.cpp)
		void search_student(fstream& myfile); //method to search for a student
		void add_student_from_file(fstream& myfile); //to add the students from the files in the list
		static bool sort_by_name(const Student& a, const Student& b);
		static bool sort_by_id(const Student& a, const Student& b);
		static bool sort_by_by(const Student& a, const Student& b); //by stands for birth year
		static bool sort_by_deptname(const Student& a, const Student& b);
		void sorting_option(fstream& myfile); //method to sort
		void display_list(); //method to display the list of students
		
};

