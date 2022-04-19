#include "../../../../pch.h"
#include "Bitty/Events/ApplicationEvents/AppTickEvent.h"

namespace {
    class AppTickEventTest : public ::testing::Test {
    protected:
        Bitty::app_tick_event event;

        AppTickEventTest() : event(Bitty::app_tick_event()) {}
    };

    TEST_F(AppTickEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "AppTick");
    }

    TEST_F(AppTickEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryApplication);
    }

    TEST_F(AppTickEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::AppTick);
    }

    TEST_F(AppTickEventTest, IsInCategory)
    {
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}