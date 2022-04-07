#include "pch.h"

namespace Bitty
{
	__declspec(dllimport) void Print();
}

TEST(TestCaseName, TestName) {
	Bitty::Print();
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}