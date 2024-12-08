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
        std::cout << "\n���� ���������� ����������:\n";
        std::cout << "1. �������� ��������\n";
        std::cout << "2. ������������� ��������\n";
        std::cout << "3. ������� ��������\n";
        std::cout << "4. �������� ��������� � ������� 2\n";
        std::cout << "5. ����������� �� �������� �����\n";
        std::cout << "0. ����� � ������� ����\n";
        std::cout << "��� �����: ";
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
            std::cout << "������� ������ �������� ��� ��������������: ";
            std::cin >> index;

            if (index < 0 || index >= students.size()) {
                std::cout << "�������� ������.\n";
                break;
            }
            std::cin >> students[index];
            break;
        }
        case '3': {
            system("cls");
            int index;
            std::cout << "������� ������ �������� ��� ��������: ";
            std::cin >> index;

            if (index < 0 || index >= students.size()) {
                std::cout << "�������� ������.\n";
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
                std::cout << "��������� � ������� 2 ���.\n";
            }
            break;
        }
        case '5': {
            system("cls");
            std::sort(students.begin(), students.end(), [](const STUDENT& a, const STUDENT& b) {
                return a.getAverageGrade() < b.getAverageGrade();
                });
            std::cout << "���������� ���������.\n";
            break;
        }
        case '0':
            return;
        default:
            std::cout << "������������ �����. ���������� �����.\n";
        }
    }
}

void menuFileProcessor() {
    FileProcessor processor;
    std::string filename;
    int choice;

    while (true) {
        std::cout << "\n���� ������ � �������:\n";
        std::cout << "1. ������� ����\n";
        std::cout << "2. ����������� ������ � ����������� �������\n";
        std::cout << "0. ����� � ������� ����\n";
        std::cout << "��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "������� ��� �����: ";
            std::cin >> filename;

            try {
                auto lines = processor.readFile(filename);
                std::cout << "���� ������� ������.\n";
                for (const auto& line : lines) {
                    std::cout << line << "\n";
                }
            }
            catch (const std::exception& e) {
                std::cout << "������: " << e.what() << "\n";
            }
            break;
        }
        case 2: {
            std::cout << "������� ��� �����: ";
            std::cin >> filename;

            try {
                auto lines = processor.readFile(filename);
                auto filteredLines = processor.filterLinesWithTwoDigitNumbers(lines);
                if (filteredLines.empty()) {
                    std::cout << "��� ����� � ����������� �������.\n";
                }
                else {
                    std::cout << "������ � ����������� �������:\n";
                    for (const auto& line : filteredLines) {
                        std::cout << line << "\n";
                    }
                }
            }
            catch (const std::exception& e) {
                std::cout << "������: " << e.what() << "\n";
            }
            break;
        }
        case 0:
            return;
        default:
            std::cout << "������������ �����. ���������� �����.\n";
        }
    }
}


int main() {
    int choice;
    setlocale(LC_ALL, "Russian");
    while (true) {
        system("cls");
        std::cout << "\n������� ����:\n";
        std::cout << "1. ���������� ����������\n";
        std::cout << "2. ������ � ���������� �������\n";
        std::cout << "0. �����\n";
        std::cout << "��� �����: ";
        char choice;

        switch (choice = _getch()) {
        case '1':
            menuStudentManager();
            break;
        case '2':
            menuFileProcessor();
            break;
        case '0':
            std::cout << "����� �� ���������.\n";
            return 0;
        }
    }
    return 0;
}