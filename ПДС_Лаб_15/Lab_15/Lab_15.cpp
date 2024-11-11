#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<int>& positions) {

    for (int i = 0; i < row; ++i) {
        if (positions[i] == col || abs(positions[i] - col) == row - i) {
            return false; 
        }
    }
    return true;
}

void printSolution(const vector<int>& positions, int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (positions[i] == j)
                cout << "Q "; 
            else
                cout << ". "; 
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int row, int n, vector<int>& positions, int& solutionCount) {
    if (row == n) {
  
        printSolution(positions, n);
        solutionCount++;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, positions)) {
            positions[row] = col;  
            solveNQueens(row + 1, n, positions, solutionCount); 

        }
    }
}

int main() {
    SetConsoleOutputCP(1251);

    SetConsoleCP(1251);
    int n;
    cout << "Введіть розмір шахівниці n: ";
    cin >> n;

    vector<int> positions(n); 
    int solutionCount = 0;

    solveNQueens(0, n, positions, solutionCount);

    if (solutionCount == 0) {
        cout << "Рішення не знайдено" << endl;
    }
    else {
        cout << "Знайдено " << solutionCount << " розв'язків" << endl;
    }

    return 0;
}
