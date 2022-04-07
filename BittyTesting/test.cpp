#include "pch.h"
#include "Bitty.h"

TEST(TestCaseName, TestName) {
	Bitty::Log::GetCoreLogger()->warn("WARNING");
	Bitty::Log::GetClientLogger()->info("INFO");
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}