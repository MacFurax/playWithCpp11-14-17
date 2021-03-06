// TourCpp_Templates_Buffer.cpp : Defines the entry point for the console application.
//


//
// practice base on Tour of C++ book end of �5.2
// About templated buffer definition
//

#include "stdafx.h"

template <typename T, int N>
struct Buffer {
  using value_type = T;
  constexpr int size() { return N; }
  T data[N];
};

using namespace std;

int main()
{

  Buffer<int, 100> buf;

  cout << "Buf size " << buf.size() << "\n";

  buf.data[0] = 155;

  return 0;
}

