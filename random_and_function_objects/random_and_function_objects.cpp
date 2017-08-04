// random_and_function_objects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct uniform_dist_int_rnd {
	

	uniform_dist_int_rnd() : d(), gen(e()) {
		rnd = std::bind(d, gen); // a copy of e is stored in rnd
	}

	uniform_dist_int_rnd(int min, int max) : d( min, max ), gen(e()) {
		rnd = std::bind(d, gen); // a copy of e is stored in rnd
	}

	void range(int min, int max) {
		std::uniform_int_distribution<>::param_type dis_params(min, max);
		d.param(dis_params);
		rnd = std::bind(d, gen);
	}

	int operator()() const 
	{ 
		return rnd(); 
		//return d(gen);
	} // call operator
	
	std::default_random_engine e;
	std::mt19937 gen;
	std::uniform_int_distribution<> d;
	std::function<int()> rnd;

};

int main()
{


	// common use case: binding a RNG with a distribution
	std::cout << "\nSimple random int generation between 0 and 10 \n";
	std::default_random_engine e;
	std::mt19937 gen(e());
	std::uniform_int_distribution<> d(0, 10);
	std::uniform_int_distribution<>::param_type dis_params;
	std::function<int()> rnd = std::bind(d, gen); // a copy of e is stored in rnd

	for (int n = 0; n<10; ++n)
		std::cout << rnd() << ' ';
		//std::cout << d(gen) << ' ';
	std::cout << '\n';

	/* le changement du min at max pour la distribution ne marche pas */
	std::cout << "\nTry to change random range to 500 to 1500 \n";
	dis_params._Min = 500;
	dis_params._Max = 1500;
	d.param(dis_params);
	rnd = std::bind(d, gen);

	for (int n = 0; n<10; ++n)
		std::cout << rnd() << ' ';
		//std::cout << d(gen) << ' ';
	std::cout << '\n';


	std::cout << "\nUse a object function int random generator range 10 to 20 \n";

	uniform_dist_int_rnd int_rnd_gen(10,20);

	for (int n = 0; n<10; ++n)
		//std::cout << int_rnd_gen.rnd() << ' ';
		std::cout << int_rnd_gen() << ' ';
	std::cout << '\n';


	std::cout << "\nUse a object function int random generator to fill (generate) a vector<int> \n";

	std::vector<int> vi1(50);

	std::generate( vi1.begin(), vi1.end(), int_rnd_gen);

	for (auto& x : vi1)
		std::cout << x << " ";
	std::cout << "\n";

	std::cout << "\nChange object function int random generator range to [-100,100] \n";

	int_rnd_gen.range(-100, 100 );

	std::generate(vi1.begin(), vi1.end(), int_rnd_gen);

	for (auto& x : vi1)
		std::cout << x << " ";
	std::cout << "\n";

	
	

    return 0;
}

