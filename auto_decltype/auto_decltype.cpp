// auto_decltype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

template<class T, class U>
auto add(T t, U u) -> decltype(t + u) // the return type is the type of operator+(T, U)
{
	return t + u;
}

int main()
{
	auto startIdx = 0;
	auto fadeValue = 0.0f;
	auto indexes = {5,4,9,3,5};

	cout << "Type of startIdx " << typeid(startIdx).name() << endl;
	cout << "Type of fadeValue " << typeid(fadeValue).name() << endl;
	cout << "Type of indexes " << typeid(indexes).name() << endl;

	auto res = add(150, 17.5463f);
	cout << "Type of res " << typeid(res).name() << endl;

	auto my_lambda = [](int x) { return x + 3; };
	cout << "my_lambda: " << my_lambda(5) << '\n';
	cout << "Type of my_lambda " << typeid(my_lambda).name() << endl;

	return 0;
}

