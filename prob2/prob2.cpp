// prob2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <list>
#include "Student.h"
#include "sims.h"
#include <fstream>
#include <iostream>

using namespace std;
int main() {

    //initializing the file
    fstream myfile("file1.txt", ios::in | ios::out | ios::app);
    if (!myfile.is_open())
    {
        cout << "Error in opening the file" << endl;
        return 1;
    }

    sims s;  

    //if the file already exists and is populated, this method will add the students in the file in the list of students in the SIMS
    s.add_student_from_file(myfile); 

    cout << "Welcome to the Student Information Management System \n";
    int choice;
    do {
            cout<< "1. Insertion \n"
            << "2. Search \n"
            << "3. Sorting Option \n"
            << "4. Exit \n"
            << "\n>";
        cin >> choice;

        switch (choice) {
        case 1: {//insertion
            cout << "\n";
            s.insert_student(myfile);  
            break;
        }
        case 2: {//search
            cout << "\n";
            s.search_student(myfile);  
            break;
        }
        case 3: {//sorting option
            cout << "\n";
            s.sorting_option(myfile);
            break;
        }
        case 4: {
            cout << "Exiting the program." << endl;  
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;  
            break;
        }
        }
        cout << "\n";
    } while (choice != 4);

    myfile.close(); 
    return 0; 
}


