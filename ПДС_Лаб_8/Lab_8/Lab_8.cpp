#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
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

void printStack(const stack<int>& verticesStack) {
    stack<int> tempStack = verticesStack;
    cout << "[";
    while (!tempStack.empty()) {
        cout << tempStack.top() + 1; 
        tempStack.pop();
        if (!tempStack.empty()) cout << ", ";
    }
    cout << "]";
}

void depthFirstSearch(int startVertex, const vector<vector<int>>& adjacencyList) {
    vector<bool> visited(adjacencyList.size(), false);
    vector<int> dfsNumber(adjacencyList.size(), -1); 
    stack<int> s;
    int iterationCount = 0;

    s.push(startVertex);
    visited[startVertex] = true;
    dfsNumber[startVertex] = ++iterationCount;

    cout << "Ітерація Поточна Вершина Номер DFS Стан Стеку\n";

    while (!s.empty()) {
        int currentVertex = s.top();

        cout << "    " << iterationCount << "      |       "
            << currentVertex + 1 << "         |      "
            << dfsNumber[currentVertex] << "     | ";
        printStack(s);
        cout << endl;

        bool hasUnvisitedNeighbor = false;
        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfsNumber[neighbor] = ++iterationCount;
                s.push(neighbor);
                hasUnvisitedNeighbor = true;
                break; 
            }
        }

        if (!hasUnvisitedNeighbor) {
            s.pop();
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

    depthFirstSearch(startVertex, adjacencyList);

    return 0;
}
