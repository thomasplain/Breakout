#ifndef VEC2DFACTORY_H
#define VEC2DFACTORY_H

#include "VecFactory.h"

class Vec2DFactory : public VecFactory{
	public:
		IVec* createVec(float ff, float gg);
		IVec* createVec(IVec* v);
};
#endif //VEC2DFACTORY_H
