#include "Circle.h"

LineSeg Circle::project(const Vec2D& axis){
	Vec2D cp = centre.project(axis);
	Vec2D cmin = cp - axis.normalise() * radius;
	Vec2D cmax = cp + axis.normalise() * radius;
	return LineSeg(cmin, cmax);
}

bool Circle::collision_check(Shape& s){
	// Axes of separation, x and y are defaults
	Vec2D xaxis(1, 0), yaxis(0, 1);
	if (!s.project(xaxis).overlap(project(xaxis))) return false;
	if (!s.project(yaxis).overlap(project(yaxis))) return false;
//	if (s.isVertex(s.get_nearest(centre))){
//		Vec2D newAxis = centre - s.get_nearest(centre);
//		if (!s.project(newAxis).overlap(project(newAxis))) return false;
//	}
	return true;
}

bool Circle::isVertex(const Vec2D& v){
	if ((v-centre).magnitude() == radius) return true;
	return false;
}

Vec2D Circle::get_nearest(Vec2D point){
	Vec2D dir = (point - centre).normalise();
	Vec2D oncircle = dir * radius;
	return oncircle + centre;
}
