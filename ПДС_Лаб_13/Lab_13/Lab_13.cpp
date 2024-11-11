#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
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
        graph[v - 1].push_back(u - 1); 
    }

    file.close();
}

void colorGraph(const vector<vector<int>>& graph, vector<int>& colors) {
    int n = graph.size();

    colors.assign(n, -1);

    for (int u = 0; u < n; ++u) {

        vector<bool> usedColors(n, false);

        for (int v : graph[u]) {
            if (colors[v] != -1) {
                usedColors[colors[v]] = true;
            }
        }

        for (int color = 0; color < n; ++color) {
            if (!usedColors[color]) {
                colors[u] = color;
                break;
            }
        }
    }
}

void printColors(const vector<int>& colors) {
    for (int i = 0; i < colors.size(); ++i) {
        cout << "Вершина " << i + 1 << " має колір: " << colors[i] + 1 << endl;
    }
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n, m;  
    vector<vector<int>> graph;

    string inputFile = "test_graph.txt"; 
    readGraphFromFile(inputFile, graph, n, m);

    vector<int> colors;

    colorGraph(graph, colors);

    cout << "Розфарбування графу:" << endl;
    printColors(colors);

    return 0;
}
