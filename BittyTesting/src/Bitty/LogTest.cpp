#include "../../pch.h"
#include "Bitty/Log.h"
#include "spdlog/spdlog.h"

namespace {
    TEST(LogTest, Init) {
        EXPECT_EQ(Bitty::log::get_core_logger(), nullptr);
        EXPECT_EQ(Bitty::log::get_client_logger(), nullptr);

        Bitty::log::init();

        EXPECT_EQ(Bitty::log::get_core_logger()->level(), spdlog::level::trace);
        EXPECT_EQ(Bitty::log::get_core_logger()->name(), "BITTY");

        EXPECT_EQ(Bitty::log::get_client_logger()->level(), spdlog::level::trace);
        EXPECT_EQ(Bitty::log::get_client_logger()->name(), "APP");
    }
}