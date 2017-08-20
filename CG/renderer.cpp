#include <iostream>

#include "Renderer.h"
#include "Window.h"
#include "world.h"

Renderer::Renderer()
{
	_world = new World();
}

Renderer::~Renderer()
{
	delete _window;
	delete _world;
}

Window * Renderer::OpenWindow(uint32_t size_x, uint32_t size_y, std::string name)
{
	_window = new Window(this, size_x, size_y, name);

//	_BeginRenderer();
	return _window;
}

void Renderer::_BeginRenderer() {
	_hdc = BeginPaint(_window->GetHandler(), &_window->GetPainter());
}

void Renderer::_EndRenderer() {
	EndPaint(_window->GetHandler(), &_window->GetPainter());
}

void Renderer::Paint(){
	_BeginRenderer();
	HPEN hpen; // 画笔
	hpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	// DC 选择画笔
	SelectObject(_hdc, hpen);
	// (画笔)从初始点移动到 50,50
	MoveToEx(_hdc, 50, 50, NULL);
	// (画笔)从初始点画线到 100,100
	LineTo(_hdc, 150, 100);
	_EndRenderer();
}

bool Renderer::Run()
{
	if (nullptr != _window) {
		_fps.Update();
		return _window->Update();
	}
	return true;
}
