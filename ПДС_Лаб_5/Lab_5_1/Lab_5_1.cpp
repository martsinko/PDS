#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// Функція для обчислення декартового добутку
vector<string> cartesianProduct(const char A[], const char B[], const char C[]) {
    vector<string> D;

    for (int ic = 0; ic < 2; ic++) {
        for (int ia = 0; ia < 3; ia++) {
            for (int ib = 0; ib < 3; ib++) {
                D.push_back(string(1, C[ic]) + string(1, A[ia]) + string(1, B[ib]));
            }
        }
    }

    return D;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char A[3]; // Множина A = {a, b, c}
    char B[3]; // Множина B = {x, y, z}
    char C[2]; // Множина C = {0, 1}

    cout << "Введіть елементи множини A (a, b, c): ";
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    cout << "Введіть елементи множини B (x, y, z): ";
    for (int i = 0; i < 3; i++) {
        cin >> B[i];
    }

    cout << "Введіть елементи множини C (0, 1): ";
    for (int i = 0; i < 2; i++) {
        cin >> C[i];
    }

    // Виклик функції для обчислення декартового добутку
    vector<string> D = cartesianProduct(A, B, C);

    cout << "Елементи масиву D (C x A x B):" << endl;
    for (const string& s : D) {
        cout << s << endl;
    }

    return 0;
}
