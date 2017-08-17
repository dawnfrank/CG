
#include "renderer.h"
#include <iostream>
#include <chrono>

int main() {
	Renderer r;
	auto w = r.OpenWindow(800, 600, "test");

	auto timer = std::chrono::steady_clock();
	auto last_time = timer.now();
	uint64_t frame_counter = 0;
	uint64_t fps = 0;
	while (r.Run()) {
		++frame_counter;
		if (last_time + std::chrono::seconds(1) < timer.now()) {
			last_time = timer.now();
			fps = frame_counter;
			frame_counter = 0;
			std::cout << "FPS:" << fps << std::endl;
		}
	}

	return 0;
}