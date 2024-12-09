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
    cout << "Меню:\n";
    cout << "1. Вывести всех студентов\n";
    cout << "2. Добавить студента в начало\n";
    cout << "3. Добавить студента в конец\n";
    cout << "4. Редактировать студента\n";
    cout << "5. Удалить студента\n";
    cout << "6. Найти студентов с оценкой 2\n";
    cout << "7. Сортировка студентов по среднему баллу\n";
    cout << "0. Назад\n";
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
            cout << "\nВы выбрали операцию 1\n" << endl;
            keeper.print_keeper();
            break;
        }
        case '2': {
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 2\n" << endl;
            ++keeper;
            break;
        }
        case '3': {
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 3\n" << endl;
            keeper++;
            break;
        }
        case '4': {
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 4\n" << endl;
            cout << "Введите номер элемента: ";
            int n;
            cin >> n;
            //n = check();
            keeper.edit_element(n);
            break;
        }
        case '5': {
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 5\n" << endl;
            cout << "Введите номер элемента: ";
            int n;
            cin >> n;
            //n = check();
            keeper.delete_element(n);
            break;
        }
        case '6': {
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 6\n" << endl;
            keeper.find_students_with_grade_2();
            break;
        }
        case '7': {
            system("cls");
            menu();
            cout << "\nВы выбрали операцию 6\n" << endl;
            keeper.sort_by_average_grade();
            break;
        }
        case '0':
            p = 0;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
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