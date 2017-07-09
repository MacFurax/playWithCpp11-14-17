// TourCpp_class_hierarchy.cpp : Defines the entry point for the console application.
//

// A Tour of C++ 
//
// Code to experiment with A Tour of C++ Book from Bjarne Stroustrup
//
// §4.5 Classes Hierarchies
//

#include "stdafx.h"

using namespace std;

// sample from book

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


// simplified version to play with

class Base {
public:
	Base(string n) : name{ n } { cout << "Base [" << name << "]\n"; }
	Base() : Base("CX") {}
	void virtual methodA() = 0;
	void virtual methodB() { cout << "Base::methodB [" << name << "]\n"; }

	~Base() { cout << "~Base [" << name << "]\n"; }

protected:
	string name;
};

class DerivedA : public Base {
public:
	DerivedA(string n) : Base(n) { cout << "DerivedA [" << name << "]\n"; }
	void methodA() { cout << "DerivedA::methodA [" << name << "]\n"; }
	//void methodB() { cout << "DerivedA::methodB [" << name << "]\n"; }

	~DerivedA() { cout << "~DerivedA [" << name << "]\n"; }
};

class DerivedB : public DerivedA {
public:
	DerivedB() : DerivedA("DB") { cout << "DerivedB [" << name << "]\n"; }

	void methodB() { 
		// call ancestors methodB, in this case DerivedA and base are the same, because DevivedA dosn't override methodB
		cout << ">> Call ancestor methods\n\t";
		DerivedA::methodB();
		cout << "\t";
		Base::methodB();
		cout << "DerivedB::methodB [" << name << "]\n"; 
	}

	~DerivedB() { cout << "~DerivedB [" << name << "]\n"; }
};

class DerivedC : public Base {
public:
	DerivedC() {} // should call Base()

	void methodA() { cout << "DerivedC::methodA [" << name << "]\n"; }

};

int main()
{
	//Circle c(Point(), 50);
	DerivedA DA("DA");

	DA.methodA();
	DA.methodB();

	DerivedB DB;

	DB.methodA();
	DB.methodB();

	DerivedC DC;

	DC.methodA();
	DC.methodB();

	cout << ">> Dynamic cast to base* (is it of type base ?) \n";
	Base* b = dynamic_cast<Base*>(&DC);
	if (b)
	{
		cout << "\t";
		b->methodA();
		cout << "\t";
		b->methodB();
	}
	cout << ">> Dynamic cast to base* \n";
		

    return 0;
}

