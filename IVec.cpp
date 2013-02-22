#include "IVec.h"

using namespace std;

ostream& operator<<(ostream& o, const IVec& v){
	o << "x = " << v.get_x() << endl;
	o << "y = " << v.get_y() << endl;

	return o;
}

// Determines which quadrant in the Cartesian plane the vector is in
// Makes it a buttload easier to sort them when implementing logical operators
// Quadrants numbered:
//     |
//  2  |  3
//------------
//  0  |  1
//     |
int find_quadrant(const IVec* v){
	bool negy = v->get_y() <= 0;
	bool negx = v->get_x() <= 0;
	if (negy){
		if (negx) return 0;
		return 1;
	}else{
		if (negx) return 2;
		return 3;
	}
}
