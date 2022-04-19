#include "../../../../pch.h"
#include "Bitty/Events/MouseEvents/MouseMovedEvent.h"

namespace {
    class MouseMovedEventTest : public ::testing::Test {
    protected:
        Bitty::mouse_moved_event event;

        MouseMovedEventTest() : event(Bitty::mouse_moved_event(0, 0)) {}
    };

    TEST_F(MouseMovedEventTest, GetX)
    {
        EXPECT_EQ(event.get_x(), 0);

        event = Bitty::mouse_moved_event(-1000, 0);
        EXPECT_EQ(event.get_x(), -1000);

        event = Bitty::mouse_moved_event(1000, 0);
        EXPECT_EQ(event.get_x(), 1000);
    }

    TEST_F(MouseMovedEventTest, GetY)
    {
        EXPECT_EQ(event.get_y(), 0);

        event = Bitty::mouse_moved_event(0, -1000);
        EXPECT_EQ(event.get_y(), -1000);

        event = Bitty::mouse_moved_event(0, 1000);
        EXPECT_EQ(event.get_y(), 1000);
    }

    TEST_F(MouseMovedEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "MouseMoved: 0, 0");
    }

    TEST_F(MouseMovedEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryInput | Bitty::EventCategoryMouse);
    }

    TEST_F(MouseMovedEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::MouseMoved);
    }

    TEST_F(MouseMovedEventTest, IsInCategory)
    {
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}