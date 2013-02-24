#include "Vec2DFactory.h"
#include "Vec2D.h"

IVec* Vec2DFactory::createVec(float ff, float gg){
	return new Vec2D(ff, gg);
}

IVec* Vec2DFactory::createVec(const IVec* v){
	return new Vec2D(v->get_x(), v->get_y());
}
