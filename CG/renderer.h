#pragma once

#include <Vector>

#include "platform.h"
#include "fps.h"

class Window;
class World;

class Renderer
{
public:
	Renderer();
	~Renderer();

	Window* OpenWindow(uint32_t size_x, uint32_t size_y, std::string name);

	bool Run();
	void Paint();

	World *GetWorld() { return _world; }

private:
	void _BeginRenderer();
	void _EndRenderer();

	HDC _hdc;
	Window *_window = nullptr;
	World *_world = nullptr;

	FPS _fps;
};