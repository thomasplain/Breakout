#include "LineSeg.h"
#include "Vec2D.h"

bool LineSeg::overlap(const LineSeg& l) const{
	if (!sameLine(l)) return false;
	if (end >= l.start && start <= l.start) return true;
	if (start <= l.end && end >= l.end) return true;
	if (start >= l.start && end <= l.end) return true;
	if (start <= l.start && end >= l.end) return true;
	return false;
}

Vec2D LineSeg::shuntdist(LineSeg l){
	if (!overlap(l)) return Vec2D(0, 0);
	if (start < l.end) return Vec2D(l.end - start);
	return Vec2D(l.start - end);
}

// Include factory pointer in class? Seem to use it a lot.
bool LineSeg::sameLine(const LineSeg& l) const{
	Vec2D thisgradient((end - start).normalise());
	Vec2D lgradient((l.end - l.start).normalise());
	// If lines don't have same gradient, they cannot be equal
//	if (thisgradient - lgradient > 0.01 || thisgradient - lgradient < -0.01) return false;
	if (!withinBounds(thisgradient, lgradient, 0.01)) return false;
	// Lines are potentially colinear, check
	if (!withinBounds(thisgradient, (l.start - start).normalise(), 0.01)
		&& !withinBounds(thisgradient, (start - l.start).normalise(), 0.01)) return false;
	return true;
}

Vec2D LineSeg::nudgeVec(const LineSeg& l) const{
	if (!overlap(l)) return Vec2D(0, 0);
	return ((start - l.end).magnitude() < (end - l.start).magnitude())? l.end - start : l.start - end;
}

std::ostream& operator<<(std::ostream& o, const LineSeg& l){
	o << "Start: " << std::endl << l.start;
	o << "End: " << std::endl << l.end << std::endl;
	return o;
}

bool withinBounds(const Vec2D& v1, const Vec2D& v2, const float& param){
	if (((v1 - v2).get_x() > param || (v1 - v2).get_x() < -param) ||
		((v1 - v2).get_y() > param || (v1 - v2).get_y() < -param)) return false;
	return true;
}
