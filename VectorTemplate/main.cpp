#include "Vector.h"
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
	if (errno == ERANGE) return false;
	if (*endptr != str[strlen(str.c_str())]) return false;
	return true;
}
template <typename RETURN_TYPE>
RETURN_TYPE To_Number(const std::string& str) {
	std::stringstream temp;
	temp << str;
	RETURN_TYPE value;
	temp >> value;
	return value;
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

void PrintChoices()
{
	std::cout << "  Press 1 - work with first vector\n  Press 2 - work with second vector\n  Press 3 - Vector addition\n";
	std::cout << "  Press 4 - Vector difference\n  Press 5 - Scalar product of these vectors\n  Press 6 - vectors are equal?\n Press 7- vector 1 multiply by vector2\n Press 0 - for back to start menu";
}
void PrintChoicesAdditional()
{
	std::cout << "  Press 1 - edit element\n  Press 2 - multiply by number\n  Press 3 - divide by number\n";
	std::cout << "  Press 4 - pushabck new element\n  Press 5 - erase element\n";
	std::cout << "  Press 0 - for back in menu";
}

void PrintStart()
{
	std::cout << " Press 1 - work w/ int vector\n Press 2 - work w/ double vector\n Press 3 - work w/ float vector\n Press 4 - work w/ complex float vector\n";
	std::cout << " Press 5 - work w/ complex double vector\n Press 0 - exit";
}
std::string Input_Number() {
	std::string input;
	bool flag = true;
	while (flag) {
		std::cout << "\nInput your value : ";
		std::cin >> input;
		if (&input == nullptr) {
			std::cout << "Your value is empty, repeat";
			continue;
		}
		for (size_t i = 0; i < input.size(); ++i)
		{
			if (input[i] == '-') continue;
			if (input[i] == '-' && input.size() == 1) {
				std::cout << "\n There is no number in your string or other symbols includes, repeat:";
				break;
			}
			if (int(input[i]) - int('0') >= 0 && int(input[i]) - int('0') <= 9) {
				flag = false;
				break;
			}
			else {
				std::cout << "\n There is no number in your string or other symbols includes, repeat:";
				break;
			}
		}
	}
	return input;
}
template <typename TYPE>
void MenuForTwoVectors(vector<TYPE>& vec1, vector<TYPE> vec2)
{
	bool flag = true;
	while (flag) {
		std::cout << vec1;
		std::cout << vec2;
		PrintChoices();
		long int choice = Number_needed(0, 7, "Enter a number in range 0-7: ");
		switch (choice) {
		case 0: {
			flag = false;
			break;
		}
		case 1: {
			bool work2 = true;
			while (work2)
			{
				system("cls");
				std::cout << "You are working with first vector" << std::endl;
				std::cout << vec1 << std::endl;
				PrintChoicesAdditional();
				long int key2 = Number_needed(0, 5, "Enter a number in range 0-5: ");
				switch (key2)
				{
				case 0: // exit
				{
					work2 = false;
					break;
				}
				case 1: // edit element
				{
					try {
						long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
						index--;
						vec1[index];
						TYPE value = To_Number<TYPE>(Input_Number());
						vec1[index] = value;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2: // multiply by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					vec1 *= value;
					break;
				}
				case 3: // divide by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					try { vec1 /= value; }
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 4: //pushback
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					vec1.PushBack(value);
					break;
				}
				case 5: //erase
				{
					if (vec1.GetSize() != 0)
					{
						try {
							long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
							index--;
							(vec1.begin()._Ptr + index) <= (vec1.end()._Ptr - 1) ? vec1.Erase(vec1.begin() + index) : throw "Cant erase non-exist element";
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							system("pause");
						}
					}
					else
					{
						std::cout << "\nNo more elements\n";
						system("pause");
					}
					break;
				}
				}
			}
			system("cls");
			break;
		}
		case 2: {
			bool work2 = true;
			while (work2)
			{
				system("cls");
				std::cout << "You are working with second vector" << std::endl;
				std::cout << vec2 << std::endl;
				PrintChoicesAdditional();
				long int key2 = Number_needed(0, 5, "Enter a number in range 0-5: ");
				switch (key2)
				{
				case 0: // exit
				{
					work2 = false;
					break;
				}
				case 1: // edit element
				{
					try {
						long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
						index--;
						vec2[index];
						TYPE value = To_Number<TYPE>(Input_Number());
						vec2[index] = value;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2: // multiply by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					vec2 *= value;
					break;
				}
				case 3: // divide by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					try { vec2 /= value; }
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 4: //pushback
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					vec2.PushBack(value);
					break;
				}
				case 5: //erase
				{
					if (vec2.GetSize() != 0) {
						try {
							long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
							index--;
							(vec2.begin()._Ptr + index) <= (vec2.end()._Ptr - 1) ? vec2.Erase(vec2.begin() + index) : throw "Cant erase non-exist element";
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							system("pause");
						}
					}
					else
					{
						std::cout << "\nNo more elements\n";
						system("pause");
					}
					break;
				}
				}
			}
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			try
			{
				vector<TYPE> c = vec1 + vec2;
				std::cout << "vector " << vec1 << "\n+\n" << "vector" << vec2 << "\n =\n " << c;
			}
			catch (const char* err)
			{
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			try {
				vector<TYPE> c = vec1 - vec2;
				std::cout << "vector " << vec1 << "\n-\n" << "vector" << vec2 << "\n = \n" << c;
			}
			catch (const char* err)
			{
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 5: { //scalar
			system("cls");
			try {
				std::cout << "vector " << vec1 << "\n*\n" << "vector" << vec2 << "\n = " << vec1.DotPoint(vec2) << "\n";
			}
			catch (const char* err) {
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 6: // Equals
		{
			system("cls");
			std::string answer = vec1 == vec2 ? "Yes" : "No";
			std::cout << vec1;
			std::cout << vec2;
			std::cout << "vector a  = vector b? - " << answer << "\n";
			system("pause");
			system("cls");
			break;
		}
		case 7: //vector x vector
		{
			system("cls");
			try {
				std::cout << "vector " << vec1 << "\n*\n" << "vector" << vec2 << "\n = \n" << vec1 * vec2 << "\n";
			}
			catch (const char* err) {
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		}
	}
}
template <typename TYPE>
void MenuForTwoVectors(vector<std::complex<TYPE>>& vec1, vector<std::complex<TYPE>> vec2)
{
	bool flag = true;
	while (flag) {
		std::cout << vec1;
		std::cout << vec2;
		PrintChoices();
		long int choice = Number_needed(0, 7, "Enter a number in range 0-7: ");
		switch (choice) {
		case 0: {
			flag = false;
			break;
		}
		case 1: {
			bool work2 = true;
			while (work2)
			{
				system("cls");
				std::cout << "You are working with first vector" << std::endl;
				std::cout << vec1 << std::endl;
				PrintChoicesAdditional();
				long int key2 = Number_needed(0, 5, "Enter a number in range 0-5: ");
				switch (key2)
				{
				case 0: // exit
				{
					work2 = false;
					break;
				}
				case 1: // edit element
				{
					try {
						long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
						index--;
						vec1[index];
						std::cout << "\nInput real part: ";
						TYPE re = To_Number<TYPE>(Input_Number());
						std::cout << "\nInput imag part: ";
						TYPE im = To_Number<TYPE>(Input_Number());
						vec1[index] = std::complex<TYPE>(re, im);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2: // multiply by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					vec1 *= std::complex<TYPE>(value, value);
					break;
				}
				case 3: // divide by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					try { vec1 /= value; }
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 4: //pushback
				{
					std::cout << "\nInput real part: ";
					TYPE re = To_Number<TYPE>(Input_Number());
					std::cout << "\nInput imag part: ";
					TYPE im = To_Number<TYPE>(Input_Number());
					vec1.PushBack(std::complex<TYPE>(re, im));
					break;
				}
				case 5: //erase
				{
					if (vec1.GetSize() != 0)
					{
						try {
							long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
							index--;
							(vec1.begin()._Ptr + index) <= (vec1.end()._Ptr - 1) ? vec1.Erase(vec1.begin() + index) : throw "Cant erase non-exist element";
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							system("pause");
						}
					}
					else
					{
						std::cout << "\nNo more elements\n";
						system("pause");
					}
					break;
				}
				}
			}
			system("cls");
			break;
		}
		case 2: {
			bool work2 = true;
			while (work2)
			{
				system("cls");
				std::cout << "You are working with second vector" << std::endl;
				std::cout << vec2 << std::endl;
				PrintChoicesAdditional();
				long int key2 = Number_needed(0, 5, "Enter a number in range 0-5: ");
				switch (key2)
				{
				case 0: // exit
				{
					work2 = false;
					break;
				}
				case 1: // edit element
				{
					try {
						long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
						index--;
						vec2[index];
						std::cout << "\nInput real part: ";
						TYPE re = To_Number<TYPE>(Input_Number());
						std::cout << "\nInput imag part: ";
						TYPE im = To_Number<TYPE>(Input_Number());
						vec2[index] = std::complex<TYPE>(re, im);
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2: // multiply by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					vec2 *= std::complex<TYPE>(value, value);
					break;
				}
				case 3: // divide by number
				{
					TYPE value = To_Number<TYPE>(Input_Number());
					try { vec2 /= value; }
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 4: //pushback
				{
					std::cout << "\nInput real part: ";
					TYPE re = To_Number<TYPE>(Input_Number());
					std::cout << "\nInput imag part: ";
					TYPE im = To_Number<TYPE>(Input_Number());
					vec2.PushBack(std::complex<TYPE>(re, im));
					break;
				}
				case 5: //erase
				{
					if (vec2.GetSize() != 0) {
						try {
							long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
							index--;
							(vec2.begin()._Ptr + index) <= (vec2.end()._Ptr - 1) ? vec2.Erase(vec2.begin() + index) : throw "Cant erase non-exist element";
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							system("pause");
						}
					}
					else
					{
						std::cout << "\nNo more elements\n";
						system("pause");
					}
					break;
				}
				}
			}
			system("cls");
			break;
		}
		case 3: {
			system("cls");
			try
			{
				vector<std::complex<TYPE>> c = vec1 + vec2;
				std::cout << "vector " << vec1 << "\n+\n" << "vector" << vec2 << "\n =\n " << c;
			}
			catch (const char* err)
			{
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			system("cls");
			try {
				vector<std::complex<TYPE>> c = vec1 - vec2;
				std::cout << "vector " << vec1 << "\n-\n" << "vector" << vec2 << "\n = \n" << c;
			}
			catch (const char* err)
			{
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 5: { // multi vectors
			system("cls");
			try {
				std::cout << "vector " << vec1 << "\n*\n" << "vector" << vec2 << "\n = " << vec1.DotPoint(vec2) << "\n";
			}
			catch (const char* err) {
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 6: // Equals
		{
			system("cls");
			std::string answer = vec1 == vec2 ? "Yes" : "No";
			std::cout << vec1;
			std::cout << vec2;
			std::cout << "vector a  = vector b? - " << answer << "\n";
			system("pause");
			system("cls");
			break;
		}
		case 7: //vector x vector
		{
			system("cls");
			try {
				std::cout << "vector " << vec1 << "\n*\n" << "vector" << vec2 << "\n = \n" << vec1 * vec2 << "\n";
			}
			catch (const char* err) {
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		}
	}
}
int main()
{
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
	bool work = true;
	while (work) {
		system("cls");
		PrintStart();
		long int key = Number_needed(0, 6, "Enter a number in range 0-6: ");
		switch (key) {
		case 0: {
			work = false;
			break;
		} // exit programm
		case 1: {
			system("cls");
			MenuForTwoVectors(a_int, b_int);
			break;
		}
		case 2: {
			system("cls");
			MenuForTwoVectors(a_double, b_double);
			break;
		}
		case 3: {
			system("cls");
			MenuForTwoVectors(a_float, b_float);
			break;
		}
		case 4: {
			system("cls");
			MenuForTwoVectors(a_cf, b_cf);
			break;
		}
		case 5: {
			system("cls");
			MenuForTwoVectors(a_cd, b_cd);
			break;
		}
		}
	}
}