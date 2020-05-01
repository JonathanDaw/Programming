#include <string>

using namespace std;

class studentType {
public:
    void print() const;
    void setFirstName(string first);
    void setLastName(string last);
    void setGrade();
    void setTestScore(int test);
    void setProgScore(int programming);
    void setGPA(double average);

    string getFirstName() const;
    string getLastName() const;
    char getGrade() const;
    int getTestScore() const;
    int getProgScore() const;
    double getGPA() const;

    studentType(string, string, char, int, int, double);
    studentType();

private:
    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programmingScore;
    double GPA;
};

