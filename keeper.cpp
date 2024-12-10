#include "keeper.h"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {}
Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {}
Keeper::Keeper(const Keeper& other) : head(other.head), tail(other.tail), count(other.count) {}
Keeper::~Keeper() { delete_all(); }

Element* Keeper::get_head() { return head; }
Element* Keeper::get_tail() { return tail; }
int Keeper::get_count() { return count; }

void Keeper::delete_all() {
    while (head != nullptr) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
    }
    tail = nullptr;
}

Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        cout << "�������� � ����� �������� �� ����������." << endl;
        return *this;
    }
    if (n == 1) {
        --(*this);
        return *this;
    }
    Element* temp = head;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }
    Element* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail) {
        tail = temp;
    }
    delete toDelete->data;
    delete toDelete;
    count--;
    return *this;
}

Keeper& Keeper::edit_element(int n) {

    if (n < 1 || n > count) {
        cout << "�������� � ����� �������� �� ����������." << endl;
        return *this;
    }
    Element* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp = tmp->next;
    }
    if (tmp->data) {
        tmp->data->edit();
    }
    else {
        cout << "������ � ������� �������� ���." << endl;
    }
    return *this;
}

void Keeper::add_to_head(Student* item) {
    Element* new_el = new Element;
    new_el->data = item;
    new_el->next = head;
    if (head == nullptr) {
        tail = new_el;
    }
    head = new_el;
    count++;
}

void Keeper::add_to_tail(Student* item) {
    Element* new_el = new Element;
    new_el->data = item;
    new_el->next = nullptr;
    if (head == nullptr) {
        head = tail = new_el;
    }
    else {
        tail->next = new_el;
        tail = new_el;
    }
    count++;
}

Keeper& Keeper::operator++() {
    cout << "���������� �������� � ������ ������.\n";
    string name;
    int group, gradesCount;
    cout << "������� ������� � ��������: ";
    cin.ignore();
    getline(cin, name);
    cout << "������� ����� ������: ";
    cin >> group;
    cout << "������� ���������� ���������: ";
    cin >> gradesCount;

    Student* student = new Student(name, group, gradesCount);
    for (int i = 0; i < gradesCount; ++i) {
        string subject;
        int grade;
        cout << "������� " << i + 1 << ": ";
        cin >> subject;
        cout << "������: ";
        int p=1;
        while (p==1)
        {
            cin >> grade;
            if ((grade >= 1) && (grade <= 5))
            {
                student->setGrade(subject, grade, i);
                p = 0;
            }
            else
            {
                cout << "����������� ����. ������� �� 1 �� 5\n������: ";
            }
        }
    }
    add_to_head(student);
    
    return *this;
}

Keeper& operator++(Keeper& K, int) {
    cout << "���������� �������� � ����� ������.\n";
    string name;
    int group, gradesCount;
    cout << "������� ������� � ��������: ";
    cin.ignore();
    getline(cin, name);
    cout << "������� ����� ������: ";
    cin >> group;
    cout << "������� ���������� ���������: ";
    cin >> gradesCount;

    Student* student = new Student(name, group, gradesCount);
    for (int i = 0; i < gradesCount; ++i) {
        string subject;
        int grade;
        cout << "������� " << i + 1 << ": ";
        cin >> subject;
        cout << "������: ";
        int p = 1;
        while (p == 1)
        {
            cin >> grade;
            if ((grade >= 1) && (grade <= 5))
            {
                student->setGrade(subject, grade, i);
                p = 0;
            }
            else
            {
                cout << "����������� ����. ������� �� 1 �� 5\n������: ";
            }
        }
        //grade = number();
        // cin >> grade;
        //student->setGrade(subject, grade, i);
    }
    K.add_to_tail(student);
    
    return K;
}

Keeper& Keeper::operator--(int) {
    if (count == 0) {
        cout << "��������� ����." << endl;
        return *this;
    }
    Element* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail->data;
    delete tail;
    tail = temp;
    tail->next = nullptr;
    count--;
    
    return *this;

}

Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "��������� ����." << endl;
        return K;
    }
    Element* temp = K.head;
    K.head = K.head->next;
    delete temp->data;
    delete temp;
    K.count--;
    
    return K;
}

void Keeper::print_keeper() {
    Element* temp = head;
    if (count == 0) {
        cout << "��������� ����." << endl;
        return;
    }
    int i = 1;
    while (temp != nullptr) {
        cout << "������� #" << i++ << ":\n";
        temp->data->print();
        temp = temp->next;
    }
}

void Keeper::print_element(int n) {
    if (n < 1 || n > count) {
        cout << "�������� � ����� �������� �� ����������." << endl;
        return;
    }
    Element* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp = tmp->next;
    }
    tmp->data->print();
}

void Keeper::find_students_with_grade_2() {
    Element* temp = head;
    bool found = false;

    while (temp != nullptr) {
        Student* student = dynamic_cast<Student*>(temp->data);
        if (student && student->hasGradeTwo()) {
            student->print();
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        std::cout << "��������� � ������� '2' �� �������." << std::endl;
    }
}

void Keeper::sort_by_average_grade() {
    if (count < 2) return;

    // ����������� ���������� ������ ���������� ������
    bool swapped;
    do {
        swapped = false;
        Element* current = head;
        while (current != nullptr && current->next != nullptr) {
            Student* student1 = dynamic_cast<Student*>(current->data);
            Student* student2 = dynamic_cast<Student*>(current->next->data);
            if (student1 && student2 && student1->getAverageGrade() < student2->getAverageGrade()) {
                // ������ ������� ������ � �����
                Student* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    // ������ ���������������� ������
    Element* temp = head;
    while (temp != nullptr) {
        Student* student = dynamic_cast<Student*>(temp->data);
        if (student) {
            student->print();
        }
        temp = temp->next;
    }
}