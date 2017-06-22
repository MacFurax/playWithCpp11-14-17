// static_assert_and_type_traits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <type_traits>  
#include <iosfwd> 
#include <iostream>

template <typename T, size_t Size>
class Vector
{
	static_assert( Size > 3, "Size is too small");
	T _points[Size];
};

template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
	static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
	static_assert(std::is_integral<T2>::value, "Type T2 must be integral");

	return t1 + t2;
}


int main()
{
	Vector<int, 16> a1;
	Vector<double, 4> a2;

	//std::cout << add(1, 3.14) << std::endl;
	//std::cout << add("one", 2) << std::endl;
	std::cout << add(15, 2) << std::endl;

    return 0;
}

