#include "fileprocessor.h"
#include <fstream>
#include <iostream>
#include <regex>

// Конструктор
FileProcessor::FileProcessor() {
    std::cout << "Создан объект FileProcessor\n";
}

// Деструктор
FileProcessor::~FileProcessor() {
    std::cout << "Уничтожен объект FileProcessor\n";
}

// Метод для чтения файла
std::vector<std::string> FileProcessor::readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Ошибка открытия файла: " + filename);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();
    return lines;
}

// Метод для фильтрации строк с двузначными числами
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

// Метод для записи строк в файл
void FileProcessor::writeToFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        throw std::runtime_error("Ошибка открытия файла для записи: " + filename);
    }

    for (const auto& line : lines) {
        outputFile << line << "\n";
    }

    outputFile.close();
}
