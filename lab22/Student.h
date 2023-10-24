#pragma once
#include <string>

class Student {
private:
    std::string lastName;
    int studentID;
    int* grades;
    int numGrades;
    int numStudents;
    Student* students;

public:
    Student();
    Student(const std::string& name, int id);
    ~Student();
    void AddGrade(int grade);
    void EditGrade(int gradeIndex, int studentIndex, int newGrade);
    double CalculateAverageGrade() const;
    const std::string& GetLastName() const;
};
