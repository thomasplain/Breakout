#include "ILine.h"
#include "IVec.h"
#include "LineSeg.h"
#include "VecFactory.h"

bool LineSeg::overlap(ILine* l){
	if (!sameLine(l)) return false;
	if (end > l->get_start()) return true;
	if (start < l->get_end()) return true;
	return false;
}

IVec* LineSeg::shuntdist(ILine* l, VecFactory* vf){
	if (!overlap(l)) return false;
	if (*start < *(l->get_end())) return vf->createVec(&(*(l->get_end()) - *start));
	return vf->createVec(&(*(l->get_start()) - *end));
}

// Include factory pointer in class? Seem to use it a lot.
bool LineSeg::sameLine(ILine* l){
	IVec* thisgradient = new Vec2D((*end - *start).normalise());
	IVec* lgradient = (*(l->get_end()) - *(l->get_start())).normalise(); 
	// If lines don't have same gradient, they cannot be equal
	if (thisgradient != lgradient) return false;
	// Lines are potentially colinear, check
	if (thisgradient != (*(l->get_start()) - *start).normalise() 
		&& thisgradient != (*start - *(l->get_start())).normalise()) return false;
	delete thisgradient;
	return true;
}
