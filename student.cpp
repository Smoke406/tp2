#include "student.h"
#include <stdexcept>
#include <iostream>
#include <windows.h>

// ������������
Student::Student() : surname_and_initials(" "), group_number(0), grades(nullptr), grade_count(0) {
    std::cout << "����������� �� ��������� ��� Student\n";
}

Student::Student(std::string surname, int group, int gradeCount)
    : surname_and_initials(surname), group_number(group), grade_count(gradeCount) {
    if (grade_count < 0) throw std::invalid_argument("������ �� ����� ���� ������������");
    grades = new Subject[grade_count];
    std::cout << "����������� � ���������� ��� Student\n";
}

Student::Student(const Student& other)
    : surname_and_initials(other.surname_and_initials), group_number(other.group_number), grade_count(other.grade_count) {
    grades = new Subject[grade_count];
    for (int i = 0; i < grade_count; i++) {
        grades[i] = other.grades[i];
    }
    std::cout << "����������� ����������� ��� Student\n";
}

// ����������
Student::~Student() {
    delete[] grades;
    std::cout << "���������� ��� Student\n";
}

// ������ set � get
void Student::setSurnameAndInitials(const std::string& surname) {
    surname_and_initials = surname;
}

std::string Student::getSurnameAndInitials() const {
    return surname_and_initials;
}

void Student::setGroupNumber(int group) {
    group_number = group;
}

int Student::getGroupNumber() const {
    return group_number;
}

void Student::setGrade(const std::string& subjectName, int grade, int index) {
    if (index < 0 || index >= grade_count) throw std::out_of_range("Index out of range");
    grades[index].name = subjectName;
    grades[index].grade = grade;
}

Subject Student::getGrade(int index) const {
    if (index < 0 || index >= grade_count) throw std::out_of_range("Index out of range");
    return grades[index];
}

// ���������� �������� �����
double Student::getAverageGrade() const {
    if (grade_count == 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < grade_count; i++) {
        sum += grades[i].grade;
    }
    return sum / grade_count;
}

// �������� ������� ������ "2"
bool Student::hasGradeTwo() const {
    for (int i = 0; i < grade_count; i++) {
        if (grades[i].grade == 2) return true;
    }
    return false;
}

// ������ ���������� � ��������
void Student::print() const {
    SetConsoleCP(1251);          // ������������� ��������� �����
    SetConsoleOutputCP(1251);    // ������������� ��������� ������

    std::cout << "�������: " << surname_and_initials << "\n";
    std::cout << "������: " << group_number << "\n";
    std::cout << "������:\n";
    for (int i = 0; i < grade_count; i++) {
        std::cout << "  " << grades[i].name << ": " << grades[i].grade << "\n";
    }
    std::cout << std::endl;
}

// �������������� ��������
void Student::edit() {
    system("cls");
    SetConsoleCP(1251);          // ������������� ��������� �����
    SetConsoleOutputCP(1251);
    char choice;
    std::cout << "�������������� ��������:\n";
    std::cout << "1. �������� ������� � ��������\n";
    std::cout << "2. �������� ����� ������\n";
    std::cout << "3. �������� ������\n";
    std::cout << "0. �����\n";

    while (true) {
        switch (choice = _getch()) {
        case '1': {
            std::cout << "������� ����� ������� � ��������: ";
            std::cin.ignore(); // ��� ������� ������ ����� _getch
            std::string newName;
            getline(std::cin, newName);
            setSurnameAndInitials(newName);
            std::cout << "������� � �������� ���������.\n";
            break;
        }
        case '2': {
            std::cout << "������� ����� ����� ������: ";
            int newGroup;
            std::cin >> newGroup;
            setGroupNumber(newGroup);
            std::cout << "����� ������ ��������.\n";
            break;
        }
        case '3': {
            std::cout << "������� ���������� ���������: ";
            int subjectCount;
            std::cin >> subjectCount;

            for (int i = 0; i < subjectCount; ++i) {
                std::string subjectName;
                int grade;

                std::cout << "������� " << i + 1 << ": ";
                std::cin >> subjectName;
                std::cout << "������: ";
                int p = 1;
                while (p == 1)
                {
                    std::cin >> grade;
                    if ((grade >= 1) && (grade <= 5))
                    {
                        setGrade(subjectName, grade, i);
                        p = 0;
                    }
                    else
                    {
                        std::cout << "����������� ����. ������� �� 1 �� 5\n������: ";
                    }
                }
               // std::cin >> grade;

               // setGrade(subjectName, grade, i);
            }

            std::cout << "������ ���������.\n";
            break;
        }
        case '0':
            std::cout << "����� �� ��������������.\n";
            return;
        default:
            std::cout << "�������� �������.\n";
            break;
        }
    }
}



