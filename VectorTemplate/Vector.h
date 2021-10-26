#pragma once
#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <iterator>
template <class T>




class vector {
private:
	std::vector<T> v;
public:
	vector(); //constrictopn
	vector(const size_t size);// CONSTRUCTION PARAM
	size_t GetSize() const; //GetSize
	T& operator[] (const size_t index); //OperatorSqBrackets
	T operator[] (const size_t index) const; // SquareBrackets
	auto begin() const; // iterator begins
	auto end() const;// iterator end
	vector& operator+= (const vector& vec); // OperatorPlusEqual
	vector operator+ (const vector& vec) const; //OperatorPlus	
	vector operator- (const vector& vec) const; // OperatorMinus
	vector& operator-= (const vector& vec); //OperatorMinusEqual
	vector<T>& vector<T>::operator=(const vector<T>& rhs); // Operator Equal
	vector<T> operator*= (const vector<T>& vec) {  //OperatorMulltipliedEqualVector
		for (size_t i = 0; i < v.size(); ++i) {
			v[i] = v[i] * vec.v[i];
		}
		return *this;
	}
	vector<T> operator*= (const T x) {   //OperatorMulltipliedEqualNumber
		for (size_t i = 0; i < v.size(); ++i) {
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
	bool operator== (const vector& vec) const; //OperatorIsEqual
	bool operator!= (const vector& vec) const; // OperatorNotEqual
	auto Erase(typename std::vector<T>::const_iterator index); //MethodErase
	void PushBack(const T& data);  //MethodPushBack
	template <typename TYPE>
	vector<TYPE> operator* (const vector<TYPE>& vec) {
		if (v.size() != vec.v.size()) throw("Difference between sizes");
		size_t size = vec.GetSize();
		vector<TYPE> Newbie(*this);
		for (size_t i = 0; i < size; i++) {
			Newbie.v[i] *= vec.v[i];
		}
		return Newbie;
	}
	T DotPoint(const vector<T>& vec1) const 
	{
		if (vec1.GetSize() != (*this).GetSize()) throw("Difference between sizes");
		size_t size = vec1.GetSize();
		T result = 0;
		for (size_t i = 0; i < size; ++i) {
			result += vec1.v[i] * v[i];
		}
		return result;
	}
	std::complex<T> DotPoint(const vector<std::complex<T>>& vec1) const 
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
