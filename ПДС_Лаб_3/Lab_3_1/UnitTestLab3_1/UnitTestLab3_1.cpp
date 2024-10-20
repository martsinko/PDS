#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab31
{
	TEST_CLASS(UnitTestLab31)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тест для n = 8, r = 1
			Assert::AreEqual(8, calculateArrangements(8, 1));

			// Тест для n = 5, r = 2
			Assert::AreEqual(20, calculateArrangements(5, 2));

			// Тест для n = 6, r = 3
			Assert::AreEqual(120, calculateArrangements(6, 3));

			// Тест для n = 10, r = 4
			Assert::AreEqual(5040, calculateArrangements(10, 4));

			// Тест для країв (Edge cases)
			// Тест для n = 0, r = 0
			Assert::AreEqual(1, calculateArrangements(0, 0));

			// Тест для n = 1, r = 0
			Assert::AreEqual(1, calculateArrangements(1, 0));

			// Тест для n = 1, r = 1
			Assert::AreEqual(1, calculateArrangements(1, 1));

			// Тест для n = 10, r = 0
			Assert::AreEqual(1, calculateArrangements(10, 0));
		}
	};
}
