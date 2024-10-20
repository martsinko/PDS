#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_2/Lab_5_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab52
{
	TEST_CLASS(UnitTestLab52)
	{
	public:
		
        TEST_METHOD(TestSetOperations)
        {
            // Створюємо бітові рядки A та B
            std::bitset<n> A;
            A[1] = 1; // A = {1}
            A[3] = 1; // A = {3}

            std::bitset<n> B;
            B[3] = 1; // B = {3}
            B[4] = 1; // B = {4}

            std::bitset<n> notA, intersection, unionAB, difference, xorAB;

            // Викликаємо функцію, яка виконує операції над множинами
            performSetOperations(A, B, notA, intersection, unionAB, difference, xorAB);

            // Тести для доповнення
            Assert::AreEqual(std::string("11110101"), notA.to_string()); // not A: {0, 2, 4, 5, 6, 7}

            // Тести для перетину
            Assert::AreEqual(std::string("00001000"), intersection.to_string()); // A ∩ B: {3}

            // Тести для об'єднання
            Assert::AreEqual(std::string("00011010"), unionAB.to_string()); // A ∪ B: {1, 3, 4}

            // Тести для різниці
            Assert::AreEqual(std::string("00000010"), difference.to_string()); // A \ B: {1}

            // Тести для симетричної різниці
            Assert::AreEqual(std::string("00010010"), xorAB.to_string()); // A ⊕ B: {1, 4}
        }
	};
}
