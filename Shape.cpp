#include "Shape.h"

bool collision_check(Shape& s1, Shape& s2){
	if (!s1.collision_check(s2)) return false;
	if (!s2.collision_check(s1)) return false;
	return true;
}
