#include "Vec2D.h"
#include "Vec2DFactory.h"
#include <iostream>

using namespace std;

int main(){
//	Vec2D v(1, 0);
	Vec2DFactory v2f;
	IVec* v = v2f.createVec(1, 0);
	IVec* pi = v2f.createVec(v);
//	IVec* pi = &v;
	cout << *pi;

cout << "Testing set functions" << endl;
pi->set_x(3); pi->set_y(4);
cout << *pi;

cout << "Testing normalise and magnitude" << endl;
Vec2D normalised(pi->normalise());
cout << normalised;
cout << "Length of normlised is " << normalised.magnitude() << endl;

cout << "Finding nemo" << endl;
cout << normalised.normal();

cout << "Finding dot product" << endl;
cout << normalised.dot(Vec2D(1, 1)) << endl;
cout << normalised.dot(Vec2D(1, 2)) << endl;
cout << normalised.dot(Vec2D(3,4)) << endl;

cout << "Testing project() by projecting (3, 4) on x and y axes" << endl;
Vec2D xaxis(1, 0);
Vec2D yaxis(0, 1);

cout << xaxis.normalise() * pi->project(xaxis);
cout << yaxis.normalise() * pi->project(yaxis);

cout << "Testing *, +  and - operators with (1, 1) and (2, 3)" << endl;
cout << Vec2D(1, 1) * Vec2D(2, 3);
cout << Vec2D(1, 1) + Vec2D(2, 3);
cout << Vec2D(1, 1) - Vec2D(2, 3);
		
cout << "Testing *=, +=  and -= operators with (1, 1) and *pi" << endl;
cout << "*pi:" << endl << *pi;
*pi *= Vec2D(1, 1);
cout << "*pi:" << endl << *pi;
*pi += Vec2D(1, 1);
cout << "*pi:" << endl << *pi;
*pi -= Vec2D(1, 1);
cout << "*pi:" << endl << *pi;

cout << "Testing above operators with *pi as second argument" << endl;
*pi *= (*pi);
cout << "*pi:" << endl << *pi;
*pi += (*pi);
cout << "*pi:" << endl << *pi;
*pi -= (*pi);
cout << "*pi:" << endl << *pi;

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
