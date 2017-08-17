#pragma once

#include <string>
#include <vector>

#include "platform.h"

class Renderer;

class Window
{
public:
	Window(Renderer *render, uint32_t size_x, uint32_t size_y, std::string name);
	~Window();

	void Close();
	bool Update();
private:
	void _InitOSWindow();
	void _DeInitOsWindow();
	void _UpdateOSWindow();
	
	Renderer *_render = nullptr;

	uint32_t _surface_size_x = 512;
	uint32_t _surface_size_y = 512;
	std::string _window_name;

	bool _window_should_run = true;

	HINSTANCE	_win32_instance = NULL;
	HWND _win32_window = NULL;
	std::string _win32_class_name;
	static uint64_t _win32_class_id_counter;


};