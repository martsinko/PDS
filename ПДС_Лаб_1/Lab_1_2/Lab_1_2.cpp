#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;

void bitOperations(const string& s1, const string& s2, int n, string& andResult, string& orResult, string& xorResult) {
    for (int i = 0; i < n; i++) {
        char bit1 = s1[i];
        char bit2 = s2[i];

        andResult += (bit1 == '1' && bit2 == '1') ? '1' : '0';
        orResult += (bit1 == '1' || bit2 == '1') ? '1' : '0';
        xorResult += (bit1 != bit2) ? '1' : '0';
    }

    // Виведення результатів
    cout << "AND: " << andResult << endl;
    cout << "OR:  " << orResult << endl;
    cout << "XOR: " << xorResult << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    string s1, s2;
    string andResult, orResult, xorResult;

    cout << "Введіть довжину бітових рядків: ";
    cin >> n;

    cout << "Введіть перший бітовий рядок: ";
    cin >> s1;

    cout << "Введіть другий бітовий рядок: ";
    cin >> s2;

    // Перевірка на правильність введення рядків
    if (s1.length() == n && s2.length() == n && s1.find_first_not_of("01") == string::npos && s2.find_first_not_of("01") == string::npos) {
        bitOperations(s1, s2, n, andResult, orResult, xorResult);
    }
    else {
        cout << "Помилка: обидва рядки повинні бути довжиною " << n << " і містити лише символи '0' або '1'." << endl;
    }
    return 0;
}
