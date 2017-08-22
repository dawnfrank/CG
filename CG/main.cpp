#include <iostream>
#include <chrono>

#include "world.h"
#include "renderer.h"

int main() {
	Renderer r;
	auto w = r.OpenWindow(800, 600, "test");

	World *pWorld = r.GetWorld();
	Camera *pCamera = pWorld->GetCamera();
	Box *pBox = pWorld->GetBox();

	while (r.Run()) {
		r.Paint();

		Mat3 matrixCamera = pCamera->GetCoord();
	}

	return 0;
}