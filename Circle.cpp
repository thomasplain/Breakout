#include "Circle.h"

LineSeg Circle::project(const Vec2D& axis) const{
	Vec2D cp = centre.project(axis);
	Vec2D cmin = cp - axis.normalise() * radius;
	Vec2D cmax = cp + axis.normalise() * radius;
	return LineSeg(cmin, cmax);
}

bool Circle::collision_check(const Shape& s) const{
	// Axes of separation, x and y are defaults
	Vec2D xaxis(1, 0), yaxis(0, 1);
	if (!s.project(xaxis).overlap(project(xaxis))) return false;
	if (!s.project(yaxis).overlap(project(yaxis))) return false;
	if (s.isVertex(s.get_nearest(centre))){
		Vec2D newAxis = centre - s.get_nearest(centre);
		if (!s.project(newAxis).overlap(project(newAxis))) return false;
	}
	return true;
}

bool Circle::isVertex(const Vec2D& v) const{
	if ((v-centre).magnitude() == radius) return true;
	return false;
}

Vec2D Circle::nudge(const Shape& s) const{
	if (!collision(*this, s)) return Vec2D(0, 0);
	Vec2D xaxis(1, 0), yaxis(0, 1), naxis = (centre - s.get_nearest(centre)).normalise();
	LineSeg cx = project(xaxis), cy = project(yaxis), cn = project(naxis);
	LineSeg sx = s.project(xaxis), sy = s.project(yaxis), sn = s.project(naxis);
	Vec2D nv1 = cx.nudgeVec(sx), nv2 = cy.nudgeVec(sy), nv3 = cn.nudgeVec(sn);
	return (nv1.magnitude() < nv2.magnitude())? ((nv1.magnitude() < nv3.magnitude())? nv1 : nv3) : ((nv2.magnitude() < nv3.magnitude())? nv2 : nv3);
}

Vec2D Circle::get_nearest(const Vec2D point) const{
	Vec2D dir = (point - centre).normalise();
	Vec2D oncircle = dir * radius;
	return oncircle + centre;
}
