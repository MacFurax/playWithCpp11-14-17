#include <iostream>
#include <chrono>

int main()
{
	std::chrono::milliseconds msTime{3400};
	std::chrono::seconds sTime;
	std::chrono::duration<double, std::ratio<1, 1>> sDoubleTime;

	sTime = std::chrono::duration_cast<std::chrono::seconds>(msTime); // cast milliscondes for seconds loosing inforation, the 0.4 seconds are lost
	sDoubleTime = msTime; // convert milliseconds to seconds in float, so keep infromaiton below seconds

	std::cout << "duration in sec[int] : " << sTime.count() << std::endl;
	std::cout << "duration in sec[double] : " << sDoubleTime.count() << std::endl;

	std::cout << "is dur sec[int] less then sec[double] " << ( sTime < sDoubleTime ?"yes":"no") << std::endl;

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	start = std::chrono::steady_clock::now();
	sTime = std::chrono::seconds{1};
	int x = 0;
	
	while (std::chrono::steady_clock::now() < start + sTime) {
		x++;
	}
	end = std::chrono::steady_clock::now();
	sDoubleTime = end - start;

	std::cout << "loop took " << sDoubleTime.count() << " sec, loop runs " << x << " times" << std::endl;

	return 0;
}