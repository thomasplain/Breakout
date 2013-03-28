#ifndef LINESEG_H
#define LINESEG_H

#include "Vec2D.h"
#include <iostream>

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

		bool overlap(const LineSeg& l) const;
		Vec2D shuntdist(LineSeg l);
		bool sameLine(const LineSeg& l) const;
		Vec2D nudgeVec(const LineSeg& l) const;

		friend std::ostream& operator<<(std::ostream& o, const LineSeg& l);
};

bool withinBounds(const Vec2D& v1, const Vec2D& v2, const float& param);
#endif
