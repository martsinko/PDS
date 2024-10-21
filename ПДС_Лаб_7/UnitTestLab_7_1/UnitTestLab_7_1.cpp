#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7_1/Lab_7_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab71
{
	TEST_CLASS(UnitTestLab71)
	{
	public:
        TEST_METHOD(TestCalculateDegrees)
        {
            Graph graph;
            graph.n = 3;
            graph.m = 2;
            graph.edges = { {1, 2}, {2, 3} };

            std::vector<int> inDegrees, outDegrees;
            calculateDegrees(graph, inDegrees, outDegrees);

            Assert::AreEqual(0, inDegrees[0]);
            Assert::AreEqual(1, inDegrees[1]);
            Assert::AreEqual(1, inDegrees[2]);

            Assert::AreEqual(1, outDegrees[0]);
            Assert::AreEqual(1, outDegrees[1]);
            Assert::AreEqual(0, outDegrees[2]);
        }

        // Тест для функції isUniform
        TEST_METHOD(TestIsUniform)
        {
            std::vector<int> outDegrees = { 2, 2, 2 };
            int uniformDegree;
            bool result = isUniform(outDegrees, uniformDegree);

            Assert::IsTrue(result);
            Assert::AreEqual(2, uniformDegree);
        }

        // Тест для функції findHangingAndIsolatedVertices
        TEST_METHOD(TestFindHangingAndIsolatedVertices)
        {
            Graph graph;
            graph.n = 3;
            graph.m = 2;
            graph.edges = { {1, 2}, {2, 3} };

            std::vector<int> inDegrees = { 0, 1, 1 };
            std::vector<int> outDegrees = { 1, 1, 0 };
            std::set<int> hanging, isolated;

            findHangingAndIsolatedVertices(graph, outDegrees, inDegrees, hanging, isolated);

            Assert::IsTrue(hanging.find(3) != hanging.end());
            Assert::IsTrue(isolated.empty());
        }
	};
}
