#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
	TEST_CLASS(UnitTest71)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int Q[2][2] = { {2, 1}, {7, 5} };
			int s = 0;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++)
					if (Q[i][j] % 2 == 0 && (i + j) % 8 != 0)
						s += Q[i][j];
			}
			Assert::AreEqual(s, 0);
		}
	};
}
