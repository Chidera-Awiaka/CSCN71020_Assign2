#include "pch.h"
#include "CppUnitTest.h"
extern "C"
{
#include "../BCSRec/main.h"
}

extern "C"
{
	void setLength(int input, int* length);
	void setWidth(int input, int* width);
	int getPerimeter(int* length, int* width);
	int getArea(int* length, int* width);
	void printWelcomeMenu();
	void printOptions();
	int getIntInput(char message[]);
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecUnitTest
{
	TEST_CLASS(BCSRecUnitTest)
	{
	public:
		
		TEST_METHOD(Test_Get_Perimeter)
		{
			// Initialized the length and width for the test
			int length = 15; 
			int width = 10;

			// Gave an expected value
			int expectedPerimeter = 50; // 2*(15+10)

			// Assert to verify the values are equal
			int result = getPerimeter(&length, &width);
			Assert::AreEqual(expectedPerimeter, result);
		}

		TEST_METHOD(Test_Get_Area)
		{
			// Initialized the length and width for the test
			int length = 15;
			int width = 10;

			// Gave an expected value
			int expectedArea = 150; // 15 * 10

			// Assert to verify the values are equal
			int result = getArea(&length, &width);
			Assert::AreEqual(expectedArea, result);
		}

		TEST_METHOD(TestSetLength_Valid)
		{
			int length = 0;
			int input = 25;
			setLength(input, &length);
			Assert::AreEqual(25, length);
		}

		TEST_METHOD(TestSetLength_BelowValid)
		{
			int length = 10;
			int input = -1;
			setLength(input, &length);
			Assert::AreEqual(10, length); // Length should not change
		}

		TEST_METHOD(TestSetLength_AboveValid)
		{
			int length = 10;
			int input = 101;
			setLength(input, &length);
			Assert::AreEqual(10, length); // Length should not change
		}

		TEST_METHOD(TestSetWidth_Valid)
		{
			int width = 0;
			int input = 30;
			setWidth(input, &width);
			Assert::AreEqual(30, width);
		}

		TEST_METHOD(TestSetWidth_BelowValid)
		{
			int width = 20;
			int input = 0;
			setWidth(input, &width);
			Assert::AreEqual(20, width); // Width should not change
		}

		TEST_METHOD(TestSetWidth_AboveValid)
		{
			int width = 20;
			int input = 102;
			setWidth(input, &width);
			Assert::AreEqual(20, width); // Width should not change
		}


	};
}
