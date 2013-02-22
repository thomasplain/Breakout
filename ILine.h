#ifndef ILINE_H
#define ILINE_H

#include "IVec.h"

class ILine{
	public:
		IVec* get_start();
		IVec* get_end();
		
		// Tests whether line overlaps with another
		bool overlap(ILine* l);
		// Returns distance line must be shunted to remove overlap
		float shuntdist(ILine* l);
}
#endif // ILINE_H
