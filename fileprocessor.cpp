#include "fileprocessor.h"
#include <fstream>
#include <iostream>
#include <regex>

// �����������
FileProcessor::FileProcessor() {
    std::cout << "������ ������ FileProcessor\n";
}

// ����������
FileProcessor::~FileProcessor() {
    std::cout << "��������� ������ FileProcessor\n";
}

// ����� ��� ������ �����
std::vector<std::string> FileProcessor::readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        throw std::runtime_error("������ �������� �����: " + filename);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();
    return lines;
}

// ����� ��� ���������� ����� � ����������� �������
std::vector<std::string> FileProcessor::filterLinesWithTwoDigitNumbers(const std::vector<std::string>& lines) {
    std::vector<std::string> filteredLines;
    std::regex twoDigitNumber("\\b\\d{2}\\b");

    for (const auto& line : lines) {
        if (std::regex_search(line, twoDigitNumber)) {
            filteredLines.push_back(line);
        }
    }

    return filteredLines;
}

// ����� ��� ������ ����� � ����
void FileProcessor::writeToFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        throw std::runtime_error("������ �������� ����� ��� ������: " + filename);
    }

    for (const auto& line : lines) {
        outputFile << line << "\n";
    }

    outputFile.close();
}
