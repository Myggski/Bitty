#include "pch.h"
#include "Bitty/Events/ApplicationEvents/AppUpdateEvent.h"

namespace {
    class AppUpdateEventTest : public ::testing::Test {
    protected:
        Bitty::app_update_event event;

        AppUpdateEventTest() : event(Bitty::app_update_event()) {}
    };

    TEST_F(AppUpdateEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "AppUpdate");
    }

    TEST_F(AppUpdateEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryApplication);
    }

    TEST_F(AppUpdateEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::AppUpdate);
    }

    TEST_F(AppUpdateEventTest, IsInCategory)
    {
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}