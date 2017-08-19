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
	void Paint();

private:
	void _BeginRenderer();
	void _EndRenderer();

	HDC _hdc;
	Window *_window = nullptr;
};