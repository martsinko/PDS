#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab12
{
	TEST_CLASS(UnitTestLab12)
	{
	public:
		
		TEST_METHOD(TestAndOperation)
		{
			string s1 = "1100";
			string s2 = "1010";
			int n = 4;
			string andResult = "", orResult = "", xorResult = "";

			bitOperations(s1, s2, n, andResult, orResult, xorResult);

			Assert::AreEqual(string("1000"), andResult);
		}
	};
}
