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
Vec2D normalised = *pi;
cout << normalised;
normalised = normalised.normalise();
cout << normalised;
cout << "Length of normlised is " << normalised.magnitude() << endl;

//IVec& normal();
cout << "Finding nemo" << endl;
cout << normalised.normal();
//float dot(IVec& v);
cout << "Finding dot product" << endl;
Vec2D temp(1, 1);
cout << normalised.dot(temp) << endl;
temp = Vec2D(1, 2);
cout << normalised.dot(temp) << endl;
temp = Vec2D(3, 4);
cout << normalised.dot(temp) << endl;

//IVec& project(IVec& axis);
cout << "Testing project() by projecting (3, 4) on x and y axes" << endl;
Vec2D xaxis(1, 0);
Vec2D yaxis(0, 1);

// Assignment is causing trouble once it reaches the copy constructor
pi->project(xaxis);
//cout << temp << endl;
//cout << pi->project(xaxis) << endl;
//cout << pi->project(yaxis) << endl;

//IVec& operator*(IVec& v1);
//IVec& operator+(IVec& v1);
//IVec& operator-(IVec& v1);
		
//IVec& operator*=(IVec& v1);
//IVec& operator+=(IVec& v1);
//IVec& operator-=(IVec& v1);	

return 0;
}
