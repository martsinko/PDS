#include <iostream> 

#include <fstream> 

#include <vector> 

#include <iomanip> 

#include <limits> 

#define WIN32_LEAN_AND_MEAN  

#include <windows.h>  



const int INF = (std::numeric_limits<int>::max)();



void readGraphFromFile(const std::string& filename, std::vector<std::vector<int>>& weightMatrix, int& n, int& m) {

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {

        std::cerr << "Не вдалося відкрити файл " << filename << ". Перевірте шлях та існування файлу." << std::endl;

        return;

    }



    inputFile >> n >> m;



    weightMatrix.assign(n, std::vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {

        weightMatrix[i][i] = 0;

    }



    int v, u, w;

    for (int i = 0; i < m; ++i) {

        inputFile >> v >> u >> w;

        weightMatrix[v][u] = w;

    }



    inputFile.close();

}



void printMatrix(const std::vector<std::vector<int>>& matrix) {

    for (const auto& row : matrix) {

        for (int el : row) {

            if (el == INF)

                std::cout << std::setw(4) << "inf";

            else

                std::cout << std::setw(4) << el;

        }

        std::cout << std::endl;

    }

}



void writeMatrixToFile(const std::vector<std::vector<int>>& matrix, const std::string& filename) {

    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {

        std::cerr << "Не вдалося відкрити файл " << filename << " для запису. Перевірте шлях та доступ до папки." << std::endl;

        return;

    }



    for (const auto& row : matrix) {

        for (int el : row) {

            if (el == INF)

                outputFile << "inf ";

            else

                outputFile << el << " ";

        }

        outputFile << "\n";

    }


    outputFile.close();

}

int main() {

    SetConsoleOutputCP(1251);

    SetConsoleCP(1251);

    std::string inputFilename = "D:\\Лаби ДПС\\ПДС_Лаб_10\\wag_graph.txt";

    std::string outputFilename = "D:\\Лаби ДПС\\ПДС_Лаб_10\\matrix_output.txt";

    int n, m;

    std::vector<std::vector<int>> weightMatrix;



    readGraphFromFile(inputFilename, weightMatrix, n, m);



    if (weightMatrix.empty()) {

        std::cerr << "Помилка: не вдалося завантажити граф з файлу." << std::endl;

        return 1;

    }

    std::cout << "Матриця ваг графу:" << std::endl;

    printMatrix(weightMatrix);

    writeMatrixToFile(weightMatrix, outputFilename);

    std::cout << "Матриця ваг записана у файл '" << outputFilename << "'." << std::endl;

    return 0;

}