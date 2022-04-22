#include "pch.h"
#include "Bitty/Events/KeyEvents/KeyReleasedEvent.h"

namespace {
    const int key_code_a = static_cast<int>('a');
    const int key_code_b = static_cast<int>('b');
    const int key_code_c = static_cast<int>('c');

    class KeyReleasedEventTest : public ::testing::Test {
    protected:
        Bitty::key_released_event event;

        KeyReleasedEventTest() : event(Bitty::key_released_event(key_code_a)) {}
    };

    TEST_F(KeyReleasedEventTest, GetKeyCode)
    {
        EXPECT_EQ(event.get_key_code(), key_code_a);

        event = Bitty::key_released_event(key_code_b);
        EXPECT_EQ(event.get_key_code(), key_code_b);

        event = Bitty::key_released_event(key_code_c);
        EXPECT_EQ(event.get_key_code(), key_code_c);
    }

    TEST_F(KeyReleasedEventTest, ToString) {
        std::stringstream ss;
        ss << "KeyReleased: " << event.get_key_code();

        EXPECT_EQ(event.to_string(), ss.str());
    }

    TEST_F(KeyReleasedEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryInput | Bitty::EventCategoryKeyboard);
    }

    TEST_F(KeyReleasedEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::KeyReleased);
    }

    TEST_F(KeyReleasedEventTest, IsInCategory)
    {
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}