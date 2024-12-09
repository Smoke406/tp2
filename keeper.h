#pragma once
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

struct Element {
    Element* next;
    Student* data;
};

class Keeper {
private:
    Element* head;
    Element* tail;
    int count;

public:
    Keeper();
    Keeper(Element* h, Element* t, int c);
    Keeper(const Keeper& other);
    ~Keeper();

    Element* get_head();
    Element* get_tail();
    int get_count();

    void delete_all();
    Keeper& delete_element(int n);
    Keeper& edit_element(int n);

    void add_to_head(Student* item);
    void add_to_tail(Student* item);

    Keeper& operator++(); // Adds an element at the beginning
    friend Keeper& operator++(Keeper& K, int); // Adds an element at the end

    Keeper& operator--(int); // Deletes the last element
    friend Keeper& operator--(Keeper& K); // Deletes the first element

    void print_keeper();
    void print_element(int n);

    void find_students_with_grade_2();  // Для поиска студентов с оценкой 2
    void sort_by_average_grade();
};