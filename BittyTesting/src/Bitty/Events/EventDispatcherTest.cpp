#include "../../../pch.h"
#include "Bitty/Events/EventBase.h"
#include "Bitty/Events/EventDispatcher.h"
#include "Bitty/Events/ApplicationEvents/AppRenderEvent.h"
#include "Bitty/Events/ApplicationEvents/AppTickEvent.h"
#include <functional>

namespace {
    TEST(EventDispatcherTest, DispatchMatchedType)
    {
        using CallbackFunctionMock = testing::MockFunction<std::function<bool(Bitty::app_render_event&)>>;
        CallbackFunctionMock callbackFunctionMock;

        Bitty::app_render_event event{ };
        Bitty::event_dispatcher dispatcher{ event };

        EXPECT_CALL(callbackFunctionMock, Call(testing::_)).WillOnce(testing::Return(true));
        dispatcher.dispatch<Bitty::app_render_event>(callbackFunctionMock.AsStdFunction());
    }

    TEST(EventDispatcherTest, DispatchMismatchType)
    {
        using CallbackFunctionMock = testing::MockFunction<std::function<bool(Bitty::event_base&)>>;
        CallbackFunctionMock callbackFunctionMock;

        Bitty::app_render_event event{ };
        Bitty::event_dispatcher dispatcher{ event };

        EXPECT_CALL(callbackFunctionMock, Call(testing::_)).Times(0);
        dispatcher.dispatch<Bitty::app_tick_event>(callbackFunctionMock.AsStdFunction());
    }
}
