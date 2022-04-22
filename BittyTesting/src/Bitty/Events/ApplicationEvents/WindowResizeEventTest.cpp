#include "pch.h"
#include "Bitty/Events/ApplicationEvents/WindowResizeEvent.h"

namespace {
    class WindowResizeEventTest : public ::testing::Test {
    protected:
        Bitty::window_resize_event event;

        WindowResizeEventTest() : event(Bitty::window_resize_event(1280, 720)) {}
    };

    TEST_F(WindowResizeEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "WindowResize: 1280, 720");
    }

    TEST_F(WindowResizeEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryApplication);
    }

    TEST_F(WindowResizeEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::WindowResize);
    }

    TEST_F(WindowResizeEventTest, GetWidth)
    {
        EXPECT_EQ(event.get_width(), 1280);
    }

    TEST_F(WindowResizeEventTest, GetHeight)
    {
        EXPECT_EQ(event.get_height(), 720);
    }

    TEST_F(WindowResizeEventTest, IsInCategory)
    {
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}