#include <iostream>
#include <vector>
#include<Windows.h>

using namespace std;

void printCombination(const vector<int>& combination) {
    for (int i = 0; i < combination.size(); i++) {
        cout << combination[i] << " ";
    }
    cout << endl;
}

bool nextCombination(vector<int>& combination, int n, int r) {
    int i = r - 1;

    while (i >= 0 && combination[i] == n - r + i + 1) {
        i--;
    }

    if (i < 0) {
        return false;
    }

    combination[i]++;

    for (int j = i + 1; j < r; j++) {
        combination[j] = combination[j - 1] + 1;
    }

    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, r;
    cout << "Введіть натуральне число n: ";
    cin >> n;
    cout << "Введіть невід’ємне ціле число r (r <= n): ";
    cin >> r;

    vector<int> combination(r);
    for (int i = 0; i < r; i++) {
        combination[i] = i + 1;
    }

    printCombination(combination);

    while (nextCombination(combination, n, r)) {
        printCombination(combination);
    }

    return 0;
}
