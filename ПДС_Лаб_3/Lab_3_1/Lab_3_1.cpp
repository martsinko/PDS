#include <iostream>
#include <Windows.h>
using namespace std;

int calculateArrangements(int n, int r) {
    int P1 = 1;
    for (int i = 1; i <= n; i++) {
        P1 *= i;
    }

    int P2 = 1;
    for (int i = 1; i <= (n - r); i++) {
        P2 *= i;
    }

    int A = P1 / P2;
    return A;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, r;

    cout << "Введіть значення n: ";
    cin >> n;
    cout << "Введіть значення r: ";
    cin >> r;

    int A = calculateArrangements(n, r);

    cout << "Кількість усіх розміщень без повторень A(" << n << ", " << r << ") = " << A << endl;

    return 0;
}
