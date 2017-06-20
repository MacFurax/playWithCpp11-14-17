// meta_programming_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// Factorial
template <int N> struct Factorial {
	static const int result = N * Factorial<N - 1>::result;
};

template <> struct Factorial<0> {
	static const int result = 1;
};


// Fraction
template <int N, int D> struct Frak {
	static const long Num = N;
	static const long Den = D;
};

template <int N, typename F> struct ScalarMultiplication {
	typedef Frak<N*F::Num, N*F::Den> result;
};


template <int X, int Y>   struct MCD {
	static const long result = MCD<Y, X % Y>::result;
};

template <int X> struct MCD<X, 0> {
	static const long result = X;
};

template <class F> struct Simpl {
	static const long mcd = MCD<F::Num, F::Den>::result;
	typedef Frak< F::Num / mcd, F::Den / mcd > result;
};

int main()
{	
	// Factorial
	std::cout << Factorial<5>::result << "\n";

	// Fraction
	typedef Frak< 2, 3 > Two_Thirds;
	typedef ScalarMultiplication< 2, Two_Thirds >::result Four_Sixths;
	std::cout << Four_Sixths::Num << "/" << Four_Sixths::Den << "\n";

	typedef Simpl<Four_Sixths>::result simplyfied;
	std::cout << "Simplification of " << Four_Sixths::Num << "/" << Four_Sixths::Den << " is " << simplyfied::Num << "/" << simplyfied::Den << "\n";

    return 0;
}

