// unique_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <cassert>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <functional>

struct B {
	virtual void bar() { std::cout << "B::bar\n"; }
	virtual ~B() = default;
};

struct D : B
{
	D() { std::cout << "D::D\n"; }
	~D() { std::cout << "D::~D\n"; }
	void bar() override { std::cout << "D::bar\n"; }
};

// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
	p->bar();
	return p;
}

struct Foo {
	Foo(std::string _id) { mId = _id;  std::cout << "Foo : " << mId << "\n"; }
	~Foo() { std::cout << "~Foo : " << mId << "\n"; }
	std::string mId;
};

class Bar {
public:
	//std::unique_ptr<Foo> f(new Foo("Bar"));

	std::unique_ptr<Foo> f = std::make_unique<Foo>("Bar");

	Bar() {
		//f = std::make_unique<Foo>("Bar");
	}
};

// -----------------------------------------------------------------------
int main()
// -----------------------------------------------------------------------
{

	std::unique_ptr<Foo> p1;
	Bar bar;

	{
		std::cout << "Creating new Foo...\n";
		std::unique_ptr<Foo> p2(new Foo("p2"));
		std::unique_ptr<Foo> p3(new Foo("p3"));
		// p1 = p2; // Error ! can't copy unique_ptr
		p1 = std::move(p2); // this is moving th ownership from p2 to P1
		std::cout << "About to leave inner block...\n";

		// Foo instance will continue to live, 
		// despite p2 going out of scope
	}




	std::cout << "unique ownership semantics demo\n";
	{
		auto p = std::make_unique<D>(); // p is a unique_ptr that owns a D
		auto q = pass_through(std::move(p));
		
		assert(!p); // now p owns nothing and holds a null pointer
		q->bar();   // and q owns the D object
	} // ~D called here




	std::cout << "Runtime polymorphism demo\n";
	{
		std::unique_ptr<B> p = std::make_unique<D>(); // p is a unique_ptr that owns a D
													  // as a pointer to base
		p->bar(); // virtual dispatch

		std::vector<std::unique_ptr<B>> v;  // unique_ptr can be stored in a container
		v.push_back(std::make_unique<D>());
		v.push_back(std::move(p));
		v.emplace_back(new D);
		for (auto& p : v) p->bar(); // virtual dispatch
	} // ~D called 3 times




	std::cout << "Custom deleter demo\n";
	std::ofstream("demo.txt") << 'x'; // prepare the file to read
	{
		std::unique_ptr<std::FILE, decltype(&std::fclose)> fp(std::fopen("demo.txt", "r"),
			&std::fclose);
		if (fp) // fopen could have failed; in which case fp holds a null pointer
			std::cout << (char)std::fgetc(fp.get()) << '\n';
	} // fclose() called here, but only if FILE* is not a null pointer
	  // (that is, if fopen succeeded)



	std::cout << "Custom lambda-expression deleter demo\n";
	{
		std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr)
		{
			std::cout << "destroying from a custom deleter...\n";
			delete ptr;
		});  // p owns D
		p->bar();
	} // the lambda above is called and D is destroyed




	std::cout << "Array form of unique_ptr demo\n";
	{
		std::unique_ptr<D[]> p{ new D[3] };
	} // calls ~D 3 times

	std::cout << "About to leave program...\n";



    return 0;
}

