#pragma once

// For use by Bitty applications
#include "Bitty/Application.h"
#include "Bitty/Log.h"

// Events
#include "Bitty/Events/EventBase.h"

// Application Events
#include "Bitty/Events/ApplicationEvents/AppRenderEvent.h"
#include "Bitty/Events/ApplicationEvents/AppTickEvent.h"
#include "Bitty/Events/ApplicationEvents/AppUpdateEvent.h"
#include "Bitty/Events/ApplicationEvents/WindowCloseEvent.h"
#include "Bitty/Events/ApplicationEvents/WindowResizeEvent.h"

// Key Events
#include "Bitty/Events/KeyEvents/KeyEventBase.h"
#include "Bitty/Events/KeyEvents/KeyPressedEvent.h"
#include "Bitty/Events/KeyEvents/KeyReleasedEvent.h"

// Mouse Events

#include "Bitty/Events/MouseEvents/MouseButtonEventBase.h"
#include "Bitty/Events/MouseEvents/MouseButtonPressedEvent.h"
#include "Bitty/Events/MouseEvents/MouseButtonReleasedEvent.h"
#include "Bitty/Events/MouseEvents/MouseMovedEvent.h"
#include "Bitty/Events/MouseEvents/MouseScrolledEvent.h"

// ---Entry Point ---
#include "Bitty/EntryPoint.h"