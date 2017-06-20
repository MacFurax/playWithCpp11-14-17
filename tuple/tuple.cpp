// tuple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::tuple<double, char, std::string> get_student(int id)
{
	if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
	if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
	if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
	throw std::invalid_argument("id");
}

int main()
{
	auto student0 = get_student(0);
	std::cout << "ID: 0, "
		<< "GPA: " << std::get<0>(student0) << ", "
		<< "grade: " << std::get<1>(student0) << ", "
		<< "name: " << std::get<2>(student0) << '\n';

	double gpa1;
	char grade1;
	std::string name1;
	std::tie(gpa1, grade1, name1) = get_student(1);
	std::cout << "ID: 1, "
		<< "GPA: " << gpa1 << ", "
		<< "grade: " << grade1 << ", "
		<< "name: " << name1 << '\n';

	std::vector<std::tuple<double, char, std::string>> v;

	v.push_back(get_student(0));
	v.push_back(get_student(1));
	v.push_back(get_student(2));

	std::cout << "All before sort : \n";
	for (auto& el : v) {
		//std::cout << std::get<0>(el) << "\n";
		std::tie(gpa1, grade1, name1) = el;
		std::cout << "GPA: " << gpa1 << ", "
			<< "grade: " << grade1 << ", "
			<< "name: " << name1 << '\n';
	}

	auto lSortOnGPA = [](auto &a, auto &b) { return  std::get<0>(a) < std::get<0>(b); };
	auto lSortOnGrade = [](auto &a, auto &b) { return  std::get<1>(a) < std::get<1>(b); };
	auto lSortOnName = [](auto &a, auto &b) { return  std::get<2>(a) < std::get<2>(b); };


	std::cout << "All after sort by GPA : \n";
	std::sort(v.begin(), v.end(), lSortOnGPA);

	for (auto& el : v) {
		std::tie(gpa1, grade1, name1) = el;
		std::cout << "GPA: " << gpa1 << ", "
			<< "grade: " << grade1 << ", "
			<< "name: " << name1 << '\n';
	}

	std::cout << "All after sort by grade : \n";
	std::sort(v.begin(), v.end(), lSortOnGrade);

	for (auto& el : v) {
		std::tie(gpa1, grade1, name1) = el;
		std::cout << "GPA: " << gpa1 << ", "
			<< "grade: " << grade1 << ", "
			<< "name: " << name1 << '\n';
	}

	std::cout << "All after sort by name : \n";
	std::sort(v.begin(), v.end(), lSortOnName);

	for (auto& el : v) {
		std::tie(gpa1, grade1, name1) = el;
		std::cout << "GPA: " << gpa1 << ", "
			<< "grade: " << grade1 << ", "
			<< "name: " << name1 << '\n';
	}

    return 0;
}

