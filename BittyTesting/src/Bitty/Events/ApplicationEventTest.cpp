#include "../../../pch.h"
#include "Bitty/Events/ApplicationEvent.h"

namespace {
    class WindowResizeEventTest : public ::testing::Test {
    protected:
        Bitty::WindowResizeEvent* window_resize_event { nullptr };

        virtual void SetUp() {
            window_resize_event = new Bitty::WindowResizeEvent(1280, 720);
        }

        virtual void TearDown() {
            delete window_resize_event;
        }
    };

    TEST_F(WindowResizeEventTest, ToString) {
        EXPECT_EQ(window_resize_event->ToString(), "WindowResizeEvent: 1280, 720");
    }

    TEST_F(WindowResizeEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(window_resize_event->GetCategoryFlags(), Bitty::EventCategoryApplication);
    }

    TEST_F(WindowResizeEventTest, GetEventType)
    {
        EXPECT_EQ(window_resize_event->GetEventType(), Bitty::EventType::WindowResize);
    }

    TEST_F(WindowResizeEventTest, GetWidth)
    {
        EXPECT_EQ(window_resize_event->GetWidth(), 1280);
    }

    TEST_F(WindowResizeEventTest, GetHeight)
    {
        EXPECT_EQ(window_resize_event->GetHeight(), 720);
    }

    TEST_F(WindowResizeEventTest, IsInCategory)
    {
        EXPECT_TRUE(window_resize_event->IsInCategory(Bitty::EventCategoryApplication));
        EXPECT_FALSE(window_resize_event->IsInCategory(Bitty::EventCategoryInput));
        EXPECT_FALSE(window_resize_event->IsInCategory(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(window_resize_event->IsInCategory(Bitty::EventCategoryMouse));
        EXPECT_FALSE(window_resize_event->IsInCategory(Bitty::EventCategoryMouseButton));
    }
}