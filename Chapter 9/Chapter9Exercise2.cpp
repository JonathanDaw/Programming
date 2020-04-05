/*
Write a program that reads students’ names followed by their test scores. The program should output each student’s name followed by the test scores and the relevant grade. It should also find and print the highest test score and the name of the students having the highest test score.

Student data should be stored in a struct variable of type studentType, which has four components: studentFName and studentLName of type string, testScore of type int (testScore is between 0 and 100), and grade of type char. Suppose that the class has 20 students. Use an array of 20 components of type studentType.

Your program must contain at least the following functions:

A function to read the students’ data into the array.

A function to assign the relevant grade to each student.

A function to find the highest test score.

A function to print the names of the students having the highest test score.

Your program must output each student’s name in this form: last name followed by a comma, followed by a space, followed by the first name; the name must be left justified. Moreover, other than declaring the variables and opening the input and output files, the function main should only be a collection of function calls.
*/
#include <iostream>
#include <string>

using namespace std;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};
studentType student[20];
const int listSize = 20;


void inputData(studentType student[]);
void assignGrade(studentType student[]);
int highestGrade(int&, studentType student[]);
void printStudents(int&, studentType student[]);

int main()
{
    int topScore = 0;
    inputData(student);
    assignGrade(student);
    highestGrade(topScore, student);
    printStudents(topScore, student);
    

}
void inputData(studentType student[]) {
    cout << "Please enter the students' first names, last names, and finally test scores one line at a time: ";
    for (int i = 0; i < listSize; i++) {
        cin >> student[i].studentFName >> student[i].studentLName >> student[i].testScore;
        cout << endl;
    }
    
}
void assignGrade(studentType student[]) {
    for (int i = 0; i < listSize; i++) {
        if (student[i].testScore > 89) {
            student [i].grade = 'A';
        }
        else if (student[i].testScore > 79) {
            student[i].grade = 'B';
        }
        else if (student[i].testScore > 69) {
            student[i].grade = 'C';
        }
        else if (student[i].testScore > 59) {
            student[i].grade = 'D';
        }
        else {
            student[i].grade = 'F';
        }
    }
}
int highestGrade(int& topScore, studentType student[]) {
    for (int i = 0; i < listSize; i++) {
        if (student[i].grade > topScore) {
            topScore = student[i].grade;
        }
    }
    return topScore;
}
void printStudents(int& topScore, studentType student[]) {

    for (int i = 0; i < listSize; i++) {
        cout << student[i].studentFName << " " << student[i].studentLName << "  " << student[i].testScore << "  " << student[i].grade << endl;
    }

    cout << "The students with the highest test scores are: ";
    for (int i = 0; i < listSize; i++) {
        if (student[i].grade == topScore) {
            cout << student[i].studentLName << ", " << student[i].studentFName << endl;
        }
    }
}

