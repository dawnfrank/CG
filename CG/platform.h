#pragma once

#ifdef _WIN32

#include "Windows.h "

#elif defined(__linux)

#define VK_USE_PLATFORM_XCB_KHR 1
#define PLATFORM_SURFACE_EXTENSION_NAME VK_KHR_XCB_SURFACE_EXTENSION_NAME
#include <xcb/xcb.h>

#else

#error Platform not yet supported

#endif
