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

