#include "Renderer.h"
#include "Window.h"

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
	delete _window;
}

Window * Renderer::OpenWindow(uint32_t size_x, uint32_t size_y, std::string name)
{
	_window = new Window(this, size_x, size_y, name);



	return _window;
}

void Renderer::_BeginRenderer() {
	BeginPaint(_window->GetHandler(), &_window->GetPainter());
}

void Renderer::_EndRenderer() {
	EndPaint(_window->GetHandler(), &_window->GetPainter());
}

void Renderer::Paint() {
	HPEN hpen; // 画笔
	HDC hdc = _window->GetHDC();

	hpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	// DC 选择画笔
	SelectObject(hdc, hpen);
	// (画笔)从初始点移动到 50,50
	MoveToEx(hdc, 50, 50, NULL);
	// (画笔)从初始点画线到 100,100
	LineTo(hdc, 150, 100);
}

bool Renderer::Run()
{
	if (nullptr != _window) return _window->Update();
	return true;
}
