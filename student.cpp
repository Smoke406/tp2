#include "student.h"
#include <stdexcept>

// Конструктор по умолчанию
STUDENT::STUDENT() : surname(""), group_number(0), subjects(nullptr), subject_count(0) {
    std::cout << "Default constructor called for STUDENT\n";
}

// Конструктор с параметрами
STUDENT::STUDENT(const std::string& surname, int group_number, int subject_count)
    : surname(surname), group_number(group_number), subject_count(subject_count) {
    subjects = new std::pair<std::string, int>[subject_count];
    std::cout << "Parameterized constructor called for STUDENT\n";
}

// Конструктор копирования
STUDENT::STUDENT(const STUDENT& other)
    : surname(other.surname), group_number(other.group_number), subject_count(other.subject_count) {
    subjects = new std::pair<std::string, int>[subject_count];
    for (int i = 0; i < subject_count; ++i) {
        subjects[i] = other.subjects[i];
    }
    std::cout << "Copy constructor called for STUDENT\n";
}

// Деструктор
STUDENT::~STUDENT() {
    delete[] subjects;
    std::cout << "Destructor called for STUDENT\n";
}

// Методы set и get
void STUDENT::setSurname(const std::string& surname) { this->surname = surname; }
std::string STUDENT::getSurname() const { return surname; }

void STUDENT::setGroupNumber(int group_number) { this->group_number = group_number; }
int STUDENT::getGroupNumber() const { return group_number; }

void STUDENT::setSubjects(const std::pair<std::string, int>* subjects, int count) {
    delete[] this->subjects;
    this->subjects = new std::pair<std::string, int>[count];
    for (int i = 0; i < count; ++i) {
        this->subjects[i] = subjects[i];
    }
    this->subject_count = count;
}
const std::pair<std::string, int>* STUDENT::getSubjects() const { return subjects; }

double STUDENT::calculateAverageGrade() const {
    if (subject_count == 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < subject_count; ++i) {
        sum += subjects[i].second;
    }
    return sum / subject_count;
}

// Перегрузка операторов
std::ostream& operator<<(std::ostream& os, const STUDENT& student) {
    os << "Surname: " << student.surname << ", Group: " << student.group_number << "\n";
    os << "Subjects:\n";
    for (int i = 0; i < student.subject_count; ++i) {
        os << "  " << student.subjects[i].first << ": " << student.subjects[i].second << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, STUDENT& student) {
    std::cout << "Enter surname: ";
    is >> student.surname;
    std::cout << "Enter group number: ";
    is >> student.group_number;

    std::cout << "Enter number of subjects: ";
    is >> student.subject_count;

    delete[] student.subjects;
    student.subjects = new std::pair<std::string, int>[student.subject_count];

    for (int i = 0; i < student.subject_count; ++i) {
        std::cout << "Enter subject name: ";
        is >> student.subjects[i].first;
        std::cout << "Enter grade: ";
        is >> student.subjects[i].second;

        if (student.subjects[i].second < 2 || student.subjects[i].second > 5) {
            throw std::invalid_argument("Grade must be between 2 and 5");
        }
    }
    return is;
}
