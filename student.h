#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
struct Subject {
    std::string name; // �������� ��������
    int grade;        // ������
};

class Student {
private:
    std::string surname_and_initials; // ������� � ��������
    int group_number;                 // ����� ������
    Subject* grades;                  
    int grade_count;                  // ���������� ���������

public:
    Student();
    Student(std::string surname, int group, int gradeCount);
    Student(const Student& other);
    ~Student();

    void setSurnameAndInitials(const std::string&);
    std::string getSurnameAndInitials() const;

    void setGroupNumber(int);
    int getGroupNumber() const;

    void setGrade(const std::string& subjectName, int grade, int index);
    Subject getGrade(int index) const;

    double getAverageGrade() const;
    bool hasGradeTwo() const;

    void print() const;
    void edit();
};
