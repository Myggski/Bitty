#include "pch.h"
#include "Bitty/Events/MouseEvents/MouseButtonPressedEvent.h"

namespace {
    const int button_left = 0;
    const int button_right = 1;
    const int button_middle = 2;

    class MouseButtonPressedEventTest : public ::testing::Test {
    protected:
        Bitty::mouse_button_pressed_event event;

        MouseButtonPressedEventTest() : event(Bitty::mouse_button_pressed_event(button_left)) {}
    };

    TEST_F(MouseButtonPressedEventTest, GetMouseButton)
    {
        EXPECT_EQ(event.get_mouse_button(), button_left);

        event = Bitty::mouse_button_pressed_event(button_right);
        EXPECT_EQ(event.get_mouse_button(), button_right);

        event = Bitty::mouse_button_pressed_event(button_middle);
        EXPECT_EQ(event.get_mouse_button(), button_middle);
    }

    TEST_F(MouseButtonPressedEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "MouseButtonPressed: 0");
    }

    TEST_F(MouseButtonPressedEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryInput | Bitty::EventCategoryMouse);
    }

    TEST_F(MouseButtonPressedEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::MouseButtonPressed);
    }

    TEST_F(MouseButtonPressedEventTest, IsInCategory)
    {
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}