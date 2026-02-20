#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    setlocale(LC_ALL, "Russian");
    cout << "1 - Троичная в десятичную\n";
    cout << "2 - Десятичная в троичную\n";
    cout << "Выбор: ";
    cin >> choice;

    switch (choice) {
        // ---------- Троичная → Десятичная ----------
    case 1: {
        string s;
        cout << "Введите троичное число: ";
        cin >> s;

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            int digit = s[i] - '0';
            result = result * 3 + digit;
        }

        cout << "Десятичное число: " << result << endl;
        break;
    }
         // ---------- Десятичная → Троичная ----------
    case 2: {
        int n;
        cout << "Введите десятичное число: ";
        cin >> n;

        if (n == 0) {
            cout << "Троичное число: 0\n";
        }
        else {
            string result = "";

            while (n > 0) {
                int ost = n % 3;
                result = char(ost + '0') + result;
                n = n / 3;
            }

            cout << "Троичное число: " << result << endl;
        }
        break;
    }

    default:
        cout << "Неверный выбор\n";
    }

    return 0;
}
