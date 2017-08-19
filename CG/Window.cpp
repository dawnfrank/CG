#include "Window.h"
#include "renderer.h"

Window::Window(Renderer * renderer, uint32_t size_x, uint32_t size_y, std::string name)
{
	_renderer = renderer;
	_surface_size_x = size_x;
	_surface_size_y = size_y;
	_window_name = name;

	_InitOSWindow();
}

Window::~Window()
{
	_DeInitOsWindow();
}

void Window::Close()
{
	_window_should_run = false;
}

bool Window::Update()
{
	_UpdateOSWindow();
	return _window_should_run;
}

/*
void Window::Paint()
{
	// paint struct ��ͼ�ṹ�壬�洢Ŀ�괰�ڿ��Ի�ͼ�Ŀͻ�������(client area)
	HPEN hpen; // ����

	// ͨ�����ھ����ȡ�ô��ڵ� DC
	_hdc = BeginPaint(_win32_window, &_ps);
	// ��������
	hpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	// DC ѡ�񻭱�
	SelectObject(_hdc, hpen);
	// (����)�ӳ�ʼ���ƶ��� 50,50
	MoveToEx(_hdc, 50, 50, NULL);
	// (����)�ӳ�ʼ�㻭�ߵ� 100,100
	LineTo(_hdc, 150, 100);

	EndPaint(_win32_window, &_ps);
}
*/