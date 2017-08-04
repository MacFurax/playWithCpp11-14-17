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

class unif_rand_gen {
  default_random_engine e;  //Will be used to obtain a seed for the random number engine
  uniform_int_distribution<int> dis;

public:
  unif_rand_gen(int min , int max)
  { 
    dis = uniform_int_distribution<int>(min, max);

  }
  int operator()() { return dis->operator(&gen); }
};

template<typename C, typename P>
int count(const C& c, P pred)
{
  int cnt = 0;
  for (const auto& x : c)
    if (pred(x))
      ++cnt;

  return cnt;
}

int main()
{
  Less_than<int> lti{ 42 };
  Less_than<string> lts{ "Bachus" };

  bool b1 = lti(96);
  bool b2 = lts("toto");

  vector<int> vi(50, 6);

  //int cnt = count<vector<int>, Less_than<int>>(vi, lti);
  int cnt = count(vi, lti);
  cout << "Count is " << cnt << "\n";

  cnt = count(vi, Less_than<int>{4});
  cout << "Count is " << cnt << "\n";

  int treshold = 15;
  cnt = count(vi, [&treshold](int a) { return a < treshold; });
  cout << "Count is " << cnt << "\n";

  

  vector<int> vi1(50);
  unif_rand_gen rg(1, 50);
  generate(vi1.begin(), vi1.end(), rg());

  for (int& x : vi1)
    cout << x << " ";
  cout << "\n";

  treshold = 25;
  cnt = count(vi, [&treshold](int a) { return a < treshold; });
  cout << "Count is " << cnt << "\n";


  return 0;
}

