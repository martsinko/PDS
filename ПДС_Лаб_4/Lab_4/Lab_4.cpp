#include <iostream>
#include <vector>
#include <algorithm>
#include<Windows.h>

using namespace std;

void printPermutation(const vector<int>& perm) {
    for (int i = 0; i < perm.size(); i++) {
        cout << perm[i] << " ";
    }
    cout << endl;
}

bool nextPermutation(vector<int>& perm) {
    int n = perm.size();

    int i = n - 2;
    while (i >= 0 && perm[i] >= perm[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false;
    }

    int j = n - 1;
    while (perm[j] <= perm[i]) {
        j--;
    }

    swap(perm[i], perm[j]);

    reverse(perm.begin() + i + 1, perm.end());

    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть натуральне число n: ";
    cin >> n;

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    printPermutation(perm);

    while (nextPermutation(perm)) {
        printPermutation(perm);
    }

    return 0;
}
