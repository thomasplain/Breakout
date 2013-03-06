#include "LineSeg.h"
#include "Vec2D.h"

bool LineSeg::overlap(LineSeg l){
	if (!sameLine(l)) return false;
	if (end > l.start) return true;
	if (start < l.end) return true;
	return false;
}

Vec2D LineSeg::shuntdist(LineSeg l){
	if (!overlap(l)) return Vec2D(0, 0);
	if (start < l.end) return Vec2D(l.end - start);
	return Vec2D(l.start - end);
}

// Include factory pointer in class? Seem to use it a lot.
bool LineSeg::sameLine(LineSeg l){
	Vec2D thisgradient((end - start).normalise());
	Vec2D lgradient((l.end - l.start).normalise());
	// If lines don't have same gradient, they cannot be equal
	if (thisgradient != lgradient) return false;
	// Lines are potentially colinear, check
	if (thisgradient != (l.start - start).normalise()
		&& thisgradient != (start - l.start).normalise()) return false;
	return true;
}
