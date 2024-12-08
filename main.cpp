#include <iostream>
#include "student.h"
#include <algorithm>
#include "fileprocessor.h"
#include <vector>
#include <string>
#include <conio.h>

void menuStudentManager() {
   
    std::vector<STUDENT> students;
    system("cls");
    int choice;
    while (true) {
        std::cout << "\nМеню управления студентами:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Редактировать студента\n";
        std::cout << "3. Удалить студента\n";
        std::cout << "4. Показать студентов с оценкой 2\n";
        std::cout << "5. Упорядочить по среднему баллу\n";
        std::cout << "0. Назад в главное меню\n";
        std::cout << "Ваш выбор: ";
        char choice;

        switch (choice = _getch()) {
        case '1': {
            system("cls");
            STUDENT newStudent;
            std::cin >> newStudent;
            students.push_back(newStudent);
            break;
        }
        case '2': {
            system("cls");
            int index;
            std::cout << "Введите индекс студента для редактирования: ";
            std::cin >> index;

            if (index < 0 || index >= students.size()) {
                std::cout << "Неверный индекс.\n";
                break;
            }
            std::cin >> students[index];
            break;
        }
        case '3': {
            system("cls");
            int index;
            std::cout << "Введите индекс студента для удаления: ";
            std::cin >> index;

            if (index < 0 || index >= students.size()) {
                std::cout << "Неверный индекс.\n";
                break;
            }
            students.erase(students.begin() + index);
            break;
        }
        case '4': {
            system("cls");
            bool found = false;
            for (const auto& student : students) {
                for (const auto& subject : student.getSubjects()) {
                    if (subject.second == 2) {
                        std::cout << student << "\n";
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                std::cout << "Студентов с оценкой 2 нет.\n";
            }
            break;
        }
        case '5': {
            system("cls");
            std::sort(students.begin(), students.end(), [](const STUDENT& a, const STUDENT& b) {
                return a.getAverageGrade() < b.getAverageGrade();
                });
            std::cout << "Сортировка выполнена.\n";
            break;
        }
        case '0':
            return;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }
}

void menuFileProcessor() {
    FileProcessor processor;
    std::string filename;
    int choice;

    while (true) {
        std::cout << "\nМеню работы с файлами:\n";
        std::cout << "1. Считать файл\n";
        std::cout << "2. Фильтровать строки с двузначными числами\n";
        std::cout << "0. Назад в главное меню\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Введите имя файла: ";
            std::cin >> filename;

            try {
                auto lines = processor.readFile(filename);
                std::cout << "Файл успешно считан.\n";
                for (const auto& line : lines) {
                    std::cout << line << "\n";
                }
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            }
            break;
        }
        case 2: {
            std::cout << "Введите имя файла: ";
            std::cin >> filename;

            try {
                auto lines = processor.readFile(filename);
                auto filteredLines = processor.filterLinesWithTwoDigitNumbers(lines);
                if (filteredLines.empty()) {
                    std::cout << "Нет строк с двузначными числами.\n";
                }
                else {
                    std::cout << "Строки с двузначными числами:\n";
                    for (const auto& line : filteredLines) {
                        std::cout << line << "\n";
                    }
                }
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }
}


int main() {
    int choice;
    setlocale(LC_ALL, "Russian");
    while (true) {
        system("cls");
        std::cout << "\nГлавное меню:\n";
        std::cout << "1. Управление студентами\n";
        std::cout << "2. Работа с текстовыми файлами\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        char choice;

        switch (choice = _getch()) {
        case '1':
            menuStudentManager();
            break;
        case '2':
            menuFileProcessor();
            break;
        case '0':
            std::cout << "Выход из программы.\n";
            return 0;
        }
    }
    return 0;
}