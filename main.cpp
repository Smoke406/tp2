#include <iostream>
#include "student.h"
#include "keeper.h"
#include "fileprocessor.h"
#include <vector>
#include <string>
#include <conio.h>
using namespace std;
void menu()
{
    cout << "����:\n";
    cout << "1. ������� ���� ���������\n";
    cout << "2. �������� �������� � ������\n";
    cout << "3. �������� �������� � �����\n";
    cout << "4. ������������� ��������\n";
    cout << "5. ������� ��������\n";
    cout << "6. ����� ��������� � ������� 2\n";
    cout << "7. ���������� ��������� �� �������� �����\n";
    cout << "0. �����\n";
}
void menuStudentManager() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
   // vector<Student*> students;
    Keeper keeper;
    //int studentCount = 0;
    menu();
    int p = 1;
    while (p==1) {
        //system("cls");
       // menu();

        char choice;
        switch (choice = _getch()) {
        case '1': {
            system("cls");
            menu();
            cout << "\n�� ������� �������� 1\n" << endl;
            keeper.print_keeper();
            break;
        }
        case '2': {
            system("cls");
            menu();
            cout << "\n�� ������� �������� 2\n" << endl;
            ++keeper;
            break;
        }
        case '3': {
            system("cls");
            menu();
            cout << "\n�� ������� �������� 3\n" << endl;
            keeper++;
            break;
        }
        case '4': {
            system("cls");
            menu();
            cout << "\n�� ������� �������� 4\n" << endl;
            cout << "������� ����� ��������: ";
            int n;
            cin >> n;
            //n = check();
            keeper.edit_element(n);
            break;
        }
        case '5': {
            system("cls");
            menu();
            cout << "\n�� ������� �������� 5\n" << endl;
            cout << "������� ����� ��������: ";
            int n;
            cin >> n;
            //n = check();
            keeper.delete_element(n);
            break;
        }
        case '6': {
            system("cls");
            menu();
            cout << "\n�� ������� �������� 6\n" << endl;
            keeper.find_students_with_grade_2();
            break;
        }
        case '7': {
            system("cls");
            menu();
            cout << "\n�� ������� �������� 6\n" << endl;
            keeper.sort_by_average_grade();
            break;
        }
        case '0':
            p = 0;
            break;
        default:
            cout << "�������� �����. ���������� �����.\n";
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