#include "check.h"
int check() {
    int value;
    while (true) {
      //  cout << "������� �����: ";
        cin >> value;

        // ���������, ��� ���� �������� ����� ������
        if (cin.fail()) {
            cin.clear(); // �������� ���� ������
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // ���������� ������������ ����
            cout << "������������ ����. ����������, ������� ����� �����.\n";
        }
        else {
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // �������� ���������� �������
            return value; // ���������� ���������� ��������
        }
    }
}
