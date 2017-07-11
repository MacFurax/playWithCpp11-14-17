// TourCpp_class_copy_and_move.cpp : Defines the entry point for the console application.
//

// A Tour of C++ 
//
// Code to experiment with A Tour of C++ Book from Bjarne Stroustrup
//
// §4.6 Classes Copy and Move
//
// CAUTION: the move constructor and move assignment look's to work only with at least C++14
//

#include "stdafx.h"

using namespace std;


class Vector {
private:
	double *elem;
	int sz;
  string name;

public:
  Vector(int s) : elem{ new double[s] }, sz{ s }, name{"NONE"}
	{
		for (int i = 0; i != s; ++i)
			elem[i] = 0;
	}

  Vector(int s, string pname) : Vector(s)
  {
    name = pname;
  }

	~Vector() 
  { 
    cout << "try delete Vector[" << name << "]\n";
    if (!elem)
    {
      cout << "Vector[" << name << "] elem is empty\n";
    } else {
      cout << "delete Vector[" << name << "]\n";
      delete[] elem;
      elem = nullptr;
    }
  }

	double& operator[](int i) 
	{
		if (i < 0 || size() <= i)
			throw exception("Vector out-of-range", 0);
		return elem[i];
	}

	bool operator==(Vector& a) 
	{
		return a.elem == elem;
	}

  // copy constructor
  Vector(const Vector& a) : elem{ new double[a.sz] }, sz{ a.sz }, name{a.name}
	{
    cout << ">> Vector::Vector copy constructor\n";
    for (int i = 0; i != sz; ++i)
      elem[i] = a.elem[i];
	}

  //copy assignment
	Vector& operator=(const Vector& a)
	{
    cout << ">> Vector::operator= copy assigment\n";
    // replace this data be a data
   
    sz = a.sz;
    name += a.name;
    
    double* p = new double[a.sz];
    for (int i = 0; i != a.sz; ++i)
      p[i] = a.elem[i];
    delete[] elem;
    elem = p;

    return *this;
	}

  // move constructor
  Vector(Vector&& a) : elem{ a.elem }, sz{ a.sz }, name{a.name}
  {
    cout << ">> Vector::Vector move (" << a.name << " to " << name << ") constructor\n";
    a.name += "moved";
    a.elem = nullptr;
    a.sz = 0;
  }

  // move assignement
  Vector& operator=(Vector&& a)
  {
    cout << ">> Vector::operator= move ("<< a.name <<" to "<< name <<") assigment\n";
    elem = a.elem;
    sz = a.sz;
    a.name += "moved";
    a.elem = nullptr;
    a.sz = 0;
    return *this;
  }

	int size() const { return sz; }

	void print_info() 
	{
    cout << name << "\n";
		cout << "Size : " << sz << "\n";
		cout << "Adresse : 0x" << hex << elem << dec << "\n";
	}

	void print_info(string vname) 
	{
		cout << "[" << vname << "]\n";
		print_info();
	}

};


//int main()
//{
//	Vector v1(10, "v1");
//	Vector v2(100, "v2");
//	v1.print_info();
//	v2.print_info();
//
//	if (v1 == v2) {
//		cout << "vectors are equals\n";
//	}
//	else {
//		cout << "vectors are NOT equals\n";
//	}
//
//	Vector v3 = v2;
//
//	v3.print_info("v3");
//
//  v2 = v1;
//
//  v2.print_info("v2");
//
//  return 0;
//}

Vector t() {
  Vector x(1000, "x");
  Vector y(1000, "y");
  Vector z(1000, "z");

  z = x;
  y = move(x);
  return z;
}

int main()
{
  Vector r = t();
  r.print_info("r");
  return 0;
}

