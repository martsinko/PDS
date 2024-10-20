#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_4/Lab_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab4
{
	TEST_CLASS(UnitTestLab4)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector<int> perm = { 1, 2, 3 };

			Assert::AreEqual(1, perm[0]);
			Assert::AreEqual(2, perm[1]);
			Assert::AreEqual(3, perm[2]);

			nextPermutation(perm);

			Assert::AreEqual(1, perm[0]);
			Assert::AreEqual(3, perm[1]);
			Assert::AreEqual(2, perm[2]);

			nextPermutation(perm);

			Assert::AreEqual(2, perm[0]);
			Assert::AreEqual(1, perm[1]);
			Assert::AreEqual(3, perm[2]);
		}
	};
}
