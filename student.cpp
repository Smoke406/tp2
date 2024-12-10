#include "student.h"
#include <stdexcept>
#include <iostream>
#include <windows.h>

// Конструкторы
Student::Student() : surname_and_initials(" "), group_number(0), grades(nullptr), grade_count(0) {
    std::cout << "Конструктор по умолчанию для Student\n";
}

Student::Student(std::string surname, int group, int gradeCount)
    : surname_and_initials(surname), group_number(group), grade_count(gradeCount) {
    if (grade_count < 0) throw std::invalid_argument("оценка не может быть отрицательна");
    grades = new Subject[grade_count];
    std::cout << "Конструктор с параметром для Student\n";
}

Student::Student(const Student& other)
    : surname_and_initials(other.surname_and_initials), group_number(other.group_number), grade_count(other.grade_count) {
    grades = new Subject[grade_count];
    for (int i = 0; i < grade_count; i++) {
        grades[i] = other.grades[i];
    }
    std::cout << "Конструктор копирования для Student\n";
}

// Деструктор
Student::~Student() {
    delete[] grades;
    std::cout << "Деструктор для Student\n";
}

// Методы set и get
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

// Вычисление среднего балла
double Student::getAverageGrade() const {
    if (grade_count == 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < grade_count; i++) {
        sum += grades[i].grade;
    }
    return sum / grade_count;
}

// Проверка наличия оценки "2"
bool Student::hasGradeTwo() const {
    for (int i = 0; i < grade_count; i++) {
        if (grades[i].grade == 2) return true;
    }
    return false;
}

// Печать информации о студенте
void Student::print() const {
    SetConsoleCP(1251);          // Устанавливаем кодировку ввода
    SetConsoleOutputCP(1251);    // Устанавливаем кодировку вывода

    std::cout << "Студент: " << surname_and_initials << "\n";
    std::cout << "Группа: " << group_number << "\n";
    std::cout << "Оценки:\n";
    for (int i = 0; i < grade_count; i++) {
        std::cout << "  " << grades[i].name << ": " << grades[i].grade << "\n";
    }
    std::cout << std::endl;
}

// Редактирование студента
void Student::edit() {
    system("cls");
    SetConsoleCP(1251);          // Устанавливаем кодировку ввода
    SetConsoleOutputCP(1251);
    char choice;
    std::cout << "Редактирование студента:\n";
    std::cout << "1. Изменить фамилию и инициалы\n";
    std::cout << "2. Изменить номер группы\n";
    std::cout << "3. Изменить оценки\n";
    std::cout << "0. Выйти\n";

    while (true) {
        switch (choice = _getch()) {
        case '1': {
            std::cout << "Введите новую фамилию и инициалы: ";
            std::cin.ignore(); // Для очистки потока после _getch
            std::string newName;
            getline(std::cin, newName);
            setSurnameAndInitials(newName);
            std::cout << "Фамилия и инициалы обновлены.\n";
            break;
        }
        case '2': {
            std::cout << "Введите новый номер группы: ";
            int newGroup;
            std::cin >> newGroup;
            setGroupNumber(newGroup);
            std::cout << "Номер группы обновлен.\n";
            break;
        }
        case '3': {
            std::cout << "Введите количество предметов: ";
            int subjectCount;
            std::cin >> subjectCount;

            for (int i = 0; i < subjectCount; ++i) {
                std::string subjectName;
                int grade;

                std::cout << "Предмет " << i + 1 << ": ";
                std::cin >> subjectName;
                std::cout << "Оценка: ";
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
                        std::cout << "Некоректный ввод. Введите от 1 до 5\nОценка: ";
                    }
                }
               // std::cin >> grade;

               // setGrade(subjectName, grade, i);
            }

            std::cout << "Оценки обновлены.\n";
            break;
        }
        case '0':
            std::cout << "Выход из редактирования.\n";
            return;
        default:
            std::cout << "Неверная команда.\n";
            break;
        }
    }
}



