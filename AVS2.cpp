#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");

    string bits;
    cout << "Введите 16 бит IEEE 754 (например 0100001000000000): ";
    cin >> bits;

    if (bits.length() != 16) 
    {
        cout << "Ошибка: нужно ровно 16 бит\n";
        return 0;
    }

    // 1. Знак
    int sign = bits[0] - '0';

    // 2. Экспонента
    int exponent = 0;
    for (int i = 1; i <= 5; i++) {
        exponent = exponent * 2 + (bits[i] - '0');
    }

    // 3. Мантисса
    double mantissa = 0.0;
    double power = 0.5;

    for (int i = 6; i < 16; i++) {
        if (bits[i] == '1')
            mantissa += power;
        power /= 2;
    }

    double result;

    if (exponent == 0 && mantissa == 0) {
        result = 0; // ноль
    }
    else {
        // добавляем скрытую 1
        mantissa = 1 + mantissa;

        int realExponent = exponent - 15;

        result = mantissa * pow(2, realExponent);

        if (sign == 1)
            result = -result;
    }

    cout << "Десятичное число: " << result << endl;

    return 0;
}