// TourCpp_Templates_Buffer.cpp : Defines the entry point for the console application.
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

  return 0;
}

