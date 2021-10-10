#pragma once
#include <iostream>
#include <string>
#include <complex>
template <class T>
class vector {
private:
	size_t capacity;
	size_t size;
	size_t grow_size;
	T* v;
public:
	vector(); //constrictopn
	vector(const size_t size);// CONSTRUCTION PARAM
	vector(const vector& vec); // ConstructorCopy
	size_t GetSize() const; //GetSize
	T& operator[] (const size_t index); //OperatorSqBrackets
	T operator[] (const size_t index) const; // SquareBrackets
	vector operator+= (const vector& vec); // OperatorPlusEqual
	vector operator+ (const vector& vec); //OperatorPlus
	vector& operator= (const vector& vec); //OperatorEqual
	vector operator- (const vector& vec); // OperatorMinus
	vector operator-= (const vector& vec); //OperatorMinusEqual
	vector<T> operator*= (const vector<T>& vec) {  //OperatorMulltipliedEqualVector
		for (size_t i = 0; i < size; ++i) {
			v[i] = v[i] * vec.v[i];
		}
		return *this;
	}
	vector<T> operator*= (const T x) {   //OperatorMulltipliedEqualNumber
		for (size_t i = 0; i < size; ++i) {
			v[i] *= x;
		}
		return *this;
	}
	vector<T> operator* (const T x) {  // OperatorMultipliedbyNumberReturnNew
		vector<T> Newbie = *this;
		Newbie *= x;
		return Newbie;
	}
	vector operator/= (const T x); // OperatorDivideEqual
	vector operator/ (const T x); // OperatorDivide
	bool operator== (const vector& vec); //OperatorIsEqual
	bool operator!= (const vector& vec); // OperatorNotEqual
	void Erase(const size_t index); //MethodErase
	void PushBack(const T& data);  //MethodPushBack
	~vector();
	T operator* (const vector<T>& vec1)
	{
		if (vec1.GetSize() != (*this).GetSize()) throw("Difference between sizes");
		size_t size = vec1.GetSize();
		T result = 0;
		for (size_t i = 0; i < size; ++i) {
			result += vec1.v[i] * v[i];
		}
		return result;
	}
	std::complex<T> operator* (const vector<std::complex<T>>& vec1)
	{
		if (vec1.GetSize() != (*this).GetSize()) throw("Difference between sizes");
		size_t size = vec1.GetSize();
		std::complex<T> result = 0;
		for (size_t i = 0; i < size; ++i) {
			result += std::complex<T>(vec1[i].real() * v[i].real(), vec1[i].imag() * v[i].imag() * (-1));
		}
		return result;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const vector<T>& v);
#include "Vector.inl"
