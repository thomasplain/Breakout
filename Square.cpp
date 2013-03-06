#include "Square.h"
#include <cmath>

LineSeg project(Vec2D& axis){
	float left = centre.get_x() - width / 2;
	float right = centre.get_x() + width / 2;
	float bottom = centre.get_y() - height / 2;
	float top = centre.get_y() + height / 2;
	
	Vec2D corners[4] = { 	Vec2D(left, top),
							Vec2D(right, top),
							Vec2D(right, bottom),
							Vec2D(left, bottom)
						}

	Vec2D min(corners[0].project(axis)), max(corners[0].project(axis));

	for (int i = 1; i < sizeof(corners) / sizeof(Vec2D); i++){
		if (corners[i].project(axis) < min) min = corners[i].project(axis);
		if (corners[i].project(axis) > max) max = corners[i].project(axis);
	}

	return LineSeg(min, max);
}

void move(Vec2D& v)	{
	centre += v;
}

// Just realised I haven't given a solution that'll allow a rotated square
bool collision_check(Shape& s){
	Vec2D n1 = Vec2D(
	LineSeg sp = s.project(normal,
}
