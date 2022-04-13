#include "../../../pch.h"
#include "Bitty/Events/ApplicationEvents/WindowResizeEvent.h"
#include "Bitty/Application.h"

namespace {
    class WindowResizeEventTest : public ::testing::Test {
    protected:
        Bitty::window_resize_event* wre { nullptr };

        WindowResizeEventTest() {
            wre = new Bitty::window_resize_event(1280, 720);
        }

        ~WindowResizeEventTest() override {
            delete wre;
        }
    };

    TEST_F(WindowResizeEventTest, ToString) {
        EXPECT_EQ(wre->to_string(), "WindowResizeEvent: 1280, 720");
    }

    TEST_F(WindowResizeEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(wre->get_category_flags(), Bitty::EventCategoryApplication);
    }

    TEST_F(WindowResizeEventTest, GetEventType)
    {
        EXPECT_EQ(wre->get_event_type(), Bitty::EventType::WindowResize);
    }

    TEST_F(WindowResizeEventTest, GetWidth)
    {
        EXPECT_EQ(wre->get_width(), 1280);
    }

    TEST_F(WindowResizeEventTest, GetHeight)
    {
        EXPECT_EQ(wre->get_height(), 720);
    }

    TEST_F(WindowResizeEventTest, IsInCategory)
    {
        EXPECT_TRUE(wre->is_in_category(Bitty::EventCategoryApplication));
        EXPECT_FALSE(wre->is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(wre->is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(wre->is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(wre->is_in_category(Bitty::EventCategoryMouseButton));
    }
}