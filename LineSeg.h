#ifndef LINESEG_H
#define LINESEG_H

#include <algorithm>

#include "ILine.h"
#include "IVec.h"
#include "VecFactory.h"

class LineSeg : public ILine {
	protected:
		IVec* start, end;
	public:
		LineSeg(IVec *v1, IVec* v2){
			start = ((*v1) <= (*v2)) ? v1 : v2;
			end = ((*v1) <= (*v2)) ? v2 : v1;
		}
		LineSeg(const ILine&, VecFactory* f){
			start = f->createVec(ILine.get_start());
			end = f->createVec(ILine.get_end());
		}
	virtual bool overlap(ILine* l);
	virtual float shuntdist(ILine* l);
};

#endif
