#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <Windows.h>

const int n = 8; 

void printSet(const std::string& name, const std::bitset<n>& set) {
    std::cout << name << ": {";
    for (int i = 0; i < n; i++) {
        if (set[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << "}" << std::endl;
}

void performSetOperations(const std::bitset<n>& A, const std::bitset<n>& B,
    std::bitset<n>& notA, std::bitset<n>& intersection,
    std::bitset<n>& unionAB, std::bitset<n>& difference,
    std::bitset<n>& xorAB) {
    notA = ~A;
    intersection = A & B;
    unionAB = A | B;
    difference = A & ~B;
    xorAB = A ^ B;

    printSet("A", A);
    printSet("not A", notA);
    printSet("A intersection B", intersection);
    printSet("A union B", unionAB);
    printSet("A \\ B", difference);
    printSet("A xor B", xorAB);
}

int main() {
    SetConsoleOutputCP(1251);

    std::vector<int> U(n);
    std::cout << "Введіть значення елементів універсуму U (0-" << n - 1 << "): ";
    for (int i = 0; i < n; i++) {
        std::cin >> U[i];
    }

    int ka;
    std::cout << "Введіть кількість елементів множини A: ";
    std::cin >> ka;
    std::bitset<n> A; 
    std::cout << "Введіть елементи множини A: ";
    for (int i = 0; i < ka; i++) {
        int element;
        std::cin >> element;
        A[element] = 1; 
    }

    int kb;
    std::cout << "Введіть кількість елементів множини B: ";
    std::cin >> kb;
    std::bitset<n> B, notA, intersection, unionAB, difference, xorAB;
    std::cout << "Введіть елементи множини B: ";
    for (int i = 0; i < kb; i++) {
        int element;
        std::cin >> element;
        B[element] = 1; 
    }

    performSetOperations(A, B, notA, intersection, unionAB, difference, xorAB);

    return 0;
}
