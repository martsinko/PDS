#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_1_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab11
{
	TEST_CLASS(UnitTestLab11)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool p = true, q = false;
			Assert::IsFalse(getConjunction(p, q));
		}
	};
}
