#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3_2.cpp"
#include <vector>
#include <utility>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab32
{
	TEST_CLASS(UnitTestLab32)
	{
	public:
        TEST_METHOD(TestMethod1)
        {
            int i = 3;
            auto result = calculateStirlingAndBell(i);

            // Отримуємо результати
            vector<vector<int>> F = result.first;
            vector<int> B = result.second;

            // Перевіряємо деякі значення чисел Стірлінга
            Assert::AreEqual(1, F[1][1]);
            Assert::AreEqual(1, F[2][1]);
            Assert::AreEqual(1, F[2][2]);
            Assert::AreEqual(3, F[3][2]);
            Assert::AreEqual(1, F[3][3]);

            // Перевіряємо числа Белла
            Assert::AreEqual(1, B[1]);
            Assert::AreEqual(2, B[2]);
            Assert::AreEqual(5, B[3]);
        }

	};
}
