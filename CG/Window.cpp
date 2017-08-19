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
	// paint struct 绘图结构体，存储目标窗口可以绘图的客户端区域(client area)
	HPEN hpen; // 画笔

	// 通过窗口句柄获取该窗口的 DC
	_hdc = BeginPaint(_win32_window, &_ps);
	// 创建画笔
	hpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	// DC 选择画笔
	SelectObject(_hdc, hpen);
	// (画笔)从初始点移动到 50,50
	MoveToEx(_hdc, 50, 50, NULL);
	// (画笔)从初始点画线到 100,100
	LineTo(_hdc, 150, 100);

	EndPaint(_win32_window, &_ps);
}
*/