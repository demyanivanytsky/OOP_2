#include "Group.h"
#include <iostream>

Group::Group(int size) : students(new Student[size]), numStudents(size) {
    for (int i = 0; i < numStudents; i++) {
        students[i] = Student(); // Виклик конструктора за замовчуванням
    }
}

Group::~Group() {
    delete[] students;
}

void Group::AddStudent(const std::string& name, int id) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].GetLastName().empty()) {
            students[i] = Student(name, id);
            break;
        }
    }
}

void Group::AddGradeToStudent(int studentIndex, int grade) {
    if (studentIndex >= 0 && studentIndex < numStudents) {
        students[studentIndex].AddGrade(grade);
    }
}

void Group::FindTop5Students() const {
    for (int i = 0; i < numStudents; i++) {
        if (!students[i].GetLastName().empty()) {
            students[i].CalculateAverageGrade();
        }
    }

    for (int i = 0; i < 5; i++) {
        double maxAverage = 0.0;
        int topStudentIndex = -1;
        for (int j = 0; j < numStudents; j++) {
            if (!students[j].GetLastName().empty() && students[j].CalculateAverageGrade() > maxAverage) {
                maxAverage = students[j].CalculateAverageGrade();
                topStudentIndex = j;
            }
        }
        if (topStudentIndex != -1) {
            std::cout << students[topStudentIndex].GetLastName() << ": " << students[topStudentIndex].CalculateAverageGrade() << std::endl;
            students[topStudentIndex] = Student();
        }
    }
}
