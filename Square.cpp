#include "Square.h"
Square::Square(Vec2D c, float h, float w, float a) : centre(c), height(h), width(w), angle(a) {
	if (angle >= 360) angle -= 360;
	else if (angle < 0) angle += 360;

	float left = centre.get_x() - width / 2;
	float right = centre.get_x() + width / 2;
	float bottom = centre.get_y() - height / 2;
	float top = centre.get_y() + height / 2;

	// Define corner vertices	
	corners[0] = Vec2D(left, top);
	corners[1] = Vec2D(right, top);
	corners[2] = Vec2D(right, bottom);
	corners[3] = Vec2D(left, bottom);
}

LineSeg Square::project(const Vec2D& axis){
	// Rotate vertices if angle orientation isn't zero
	if (angle != 0){
		for (int i = 0; i++; i < 4){
			corners[i].rotate(angle);
		}
	}

	Vec2D min(corners[0].project(axis)), max(corners[0].project(axis));

	// Just ensuring that full length of shape is projected onto axis
	for (int i = 1; i < sizeof(corners) / sizeof(Vec2D); i++){
		if (corners[i].project(axis) < min) min = corners[i].project(axis);
		if (corners[i].project(axis) > max) max = corners[i].project(axis);
	}

	return LineSeg(min, max);
}

bool Square::collision_check(Shape& s){

	// Separation axes are normals to edges
	Vec2D xaxis(1, 0);
	Vec2D yaxis(0, 1);

	if (angle != 0){
		xaxis.rotate(angle);
		yaxis.rotate(angle);
	}

	LineSeg sp = s.project(xaxis), p = project(xaxis);
	if (!sp.overlap(p)) return false;

	sp = s.project(yaxis); p = project(yaxis);
	if (!sp.overlap(p)) return false;

	return true;
}

Vec2D Square::get_nearest(Vec2D point){
	// Find nearest point to centre of other shape
	// Define vector between two centres and then bound by square width and height
	Vec2D np = (point - centre);
		if (np.get_x() > width / 2) np.set_x(width/2);
		else if (np.get_x() < -width / 2) np.set_x(-width/2);
		if (np.get_y() > height / 2) np.set_y(height/2);
		else if (np.get_y() < -height / 2) np.set_y(-height/2);
	return np + centre;
}
