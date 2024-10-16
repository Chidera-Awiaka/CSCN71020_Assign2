#include "pch.h"
#include "CppUnitTest.h"
extern "C"
{
#include "../BCSRec/main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecUnitTest
{
	TEST_CLASS(BCSRecUnitTest)
	{
	public:
		
		TEST_METHOD(Test_Get_Perimeter)
		{
			// Initilized the length and width for the test
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
			// Initilized the length and width for the test
			int length = 15;
			int width = 10;

			// Gave an expected value
			int expectedArea = 150; // 15 * 10

			// Assert to verify the values are equal
			int result = getArea(&length, &width);
			Assert::AreEqual(expectedArea, result);
		}
	};
}
