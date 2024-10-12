#pragma once
#include <string>
using namespace std;

class Student {
private:
    string name; 
    string student_ID;
    string birth_year;
    string department;
    string tel;

public:
 
    Student(std::string n, std::string id, std::string by, std::string dep, std::string t);

    //getters
    string getName() const {
        return name;
    }
    string getStudentID() const {
        return student_ID;
    }
    string getBY() const {
        return birth_year;
    }
    string getDept() const {
        return department;
    }
    string getTel() const {
        return tel;
    }

    //setters
    void setName(const string& value) {
        name = value;
    }
    void setStudentID(const string& value) {
        student_ID = value;
    }
    void setBY(const string& value) {
        birth_year = value;
    }

    void setDept(const string& value) {
        department = value;
    }
    void setTel(const string& value) {
        tel = value;
    }
};
