#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <Windows.h>

using namespace std;

void readGraphFromFile(const string& filename, vector<vector<int>>& graph, int& n, int& m) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    file >> n >> m;
    graph.resize(n);

    int u, v;
    for (int i = 0; i < m; ++i) {
        file >> u >> v;
        graph[u - 1].push_back(v - 1); 
    }

    file.close();
}

bool isReflexive(const vector<vector<int>>& graph, int n) {
    for (int i = 0; i < n; ++i) {
        bool foundSelfLoop = false;
        for (int neighbor : graph[i]) {
            if (neighbor == i) {
                foundSelfLoop = true;
                break;
            }
        }
        if (!foundSelfLoop) {
            return false; 
        }
    }
    return true;  
}

bool isAsymmetric(const vector<vector<int>>& graph, int n) {
    set<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int neighbor : graph[i]) {
            if (edges.find({ neighbor, i }) != edges.end()) {
                return false;  
            }
            edges.insert({ i, neighbor });
        }
    }
    return true; 
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n, m;
    vector<vector<int>> graph;

    string inputFile = "test14.txt";
    readGraphFromFile(inputFile, graph, n, m);

    if (isReflexive(graph, n)) {
        cout << "Граф рефлексивний" << endl;
    }
    else {
        cout << "Граф не є рефлексивним" << endl;
    }

    if (isAsymmetric(graph, n)) {
        cout << "Граф асиметричний" << endl;
    }
    else {
        cout << "Граф не є асиметричним" << endl;
    }

    return 0;
}
