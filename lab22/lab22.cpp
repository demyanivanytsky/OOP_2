#include "Group.h"
#include <iostream>

int main() {
    Group group(10);

    group.AddStudent("Hadzitska", 1);
    group.AddStudent("Krechkivska", 2);
    group.AddStudent("Tymkiv", 3);
    group.AddStudent("Koliada", 4);
    group.AddStudent("Sadura", 5);
    group.AddStudent("Bursin", 6);
    group.AddStudent("Sancaktutan", 7);
    group.AddStudent("Baysel", 8);
    group.AddStudent("Sezen", 9);
    group.AddStudent("Sarikaya", 10);

    for (int i = 0; i < 10; i++) {
        int grade;
        std::cout << "Enter grades for student " << i + 1 << " (separate grades by spaces): ";
        for (int j = 0; j < 2; j++) {
            std::cin >> grade;
            group.AddGradeToStudent(i, grade);
        }
    }

    std::cout << "Top 5 students with the highest average grade:" << std::endl;
    group.FindTop5Students();

    return 0;
}
