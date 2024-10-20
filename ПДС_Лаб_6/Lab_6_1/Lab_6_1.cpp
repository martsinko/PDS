#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <Windows.h>

struct Graph {
    int n; // Кількість вершин
    int m; // Кількість ребер
    std::vector<std::pair<int, int>> edges;
};

Graph readGraphFromFile(const std::string& filename) {
    Graph graph;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл");
    }

    file >> graph.n >> graph.m;
    graph.edges.resize(graph.m);

    for (int i = 0; i < graph.m; ++i) {
        file >> graph.edges[i].first >> graph.edges[i].second;
    }

    file.close();
    return graph;
}

void printAdjacencyMatrix(const Graph& graph) {
    std::vector<std::vector<int>> adjacencyMatrix(graph.n, std::vector<int>(graph.n, 0));

    for (const auto& edge : graph.edges) {
        adjacencyMatrix[edge.first - 1][edge.second - 1] = 1; 
    }

    std::cout << "Матриця суміжності:\n";
    for (const auto& row : adjacencyMatrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void printIncidenceMatrix(const Graph& graph) {
    std::vector<std::vector<int>> incidenceMatrix(graph.n, std::vector<int>(graph.m, 0));

    for (int i = 0; i < graph.m; ++i) {
        incidenceMatrix[graph.edges[i].first - 1][i] = 1;  
        incidenceMatrix[graph.edges[i].second - 1][i] = -1; 
    }

    std::cout << "Матриця інцидентності:\n";
    for (const auto& row : incidenceMatrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void writeMatrixToFile(const std::string& filename, const std::vector<std::vector<int>>& matrix) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл для запису");
    }

    for (const auto& row : matrix) {
        for (int value : row) {
            file << value << " ";
        }
        file << "\n";
    }

    file.close();
}

void writeAdjacencyMatrixToFile(const std::string& filename, const Graph& graph) {
    std::vector<std::vector<int>> adjacencyMatrix(graph.n, std::vector<int>(graph.n, 0));

    for (const auto& edge : graph.edges) {
        adjacencyMatrix[edge.first - 1][edge.second - 1] = 1; 
    }

    writeMatrixToFile(filename, adjacencyMatrix);
}

void writeIncidenceMatrixToFile(const std::string& filename, const Graph& graph) {
    std::vector<std::vector<int>> incidenceMatrix(graph.n, std::vector<int>(graph.m, 0));

    for (int i = 0; i < graph.m; ++i) {
        incidenceMatrix[graph.edges[i].first - 1][i] = 1;  
        incidenceMatrix[graph.edges[i].second - 1][i] = -1;
    }

    writeMatrixToFile(filename, incidenceMatrix);
}

int main() {
    SetConsoleOutputCP(1251);
    try {
        const std::string inputDirname = "D:\\Лаби ДПС\\ПДС_Лаб_6\\";
        const std::string inputFilename = "D:\\Лаби ДПС\\ПДС_Лаб_6\\graph.txt";
        Graph graph = readGraphFromFile(inputFilename);

        printAdjacencyMatrix(graph);
        printIncidenceMatrix(graph);

        std::string outputAdjMatrixFilename, outputIncMatrixFilename;
        std::cout << "Введіть ім'я файлу для запису матриці суміжності: ";
        std::cin >> outputAdjMatrixFilename;
        writeAdjacencyMatrixToFile(inputDirname + outputAdjMatrixFilename, graph);

        std::cout << "Введіть ім'я файлу для запису матриці інцидентності: ";
        std::cin >> outputIncMatrixFilename;
        writeIncidenceMatrixToFile(inputDirname + outputIncMatrixFilename, graph);

        std::cout << "Матриці суміжності та інцидентності виведені на екран та записані у файли." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
