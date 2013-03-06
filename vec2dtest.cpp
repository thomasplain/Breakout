#include "Vec2D.h"
#include <iostream>

using namespace std;

int main(){
	Vec2D v(1, 0);

cout << "Testing set functions" << endl;
v.set_x(3); v.set_y(4);
cout << v;

cout << "Testing normalise and magnitude" << endl;
Vec2D normalised = v.normalise();
cout << normalised;
cout << "Length of normlised is " << normalised.magnitude() << endl;

cout << "Finding nemo" << endl;
cout << normalised.normal();

cout << "Finding dot product" << endl;
cout << normalised.dot(Vec2D(1, 1)) << endl;
cout << normalised.dot(Vec2D(1, 2)) << endl;
cout << normalised.dot(Vec2D(3, 4)) << endl;

cout << "Testing project() by projecting (3, 4) on x and y axes" << endl;
Vec2D xaxis(1, 0);
Vec2D yaxis(0, 1);

cout << v.project(xaxis);
cout << v.project(yaxis);

cout << "Testing *, +  and - operators with (1, 1) and (2, 3)" << endl;
cout << Vec2D(1, 1) * Vec2D(2, 3);
cout << Vec2D(1, 1) + Vec2D(2, 3);
cout << Vec2D(1, 1) - Vec2D(2, 3);
		
cout << "Testing *=, +=  and -= operators with (1, 1) and v" << endl;
cout << "v" << endl << v;
v *= Vec2D(1, 1);
cout << "v:" << endl << v;
v += Vec2D(1, 1);
cout << "v:" << endl << v;
v -= Vec2D(1, 1);
cout << "v:" << endl << v;

cout << "Testing above operators with v as second argument" << endl;
v *= (v);
cout << "v:" << endl << v;
v += (v);
cout << "v:" << endl << v;
v -= (v);
cout << "v:" << endl << v;

cout << "Testing logical operators 1010011111" << endl;
cout << (Vec2D(2, 2) > Vec2D(1, 1)) << endl;
cout << (Vec2D(2, 2) < Vec2D(1, 1)) << endl;
cout << (Vec2D(2, 2) >= Vec2D(1, 1)) << endl;
cout << (Vec2D(2, 2) <= Vec2D(1, 1)) << endl;
cout << (Vec2D(2, 2) == Vec2D(1, 1)) << endl;
cout << (Vec2D(2, 2) != Vec2D(1, 1)) << endl;
cout << (Vec2D(-1, -1) < Vec2D(1, -1)) << endl;
cout << (Vec2D(1, -1) < Vec2D(-1, 1)) << endl;
cout << (Vec2D(-1, 1) < Vec2D(1, 1)) << endl;


return 0;
}
