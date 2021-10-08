// Lab2.cpp : Defines the entry point for the application.
//

#include "Vector.h"
#include "Vector.cpp"
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <complex>

bool StrToLong(const std::string str, long int* value)
{
	char* endptr = NULL;
	*value = strtol(str.c_str(), &endptr, 0);
	if (endptr == str)return false;
	if ((*value == LONG_MIN || *value == LONG_MAX) && errno == ERANGE) return false;
	if (*endptr != str[strlen(str.c_str())]) return false;
	return true;
}
bool StrToLong(const std::string str, double* value)
{
	char* endptr = NULL;
	*value = strtod(str.c_str(), &endptr);
	if (endptr == str) return false;
	if (errno == ERANGE) return false;
	if (*endptr != str[strlen(str.c_str())]) return false;
	return true;
}
long int Number_needed(const long int left_border, const long int right_border, const std::string condition)
{
	std::cout << "\n" << condition;
	long int dif = 0;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (StrToLong(str, &dif) == 1) break;
		else
		{
			std::cout << "Wrong input, try again\n";
		}
	}
	while (true)
	{
		if (dif >= left_border && dif <= right_border) return dif;
		else
		{
			std::cout << "\nWrong input, try again: " << condition;
			while (true)
			{
				std::cin >> str;
				if (StrToLong(str, &dif) == 1) break;
				else
				{
					std::cout << "Wrong input, try again\n";
				}
			}
		}
	}
}
double Number_needed(const std::string condition)
{
	std::cout << "\n" << condition;
	double dif = 0;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (StrToLong(str, &dif) == 1) break;
		else
		{
			std::cout << "Wrong input, try again\n";
		}
	}
	return dif;
}
void PrintChoices()
{
	std::cout << "  Press 1 - work with first vector\n  Press 2 - work with second vector\n  Press 3 - Vector addition\n";
	std::cout << "  Press 4 - Vector difference\n  Press 5 - Scalar product of these vectors\n  Press 6 - vectors are equal?\n  Press 0 - for exit programm";
}
void PrintChoicesAdditional()
{
	std::cout << "  Press 1 - edit element\n  Press 2 - multiply by number\n  Press 3 - divide by number\n";
	std::cout << "  Press 4 - pushabck new element\n  Press 5 - erase element\n";
	std::cout << "  Press 0 - for back in menu";
}

void PrintCreate()
{
	std::cout << " Press 1 - edit int vector\n Press 2 - edit double vector\n Press 3 - edit float vector\n Press 4 - edit complex<float> vector\n";
	std::cout << " Press 5 - edit complex double vector\n Press 0 - exit";
}

int main()
{
	/*vector <std::complex<float>> a(3);
	std::complex<float> number(2, 2);
	a.PushBack(number);
	std::cout << a;*/
	vector<int> a_int(2);
	vector<int> b_int(2);
	vector<double> a_double(2);
	vector<double> b_double(2);
	vector<float> a_float(2);
	vector<float> b_float(2);
	vector<std::complex<double>> a_cd(2);
	vector<std::complex<double>> b_cd(2);		
	vector<std::complex<float>> a_cf(2);
	vector<std::complex<float>> b_cf(2);
	bool work = false;
}


