#include "check.h"
int check() {
    int value;
    while (true) {
      //  cout << "Введите число: ";
        cin >> value;

        // Проверяем, что ввод является целым числом
        if (cin.fail()) {
            cin.clear(); // Очистить флаг ошибки
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Пропустить некорректный ввод
            cout << "Некорректный ввод. Пожалуйста, введите целое число.\n";
        }
        else {
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Очистить оставшиеся символы
            return value; // Возвращаем корректное значение
        }
    }
}
