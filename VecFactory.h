#ifndef VECFACTORY_H
#define VECFACTORY_H

#include "IVec.h"

class VecFactory{
	public:
		virtual IVec* createVec(float ff, float gg) = 0;
		virtual IVec* createVec(const IVec* v) = 0;
};
#endif //VECFACTORY_H
