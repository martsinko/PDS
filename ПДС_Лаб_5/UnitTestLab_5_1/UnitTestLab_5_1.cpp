#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1/Lab_5_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51
{
	TEST_CLASS(UnitTestLab51)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            // Підготовка тестових даних
            char A[] = { 'a', 'b', 'c' };
            char B[] = { 'x', 'y', 'z' };
            char C[] = { '0', '1' };

            // Виклик функції
            vector<string> result = cartesianProduct(A, B, C);

            // Очікувані результати
            vector<string> expected = {
                "0ax", "0ay", "0az",
                "0bx", "0by", "0bz",
                "0cx", "0cy", "0cz",
                "1ax", "1ay", "1az",
                "1bx", "1by", "1bz",
                "1cx", "1cy", "1cz"
            };

            // Перевірка розміру
            Assert::AreEqual(expected.size(), result.size());

            // Перевірка значень
            for (size_t i = 0; i < expected.size(); ++i) {
                Assert::AreEqual(expected[i].c_str(), result[i].c_str());
            }
        }
	};
}
