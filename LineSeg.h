#ifndef LINESEG_H
#define LINESEG_H

#include "Vec2D.h"

class LineSeg{
	protected:
		Vec2D start, end;
	public:
		LineSeg(Vec2D v1, Vec2D v2){
			start = (v1 <= v2) ? v1 : v2;
			end = (v1 <= v2) ? v2 : v1;
		}

		LineSeg(const LineSeg& l){
			start = l.start;
			end = l.end;
		}

		Vec2D get_start() const{
			return start;
		}

		Vec2D get_end() const{
			return end;
		}

		bool overlap(LineSeg l);
		Vec2D shuntdist(LineSeg l);
		bool sameLine(LineSeg l);
};
#endif
