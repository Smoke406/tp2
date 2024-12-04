#pragma once
#include <iostream>
#include <string>
using namespace std;
class STUDENT {
private:
    string surname;
    int group_number;
    pair<string, int>* subjects;
    int subject_count;

public:
    // Конструкторы
    STUDENT();
    STUDENT(const string& surname, int group_number, int subject_count);
    STUDENT(const STUDENT& other);

    // Деструктор
    ~STUDENT();

    // Методы
    void setSurname(const string& surname);
    string getSurname() const;

    void setGroupNumber(int group_number);
    int getGroupNumber() const;

    void setSubjects(const pair<string, int>* subjects, int count);
    const pair<string, int>* getSubjects() const;

    double calculateAverageGrade() const;

    // Перегрузка операторов
    friend ostream& operator<<(ostream& os, const STUDENT& student);
    friend istream& operator>>(istream& is, STUDENT& student);
};