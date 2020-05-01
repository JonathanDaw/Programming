#include <iostream>
#include <string>
#include "studentType.h"

using namespace std;

int main()
{
    studentType student;
    studentType newStudent("Brain", "Johnson", '*', 85, 95, 3.89);

    student.setFirstName("");
    student.setLastName("");
    student.setTestScore(100);
    student.setProgScore(80);
    student.setGrade();
    student.setGPA(92.65);
    student.print();
    cout << "***************" << endl << endl;

    newStudent.print();
    cout << "***************" << endl << endl;

    return 0;
}
