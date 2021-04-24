#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_5.1(E)/Object.cpp"
#include "../Lab_5.1(E)/FuzzyNumber.cpp"
#include "../Lab_5.1(E)/Multi_and_Addit.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab51E
{
	TEST_CLASS(UnitTestLab51E)
	{
	public:
		
		TEST_METHOD(Test_Addit)
		{
			FuzzyNumber A, B, C;
			FuzzyNumber L;
			{
				FuzzyNumber K;
			}

			Assert::AreEqual(Object::Display(), (unsigned)4);
		}
	};
}