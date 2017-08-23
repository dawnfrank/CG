#include <iostream>
#include <chrono>

#include "world.h"
#include "renderer.h"
using namespace std;

ostream &operator<<(ostream &os,const Vec3 &v){
	os << v[0] << " " << v[1] << " " << v[2] << endl;
	return os;
}

int main() {
	Renderer r;
	auto w = r.OpenWindow(800, 600, "test");

	World *pWorld = r.GetWorld();
	Camera *pCamera = pWorld->GetCamera();
	Box *pBox = pWorld->GetBox();


	Mat3 CameraProj=Mat3(Vec3(1,0,0), Vec3(0,1,0), Vec3(0,0,0));
	Mat3 matrixCamera = pCamera->GetCoord().inverse();

	auto vertexs = pBox->GetVertex();
	vector<Vec2> points;
	Vec2 minPoint;
	for (auto &v : vertexs) {
		v = CameraProj*matrixCamera*v;
		points.push_back(Vec2(v.x, v.y));
		if (minPoint.x > v.x) minPoint = Vec2(v.x, v.y);
		else if(minPoint.x == v.x&& minPoint.y > v.y)minPoint = Vec2(v.x, v.y);
		cout << v.x << " " << v.y << endl;
	}

	vector<Vec2> projVertexs;
	projVertexs.push_back(minPoint);

	Vec2 temp,maxPoint;
	float slope,maxSlope=0;
	cout << points.size() << asin(1) <<asin(-1) <<endl;
	for (int i = 0; i != 5; ++i) {
		for (auto p : points) {
			if (p == minPoint)continue;
			temp = p - minPoint;
			slope = temp[0] == 0 ? 0 : asin(temp[1] / temp[0]);
			if (slope > maxSlope) {
				maxSlope = slope;
				maxPoint = p;
			}
		}
		projVertexs.push_back(maxPoint);
		minPoint = maxPoint;
		slope = maxSlope = 0;
	}

	for(auto p: projVertexs) cout << p.x << " " << p.y << endl;

	while (r.Run()) {
		r.Paint();
	}

	return 0;
}