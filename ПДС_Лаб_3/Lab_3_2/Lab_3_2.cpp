#include <iostream>
#include <vector>
#include<Windows.h>
using namespace std;

pair<vector<vector<int>>, vector<int>> calculateStirlingAndBell(int i) {
    int n = i + 5;
    vector<vector<int>> F(n + 1, vector<int>(n + 1, 0)); 
    vector<int> B(n + 1, 0); 

    // Заповнюємо перший стовпчик та головну діагональ
    for (int j = 1; j <= n; j++) {
        F[j][1] = 1;
        F[j][j] = 1;
    }

    // Обчислюємо інші значення чисел Стірлінга
    for (int j = 2; j <= n; j++) {
        for (int k = 2; k <= j; k++) {
            F[j][k] = F[j - 1][k - 1] + k * F[j - 1][k];
        }
    }

    // Обчислюємо числа Белла
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= j; k++) {
            B[j] += F[j][k];
        }
    }

    // Повертаємо обчислені числа Стірлінга та Белла
    return make_pair(F, B);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i;
    cout << "Введіть номер варіанту i: ";
    cin >> i;

    // Отримуємо обчислені числа Стірлінга та Белла
    pair<vector<vector<int>>, vector<int>> result = calculateStirlingAndBell(i);
    vector<vector<int>> F = result.first;  // Числа Стірлінга
    vector<int> B = result.second;  // Числа Белла

    int n = i + 5;  // Значення n для таблиці

    // Виводимо заголовок таблиці
    cout << "n\t";
    for (int k = 1; k <= n; k++) {
        cout << k << "\t";
    }
    cout << "B\n";  // Числа Белла

    // Виводимо таблицю чисел Стірлінга та чисел Белла
    for (int j = 1; j <= n; j++) {
        cout << j << "\t";  // Номер рядка
        for (int k = 1; k <= j; k++) {
            cout << F[j][k] << "\t";  // Числа Стірлінга
        }
        cout << B[j] << "\n";  // Числа Белла
    }

    return 0;
}
