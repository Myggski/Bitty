#include "pch.h"
#include "Bitty/Events/ApplicationEvents/WindowCloseEvent.h"

namespace {
    class WindowCloseEventTest : public ::testing::Test {
    protected:
        Bitty::window_close_event event;

        WindowCloseEventTest() : event(Bitty::window_close_event()) {}
    };

    TEST_F(WindowCloseEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "WindowClose");
    }

    TEST_F(WindowCloseEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryApplication);
    }

    TEST_F(WindowCloseEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::WindowClose);
    }

    TEST_F(WindowCloseEventTest, IsInCategory)
    {
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}