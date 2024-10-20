#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6_1/Lab_6_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab61
{
	TEST_CLASS(UnitTestLab61)
	{
	public:
		
        TEST_METHOD(TestReadGraphFromFile)
        {

            const std::string testFilename = "test_graph.txt";
            {
                std::ofstream outFile(testFilename);
                outFile << "3 3\n1 2\n2 3\n3 1\n"; 
                outFile.close();
            }

            Graph graph = readGraphFromFile(testFilename);

            Assert::AreEqual(3, graph.n);
            Assert::AreEqual(3, graph.m);
            Assert::AreEqual(3, (int)graph.edges.size());
            Assert::AreEqual(1, graph.edges[0].first);
            Assert::AreEqual(2, graph.edges[0].second);

            std::remove(testFilename.c_str());
        }

        TEST_METHOD(TestAdjacencyMatrix)
        {
            Graph graph;
            graph.n = 3;
            graph.m = 3;
            graph.edges = { {1, 2}, {2, 3}, {3, 1} };

            std::vector<std::vector<int>> expectedAdjacencyMatrix = {
                {0, 1, 0},
                {0, 0, 1},
                {1, 0, 0}
            };

            std::vector<std::vector<int>> actualAdjacencyMatrix(graph.n, std::vector<int>(graph.n, 0));
            for (const auto& edge : graph.edges) {
                actualAdjacencyMatrix[edge.first - 1][edge.second - 1] = 1;
            }

            for (size_t i = 0; i < expectedAdjacencyMatrix.size(); ++i) {
                for (size_t j = 0; j < expectedAdjacencyMatrix[i].size(); ++j) {
                    Assert::AreEqual(expectedAdjacencyMatrix[i][j], actualAdjacencyMatrix[i][j]);
                }
            }
        }

        TEST_METHOD(TestIncidenceMatrix)
        {
            Graph graph;
            graph.n = 3;
            graph.m = 3;
            graph.edges = { {1, 2}, {2, 3}, {3, 1} };

            std::vector<std::vector<int>> expectedIncidenceMatrix = {
                {1, 0, 1},
                {-1, 1, 0},
                {0, -1, 1}
            };

            std::vector<std::vector<int>> actualIncidenceMatrix(graph.n, std::vector<int>(graph.m, 0));
            for (int i = 0; i < graph.m; ++i) {
                actualIncidenceMatrix[graph.edges[i].first - 1][i] = 1;
                actualIncidenceMatrix[graph.edges[i].second - 1][i] = -1;
            }

            for (size_t i = 0; i < expectedIncidenceMatrix.size(); ++i) {
                for (size_t j = 0; j < expectedIncidenceMatrix[i].size(); ++j) {
                    Assert::AreEqual(expectedIncidenceMatrix[i][j], actualIncidenceMatrix[i][j]);
                }
            }
        }
	};
}
