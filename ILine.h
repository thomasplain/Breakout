#ifndef ILINE_H
#define ILINE_H

#include "IVec.h"
#include "VecFactory.h"

class ILine{
	public:
		virtual IVec* get_start() const = 0;
		virtual IVec* get_end() const = 0;
		
		// Tests whether line overlaps with another
		virtual bool overlap(ILine* l) = 0;
		// Returns distance line must be shunted to remove overlap
		virtual IVec* shuntdist(ILine* l, VecFactory* vf) = 0;
};

#endif // ILINE_H
