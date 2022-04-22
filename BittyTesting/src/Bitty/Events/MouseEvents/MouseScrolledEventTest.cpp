#include "pch.h"
#include "Bitty/Events/MouseEvents/MouseMovedEvent.h"
#include "Bitty/Events/MouseEvents/MouseScrolledEvent.h"

namespace {
    class MouseScrolledEventTest : public ::testing::Test {
    protected:
        Bitty::mouse_scrolled_event event;

        MouseScrolledEventTest() : event(Bitty::mouse_scrolled_event(0, 0)) {}
    };

    TEST_F(MouseScrolledEventTest, GetXOffset)
    {
        EXPECT_EQ(event.get_x_offset(), 0);

        event = Bitty::mouse_scrolled_event(-1000, 0);
        EXPECT_EQ(event.get_x_offset(), -1000);

        event = Bitty::mouse_scrolled_event(1000, 0);
        EXPECT_EQ(event.get_x_offset(), 1000);
    }

    TEST_F(MouseScrolledEventTest, GetYOffset)
    {
        EXPECT_EQ(event.get_y_offset(), 0);

        event = Bitty::mouse_scrolled_event(0, -1000);
        EXPECT_EQ(event.get_y_offset(), -1000);

        event = Bitty::mouse_scrolled_event(0, 1000);
        EXPECT_EQ(event.get_y_offset(), 1000);
    }

    TEST_F(MouseScrolledEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "MouseScrolled: 0, 0");
    }

    TEST_F(MouseScrolledEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryInput | Bitty::EventCategoryMouse);
    }

    TEST_F(MouseScrolledEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::MouseScrolled);
    }

    TEST_F(MouseScrolledEventTest, IsInCategory)
    {
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}