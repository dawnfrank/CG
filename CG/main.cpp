#include <iostream>
#include <chrono>

#include "renderer.h"

int main() {
	Renderer r;
	auto w = r.OpenWindow(800, 600, "test");

	while (r.Run()) {
		r.Paint();
	}

	return 0;
}