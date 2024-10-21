#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <stdexcept>
#include <Windows.h>

struct Graph {
    int n; // Кількість вершин
    int m; // Кількість ребер
    std::vector<std::pair<int, int>> edges; // Ребра графа
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

void calculateDegrees(const Graph& graph, std::vector<int>& inDegrees, std::vector<int>& outDegrees) {
    inDegrees.resize(graph.n, 0);
    outDegrees.resize(graph.n, 0);

    for (const auto& edge : graph.edges) {
        outDegrees[edge.first - 1]++;
        inDegrees[edge.second - 1]++;
    }
}

bool isUniform(const std::vector<int>& outDegrees, int& uniformDegree) {
    uniformDegree = outDegrees[0];
    for (const auto& degree : outDegrees) {
        if (degree != uniformDegree) {
            return false;
        }
    }
    return true;
}

void findHangingAndIsolatedVertices(const Graph& graph, const std::vector<int>& outDegrees,
    const std::vector<int>& inDegrees, std::set<int>& hanging, std::set<int>& isolated) {
    for (int i = 0; i < graph.n; ++i) {
        if (outDegrees[i] == 0 && inDegrees[i] > 0) {
            hanging.insert(i + 1);
        }
        if (outDegrees[i] == 0 && inDegrees[i] == 0) {
            isolated.insert(i + 1);
        }
    }
}

void printResultsToFile(const std::string& filename, const std::vector<int>& inDegrees,
    const std::vector<int>& outDegrees, const std::set<int>& hanging,
    const std::set<int>& isolated, bool isUniform, int uniformDegree) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не вдалося відкрити файл для запису результатів");
    }

    file << "Степінь вершин (вхідна, вихідна):\n";
    for (size_t i = 0; i < inDegrees.size(); ++i) {
        file << "Вершина " << (i + 1) << ": " << inDegrees[i] << ", " << outDegrees[i] << "\n";
    }

    if (isUniform) {
        file << "Граф є однорідним, степінь однорідності: " << uniformDegree << "\n";
    }
    else {
        file << "Граф не є однорідним.\n";
    }

    file << "Висячі вершини: ";
    for (const auto& v : hanging) {
        file << v << " ";
    }
    file << "\n";

    file << "Ізольовані вершини: ";
    for (const auto& v : isolated) {
        file << v << " ";
    }
    file << "\n";

    file.close();

    std::cout << "Інформація успішно записана в файл ";
}

void printResultsToConsole(const std::vector<int>& inDegrees, const std::vector<int>& outDegrees,
    const std::set<int>& hanging, const std::set<int>& isolated,
    bool isUniform, int uniformDegree) {
    std::cout << "Степінь вершин (вхідна, вихідна):\n";
    for (size_t i = 0; i < inDegrees.size(); ++i) {
        std::cout << "Вершина " << (i + 1) << ": " << inDegrees[i] << ", " << outDegrees[i] << "\n";
    }

    if (isUniform) {
        std::cout << "Граф є однорідним, степінь однорідності: " << uniformDegree << "\n";
    }
    else {
        std::cout << "Граф не є однорідним.\n";
    }

    std::cout << "Висячі вершини: ";
    for (const auto& v : hanging) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::cout << "Ізольовані вершини: ";
    for (const auto& v : isolated) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    try {
        const std::string inputFilename = "D:\\Лаби ДПС\\ПДС_Лаб_6\\graph.txt"; // Вхідний файл
        const std::string outputFilename = "D:\\Лаби ДПС\\ПДС_Лаб_7\\results.txt"; // Вихідний файл
        Graph graph = readGraphFromFile(inputFilename);

        std::vector<int> inDegrees, outDegrees;
        calculateDegrees(graph, inDegrees, outDegrees);

        int uniformDegree;
        bool isUniformGraph = isUniform(outDegrees, uniformDegree);

        std::set<int> hanging, isolated;
        findHangingAndIsolatedVertices(graph, outDegrees, inDegrees, hanging, isolated);

        printResultsToConsole(inDegrees, outDegrees, hanging, isolated, isUniformGraph, uniformDegree);

        printResultsToFile(outputFilename, inDegrees, outDegrees, hanging, isolated, isUniformGraph, uniformDegree);
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
