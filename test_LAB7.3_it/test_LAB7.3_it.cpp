#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB7.3_it/LAB7.3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testLAB73it
{
	TEST_CLASS(testLAB73it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int** matrix = new int* [3];

            for (int i = 0; i < 3; i++) {
                matrix[i] = new int[3];
            }

            matrix[0][0] = 1;
            matrix[0][1] = -2;
            matrix[0][2] = 3;
            matrix[1][0] = 4;
            matrix[1][1] = 5;
            matrix[1][2] = 6;
            matrix[2][0] = 7;
            matrix[2][1] = 8;
            matrix[2][2] = 9;

            Assert::AreEqual(sumInRowsWithNegative(matrix, 3, 3), 2);

            for (int i = 0; i < 3; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
		}
	};
}
