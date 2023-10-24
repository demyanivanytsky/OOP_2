#pragma once
#include "Student.h"

class Group {
private:
    Student* students;
    int numStudents;

public:
    Group(int size);
    ~Group();
    void AddStudent(const std::string& name, int id);
    void AddGradeToStudent(int studentIndex, int grade);
    void EditGrades(int studentIndex, int gradeIndex, int newGrade);
    double CalculateAverageGrade(int studentIndex) const; // ���������� �������
    void FindTop5Students() const;
};
