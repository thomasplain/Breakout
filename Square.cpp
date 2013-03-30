#include "Square.h"
#include <cmath>
Square::Square(Vec2D c, float h, float w, float a) : centre(c), height(h), width(w), angle(a) {
	if (angle >= 360) angle -= 360;
	else if (angle <= -360) angle += 360;

	Vec2D leftVec = Vec2D(-width/2, 0);
	Vec2D rightVec = Vec2D(width/2, 0);
	Vec2D topVec = Vec2D(0, height/2);
	Vec2D bottomVec = Vec2D(0, -height/2);

	if (angle != 0){
		leftVec.rotate(angle);
		rightVec.rotate(angle);
		topVec.rotate(angle);
		bottomVec.rotate(angle);
	}
	
	corners[0] = c + leftVec + topVec;
	corners[1] = c + leftVec + bottomVec;
	corners[2] = c + rightVec + bottomVec;
	corners[3] = c + rightVec + topVec;
}

LineSeg Square::project(const Vec2D& axis) const{
	Vec2D min(corners[0].project(axis)), max(corners[0].project(axis));

	// Just ensuring that full length of shape is projected onto axis
	for (int i = 1; i < sizeof(corners) / sizeof(Vec2D); i++){
		if (corners[i].project(axis) < min) min = corners[i].project(axis);
		if (corners[i].project(axis) > max) max = corners[i].project(axis);
	}

	return LineSeg(min, max);
}

bool Square::collision_check(const Shape& s) const{

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

Vec2D Square::get_nearest(const Vec2D point) const{
	// Find nearest point to centre of other shape
	Vec2D np = (point - centre);
	// If point is outside shape
	if (fabs(np.get_x()) >= width / 2 || fabs(np.get_y()) >= height / 2){
	// Define vector between two centres and then bound by square width and height
		if (np.get_x() > width / 2) np.set_x(width/2);
		else if (np.get_x() < -width / 2) np.set_x(-width/2);
		if (np.get_y() > height / 2) np.set_y(height/2);
		else if (np.get_y() < -height / 2) np.set_y(-height/2);
	} else {
		float costheta = np.normalise().dot(Vec2D(1, 0));
		if (costheta > 1 / sqrt(2)) np.set_x(width /2);
		else if (costheta < -1 / sqrt(2)) np.set_x(-width / 2);
		else{
			if (np.get_y() > 0) np.set_y(height / 2);
			else np.set_y(-height / 2);
		}
	}
	return np + centre;
	
}

bool Square::isVertex(const Vec2D& point) const{
	if ((point.get_x() == centre.get_x() - width/2 || point.get_x() == centre.get_x() + width/2)
		&& (point.get_y() == centre.get_y() - height/2 || point.get_y() == centre.get_y() + height/2))
		return true;
	return false;
}

Vec2D Square::nudge(const Shape& s) const{
	if (!collision(*this, s)) return Vec2D(0, 0);
	Vec2D xaxis = Vec2D(1, 0), yaxis = Vec2D(0, 1);
	if (angle != 0){
		xaxis.rotate(angle);
		yaxis.rotate(angle);
	}

	LineSeg sqpx = project(xaxis), spx = s.project(xaxis);
	LineSeg sqpy = project(yaxis), spy = s.project(yaxis);
	
	Vec2D nv1 = sqpx.nudgeVec(spx), nv2 = sqpy.nudgeVec(spy);
	return (nv1.magnitude() < nv2.magnitude())? nv1 : nv2;
}
