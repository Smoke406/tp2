#pragma once
#include <string>
#include <vector>

class FileProcessor {
public:
    // ����������� � ����������
    FileProcessor();
    ~FileProcessor();

    // ����� ��� ������ �����
    std::vector<std::string> readFile(const std::string& filename);

    // ����� ��� ���������� ����� � ����������� �������
    std::vector<std::string> filterLinesWithTwoDigitNumbers(const std::vector<std::string>& lines);

    // ����� ��� ������ ��������������� ����� � ����
    void writeToFile(const std::string& filename, const std::vector<std::string>& lines);
};

