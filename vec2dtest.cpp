#include "Vec2D.h"
#include <iostream>

using namespace std;

int main(){
	Vec2D v(1, 0);
	IVec* pi = &v;
	cout << *pi;

// void set_x(float f);
// void set_y(float f);
cout << "Testing set functions" << endl;
pi->set_x(3); pi->set_y(4);
cout << *pi;

//float magnitude();
//IVec& normalise();
cout << "Testing normalise and magnitude" << endl;
Vec2D normalised(pi->normalise());
cout << normalised;
cout << "Length of normlised is " << normalised.magnitude() << endl;

//IVec& normal();
cout << "Finding nemo" << endl;
cout << normalised.normal();
//float dot(IVec& v);
cout << "Finding dot product" << endl;
cout << normalised.dot(Vec2D(1, 1)) << endl;
cout << normalised.dot(Vec2D(1, 2)) << endl;
cout << normalised.dot(Vec2D(3,4)) << endl;

//IVec& project(IVec& axis);
cout << "Testing project() by projecting (3, 4) on x and y axes" << endl;
Vec2D xaxis(1, 0);
Vec2D yaxis(0, 1);

// Assignment is causing trouble once it reaches the copy constructor
cout << xaxis.normalise() * pi->project(xaxis);
cout << yaxis.normalise() * pi->project(yaxis);

// const IVec& operator*(const IVec& v1);
cout << "Testing *, +  and - operators with (1, 1) and (2, 3)" << endl;
cout << Vec2D(1, 1) * Vec2D(2, 3);
//IVec& operator+(IVec& v1);
cout << Vec2D(1, 1) + Vec2D(2, 3);
//IVec& operator-(IVec& v1);
cout << Vec2D(1, 1) - Vec2D(2, 3);
		
cout << "Testing *=, +=  and -= operators with (1, 1) and *pi" << endl;
cout << "*pi:" << endl << *pi;
//IVec& operator*=(IVec& v1);
*pi *= Vec2D(1, 1);
cout << "*pi:" << endl << *pi;
//IVec& operator+=(IVec& v1);
*pi += Vec2D(1, 1);
cout << "*pi:" << endl << *pi;
//IVec& operator-=(IVec& v1);	
*pi -= Vec2D(1, 1);
cout << "*pi:" << endl << *pi;

*pi *= (*pi);
cout << "*pi:" << endl << *pi;
*pi += (*pi);
cout << "*pi:" << endl << *pi;
*pi -= (*pi);
cout << "*pi:" << endl << *pi;

return 0;
}
