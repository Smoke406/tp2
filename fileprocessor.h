#pragma once
#include <string>
#include <vector>

class FileProcessor {
public:
    // Конструктор и деструктор
    FileProcessor();
    ~FileProcessor();

    // Метод для чтения файла
    std::vector<std::string> readFile(const std::string& filename);

    // Метод для фильтрации строк с двузначными числами
    std::vector<std::string> filterLinesWithTwoDigitNumbers(const std::vector<std::string>& lines);

    // Метод для записи отфильтрованных строк в файл
    void writeToFile(const std::string& filename, const std::vector<std::string>& lines);
};

