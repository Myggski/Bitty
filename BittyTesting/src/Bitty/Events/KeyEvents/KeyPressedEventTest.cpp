#include "pch.h"
#include "Bitty/Events/KeyEvents/KeyPressedEvent.h"

namespace {
    const int key_code_a = static_cast<int>('a');
    const int key_code_b = static_cast<int>('b');
    const int key_code_c = static_cast<int>('c');

    class KeyPressedEventTest : public ::testing::Test {
    protected:
        Bitty::key_pressed_event event;

        KeyPressedEventTest() : event(Bitty::key_pressed_event(key_code_a, 0)) {}
    };

    TEST_F(KeyPressedEventTest, GetKeyCode)
    {
        EXPECT_EQ(event.get_key_code(), key_code_a);

        event = Bitty::key_pressed_event(key_code_b, 0);
        EXPECT_EQ(event.get_key_code(), key_code_b);

        event = Bitty::key_pressed_event(key_code_c, 0);
        EXPECT_EQ(event.get_key_code(), key_code_c);
    }

    TEST_F(KeyPressedEventTest, GetRepeatCount)
    {
        EXPECT_EQ(event.get_repeat_count(), 0);

        event = Bitty::key_pressed_event(key_code_a, -10);
        EXPECT_EQ(event.get_repeat_count(), -10);

        event = Bitty::key_pressed_event(key_code_a, 1000);
        EXPECT_EQ(event.get_repeat_count(), 1000);
    }

    TEST_F(KeyPressedEventTest, ToString) {
        std::stringstream ss;
        ss << "KeyPressed: " << event.get_key_code() << " (" << event.get_repeat_count() << " repeats)";

        EXPECT_EQ(event.to_string(), ss.str());
    }

    TEST_F(KeyPressedEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryInput | Bitty::EventCategoryKeyboard);
    }

    TEST_F(KeyPressedEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::KeyPressed);
    }

    TEST_F(KeyPressedEventTest, IsInCategory)
    {
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}