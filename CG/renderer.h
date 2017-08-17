#pragma once

#include <vector>

#include "platform.h"

class Window;

class Renderer
{
public:
	Renderer();
	~Renderer();

	Window* OpenWindow(uint32_t size_x, uint32_t size_y, std::string name);

	bool Run();
private:
	Window *_window = nullptr;
};