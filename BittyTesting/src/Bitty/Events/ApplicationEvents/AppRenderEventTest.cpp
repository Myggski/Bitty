#include "pch.h"
#include "Bitty/Events/ApplicationEvents/AppRenderEvent.h"

namespace {
    class AppRenderEventTest : public ::testing::Test {
    protected:
        Bitty::app_render_event event;

        AppRenderEventTest() : event(Bitty::app_render_event()) {}
    };

    TEST_F(AppRenderEventTest, ToString) {
        EXPECT_EQ(event.to_string(), "AppRender");
    }

    TEST_F(AppRenderEventTest, GetCategoryFlags)
    {
        EXPECT_EQ(event.get_category_flags(), Bitty::EventCategoryApplication);
    }

    TEST_F(AppRenderEventTest, GetEventType)
    {
        EXPECT_EQ(event.get_event_type(), Bitty::EventType::AppRender);
    }

    TEST_F(AppRenderEventTest, IsInCategory)
    {
        EXPECT_TRUE(event.is_in_category(Bitty::EventCategoryApplication));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryInput));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryKeyboard));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouse));
        EXPECT_FALSE(event.is_in_category(Bitty::EventCategoryMouseButton));
    }
}