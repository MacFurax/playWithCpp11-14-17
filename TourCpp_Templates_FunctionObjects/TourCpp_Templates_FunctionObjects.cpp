// TourCpp_Templates_FunctionObjects.cpp : Defines the entry point for the console application.
//


// 
// preactive play ground base on book Tour of C++
// §5.5 Function Objects 
//

#include "stdafx.h"

using namespace std;

template<typename T>
class Less_than {
  const T val;
public:
  Less_than(const T& v) :val(v) {}
  bool operator()(const T&x) const { return x < val; } // call operator
};

Less_than<int> lti{42};
Less_than<string> lts{"Bachus"};

int main()
{
    return 0;
}

