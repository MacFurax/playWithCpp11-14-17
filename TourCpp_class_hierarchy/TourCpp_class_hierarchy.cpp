// TourCpp_class_hierarchy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class Point {
public:
	Point() : x{ 0 }, y{0} {}
	float x;
	float y;
};

class Shape {
public:
	virtual Point center() const = 0;
	virtual void move(Point to) = 0;

	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;

	virtual ~Shape() { cout << "~Shape\n"; }
};


class Circle : public Shape {
public:
	Circle(Point p, int rr) : x{ p }, r{ rr } {}

	Point center() const { return x; }
	void move(Point to) { x = to; }

	void draw() const {}
	void rotate(int a) {}

	~Circle() { cout << "~Circle\n"; }

private:
	Point x;
	int r;
};


int main()
{
	Circle c(Point(), 50);
    return 0;
}

