#include <iostream>
#include "studentType.h"

using namespace std;

void studentType::print() const {
    cout << "Name: " << getFirstName() << " " << getLastName() << endl;
    cout << "Grade: " << getGrade() << endl;
    cout << "Test score: " << getTestScore() << endl;
    cout << "Programming score: " << getProgScore() << endl;
    cout << "GPA: " << getGPA() << endl;
}
void studentType::setFirstName(string first) {
    firstName = first;
}

void studentType::setLastName(string last) {
    lastName = last;
}
void studentType::setTestScore(int test) {
    testScore = test;
}
void studentType::setProgScore(int programming) {
    programmingScore = programming;
}
void studentType::setGrade() {
    int total = (testScore + programmingScore) / 2;
    if (total > 89) {
        courseGrade = 'A';
    }
    else if (total > 79) {
        courseGrade = 'B';
    }
    else if (total > 69) {
        courseGrade = 'C';
    }
    else if (total > 59) {
        courseGrade = 'D';
    }
    else {
        courseGrade = 'F';
    }
}

void studentType::setGPA(double average) {
    GPA = average;
}



string studentType::getFirstName() const {
    return firstName;
}

string studentType::getLastName() const {
    return lastName;
}

int studentType::getTestScore() const {
    return testScore;
}
int studentType::getProgScore() const {
    return programmingScore;
}
char studentType::getGrade() const {
    return courseGrade;
}
double studentType::getGPA() const {
    return GPA;
}

studentType::studentType(string first, string last, char grade, int test, int programming, double average) {
    firstName = first;
    lastName = last;
    courseGrade = grade;
    testScore = test;
    programmingScore = programming;
    GPA = average;
}
studentType::studentType() {

}