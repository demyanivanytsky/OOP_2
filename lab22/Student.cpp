#include "Student.h"

Student::Student() : lastName(""), studentID(0), grades(nullptr), numGrades(0) {}

Student::Student(const std::string& name, int id) : lastName(name), studentID(id), grades(nullptr), numGrades(0) {}

Student::~Student() {
    delete[] grades;
}

void Student::EditGrade(int studentIndex, int gradeIndex, int newGrade) {
    if (studentIndex >= 0 && studentIndex < numStudents) {
        students[studentIndex].EditGrade(gradeIndex, newGrade, studentIndex);
    }
}

void Student::AddGrade(int grade) {
    int* newGrades = new int[numGrades + 1];//створюємо масив оцінок студента одного 
    for (int i = 0; i < numGrades; i++) {//добавляємо оцінки 
        newGrades[i] = grades[i];
    }
    newGrades[numGrades] = grade;
    numGrades++;
    delete[] grades;
    grades = newGrades;
}

double Student::CalculateAverageGrade() const {//сер арифм
    if (numGrades == 0) {
        return 0.0;
    }
    int sum = 0;
    for (int i = 0; i < numGrades; i++) {
        sum += grades[i];
    }
    return static_cast<double>(sum) / numGrades;
}

const std::string& Student::GetLastName() const {
    return lastName;
}
