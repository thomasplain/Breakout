#include "IVec.h"

using namespace std;

ostream& operator<<(ostream& o, const IVec& v){
	o << "x = " << v.get_x() << endl;
	o << "y = " << v.get_y() << endl;

	return o;
}
