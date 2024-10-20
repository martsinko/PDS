#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4_2/Lab_4_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab42
{
	TEST_CLASS(UnitTestLab42)
	{
	public:
		
		TEST_METHOD(TestNextCombination)
		{
			int n = 5;  // кількість елементів у множині
			int r = 3;  // кількість елементів у сполученні

			// Початкове сполучення 1 2 3
			vector<int> combination = { 1, 2, 3 };

			// Викликаємо функцію nextCombination та перевіряємо результати
			bool hasNext = nextCombination(combination, n, r);
			Assert::IsTrue(hasNext);
			Assert::AreEqual(1, combination[0]);
			Assert::AreEqual(2, combination[1]);
			Assert::AreEqual(4, combination[2]);

			// Наступне сполучення: 1 2 5
			hasNext = nextCombination(combination, n, r);
			Assert::IsTrue(hasNext);
			Assert::AreEqual(1, combination[0]);
			Assert::AreEqual(2, combination[1]);
			Assert::AreEqual(5, combination[2]);

			// Наступне сполучення: 1 3 4
			hasNext = nextCombination(combination, n, r);
			Assert::IsTrue(hasNext);
			Assert::AreEqual(1, combination[0]);
			Assert::AreEqual(3, combination[1]);
			Assert::AreEqual(4, combination[2]);

			// Наступне сполучення: 1 3 5
			hasNext = nextCombination(combination, n, r);
			Assert::IsTrue(hasNext);
			Assert::AreEqual(1, combination[0]);
			Assert::AreEqual(3, combination[1]);
			Assert::AreEqual(5, combination[2]);

			// Далі ще кілька сполучень до кінця
			hasNext = nextCombination(combination, n, r);  // 1 4 5
			Assert::IsTrue(hasNext);
			Assert::AreEqual(1, combination[0]);
			Assert::AreEqual(4, combination[1]);
			Assert::AreEqual(5, combination[2]);

			hasNext = nextCombination(combination, n, r);  // 2 3 4
			Assert::IsTrue(hasNext);
			Assert::AreEqual(2, combination[0]);
			Assert::AreEqual(3, combination[1]);
			Assert::AreEqual(4, combination[2]);

			// Перевіряємо коли більше немає нових комбінацій
			hasNext = nextCombination(combination, n, r);  // 2 3 5
			Assert::IsTrue(hasNext);

			hasNext = nextCombination(combination, n, r);  // 2 4 5
			Assert::IsTrue(hasNext);

			hasNext = nextCombination(combination, n, r);  // 3 4 5
			Assert::IsTrue(hasNext);

			// Більше немає комбінацій
			hasNext = nextCombination(combination, n, r);
			Assert::IsFalse(hasNext);
		}
	};
}
