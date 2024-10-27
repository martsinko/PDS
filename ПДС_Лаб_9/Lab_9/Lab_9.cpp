#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <Windows.h>

using namespace std;

void readGraph(const string& filename, int& vertexCount, vector<vector<int>>& adjacencyList) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        exit(1);
    }

    int edgeCount;
    inputFile >> vertexCount >> edgeCount;
    adjacencyList.resize(vertexCount);

    for (int i = 0; i < edgeCount; ++i) {
        int vertex1, vertex2;
        inputFile >> vertex1 >> vertex2;
        adjacencyList[vertex1 - 1].push_back(vertex2 - 1);
        adjacencyList[vertex2 - 1].push_back(vertex1 - 1);
    }
    inputFile.close();
}

void printQueue(const queue<int>& q) {
    queue<int> tempQueue = q;
    cout << "[";
    while (!tempQueue.empty()) {
        cout << tempQueue.front() + 1;
        tempQueue.pop();
        if (!tempQueue.empty()) cout << ", ";
    }
    cout << "]";
}

void breadthFirstSearch(int startVertex, const vector<vector<int>>& adjacencyList) {
    vector<bool> visited(adjacencyList.size(), false);
    vector<int> bfsNumber(adjacencyList.size(), -1);
    queue<int> q;
    int iterationCount = 0;

    q.push(startVertex);
    visited[startVertex] = true;
    bfsNumber[startVertex] = ++iterationCount;

    cout << "Ітерація | Поточна Вершина | Номер BFS | Стан Черги\n";
    cout << "--------------------------------------------------\n";

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        cout << "    " << iterationCount << "      |       "
            << currentVertex + 1 << "         |      "
            << bfsNumber[currentVertex] << "     | ";
        printQueue(q);
        cout << endl;

        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                bfsNumber[neighbor] = ++iterationCount;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    string inputFileName = "D:\\Лаби ДПС\\ПДС_Лаб_6\\graph.txt";
    int vertexCount;
    vector<vector<int>> adjacencyList;

    readGraph(inputFileName, vertexCount, adjacencyList);

    int startVertex;
    cout << "Введіть початкову вершину (1 до " << vertexCount << "): ";
    cin >> startVertex;
    startVertex--;

    breadthFirstSearch(startVertex, adjacencyList);

    return 0;
}
