#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2
{
	bool implication(bool p, bool q_and_not_r) {
		return !p || q_and_not_r;
	}

	TEST_CLASS(UnitTestLab2)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Тестування різних комбінацій значень для p, q ~ r
			Assert::AreEqual(implication(0, 1), true);  // p = 0, q ~ r = 1 -> p -> (q ~ r) = 1
			Assert::AreEqual(implication(0, 0), true);  // p = 0, q ~ r = 0 -> p -> (q ~ r) = 1
			Assert::AreEqual(implication(1, 1), true);  // p = 1, q ~ r = 1 -> p -> (q ~ r) = 1
			Assert::AreEqual(implication(1, 0), false); // p = 1, q ~ r = 0 -> p -> (q ~ r) = 0
		}
	};
}
