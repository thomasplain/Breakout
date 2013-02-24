#ifndef LINESEG_H
#define LINESEG_H

#include "ILine.h"
#include "IVec.h"
#include "VecFactory.h"

class LineSeg : public ILine {
	protected:
		IVec *start, *end;
	public:
		LineSeg(IVec *v1, IVec* v2){
			start = ((*v1) <= (*v2)) ? v1 : v2;
			end = ((*v1) <= (*v2)) ? v2 : v1;
		}
		LineSeg(const ILine& l, VecFactory* vf){
			start = vf->createVec(l.get_start());
			end = vf->createVec(l.get_end());
		}
		virtual IVec* get_start() const{
			return start;
		}

		virtual IVec* get_end() const{
			return end;
		}

		virtual bool overlap(ILine* l);
		virtual IVec* shuntdist(ILine* l, VecFactory* vf);
		virtual bool sameLine(ILine* l);
};
#endif
