#include "Vec2D.h"
#include "Vec2DFactory.h"
#include <iostream>

#include <memory>

using namespace std;

int main(){
//	Vec2D v(1, 0);
	Vec2DFactory v2f;
	std::auto_ptr<IVec> v(v2f.createVec(1, 0));
	auto_ptr<IVec> pi(v2f.createVec(v.get()));
//	IVec* pi = &v;
	cout << *pi;

cout << "Testing set functions" << endl;
pi->set_x(3); pi->set_y(4);
cout << *(pi.get());

cout << "Testing normalise and magnitude" << endl;
auto_ptr<IVec> normalised(v2f.createVec(pi->normalise()));
cout << *(normalised.get());
cout << "Length of normlised is " << normalised->magnitude() << endl;

cout << "Finding nemo" << endl;
IVec* n = v2f.createVec(normalised->normal());
cout << *n;
delete n;

cout << "Finding dot product" << endl;
Vec2D* d = new Vec2D(1, 1);
cout << normalised->dot(d) << endl;
d->set_x(1); d->set_y(2);
cout << normalised->dot(d) << endl;
d->set_x(3); d->set_y(4);
cout << normalised->dot(d) << endl;
delete d;

cout << "Testing project() by projecting (3, 4) on x and y axes" << endl;
auto_ptr<Vec2D> xaxis(new Vec2D(1, 0));
auto_ptr<Vec2D> yaxis(new Vec2D(0, 1));

IVec* px = v2f.createVec(pi->project(xaxis.get()));
cout << *px;
delete px;
IVec* py = v2f.createVec(pi->project(yaxis.get()));
cout << *py;
delete py;
//cout << xaxis->normalise() * pi->project(xaxis);
//cout << yaxis->normalise() * pi->project(yaxis);

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
