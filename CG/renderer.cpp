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
	HPEN hpen; // ����
	HDC hdc = _window->GetHDC();

	hpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	// DC ѡ�񻭱�
	SelectObject(hdc, hpen);
	// (����)�ӳ�ʼ���ƶ��� 50,50
	MoveToEx(hdc, 50, 50, NULL);
	// (����)�ӳ�ʼ�㻭�ߵ� 100,100
	LineTo(hdc, 150, 100);
}

bool Renderer::Run()
{
	if (nullptr != _window) return _window->Update();
	return true;
}
