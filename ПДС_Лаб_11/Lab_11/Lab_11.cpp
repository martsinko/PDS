#include <iostream>
#include <Windows.h>
#include <vector>
#include <climits>
#include <fstream>
#include <sstream>

#define INF INT_MAX

void readGraphFromFile(const std::string& filename, std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& next, int& n) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return;
    }

    file >> n;
    int m;  
    file >> m;

    dist.assign(n, std::vector<int>(n, INF));
    next.assign(n, std::vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    int v, u, w;
    for (int i = 0; i < m; ++i) {
        file >> v >> u >> w;
        dist[v - 1][u - 1] = w;  
        next[v - 1][u - 1] = u - 1;  
    }

    file.close();
}

void floydWarshall(std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& next, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath(int u, int v, const std::vector<std::vector<int>>& next) {
    if (next[u][v] == -1) {
        std::cout << "Немає шляху між цими вершинами!" << std::endl;
        return;
    }

    std::cout << "Шлях: ";
    int current = u;
    while (current != v) {
        std::cout << current + 1 << " -> ";  
        current = next[current][v];
    }
    std::cout << v + 1 << std::endl;  
}

void saveToFile(const std::vector<std::vector<int>>& dist, const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Не вдалося відкрити файл для запису!" << std::endl;
        return;
    }

    for (const auto& row : dist) {
        for (int val : row) {
            if (val == INF)
                file << "INF ";
            else
                file << val << " ";
        }
        file << std::endl;
    }
    file.close();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;  
    std::vector<std::vector<int>> dist, next;

    std::string inputFile = "D:\\Лаби ДПС\\ПДС_Лаб_10\\wag_graph.txt";
    readGraphFromFile(inputFile, dist, next, n);

    floydWarshall(dist, next, n);

    std::cout << "Матриця відстаней між всіма парами вершин:" << std::endl;
    for (const auto& row : dist) {
        for (int val : row) {
            if (val == INF)
                std::cout << "INF ";
            else
                std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    int start, end;
    std::cout << "Введіть початкову вершину (від 1 до " << n << "): ";
    std::cin >> start;
    std::cout << "Введіть кінцеву вершину (від 1 до " << n << "): ";
    std::cin >> end;

    printPath(start - 1, end - 1, next); 

    std::string outputFile = "D:\\Лаби ДПС\\ПДС_Лаб_11\\output_distances.txt";
    saveToFile(dist, outputFile);
    std::cout << "Матриця відстаней збережена у файл " << outputFile << std::endl;

    return 0;
}
