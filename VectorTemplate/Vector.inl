#pragma once
#include <iostream>
#include <complex>
#include<vector>
#include<iterator>
#include "Vector.h"
template <typename T>
vector<T>::vector() {  // CONSTRUCTION

}

template <typename T>
vector<T>::vector(const size_t size) {  // CONSTRUCTION PARAM
	for (size_t i = 0; i < size; ++i) {
		v.push_back(0);
	}
}

template <typename T>
size_t vector<T>::GetSize() const {  //GetSize
	return v.size();
}

template <typename T>
T& vector<T>::operator[] (const size_t index) {
	if (index >= v.size()) throw ("Index is out of range");
	return v[index];
}

template <typename T>
T vector<T>::operator[] (const size_t index) const {       // SquareBrackets
	if (index >= v.size()) throw("Index is out of ragne");
	return v[index];
}

template <typename T>
vector<T>& vector<T>::operator+= (const vector<T>& vec) {       // OperatorPlusEqual
	if (v.size() != vec.v.size()) throw("Difference between sizes");
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] += vec.v[i];
	}
	return *this;
}

template <typename T>
vector<T> vector<T>::operator+ (const vector<T>& vec) const {     //OperatorPlus
	if (v.size() != vec.v.size()) throw("Difference between sizes");
	vector<T> Newbie(*this);
	Newbie += vec;
	return Newbie;
}


template <typename T>
vector<T> vector<T>::operator- (const vector<T>& vec) const {   // OperatorMinus
	vector<T> Newbie = *this;
	Newbie -= vec;
	return Newbie;
}

template <typename T>
vector<T>& vector<T>::operator-= (const vector<T>& vec) {    //OperatorMinusEqual
	if (v.size() != vec.v.size()) throw("Difference between sizes");
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = v[i] - vec.v[i];
	}
	return *this;
}

template <typename T>
vector<T> vector<T>::operator/= (const T x) {   // OperatorDivideEqual
	if (x == (T)0) throw("Cant divide by zero");
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] /= x;
	}
	return *this;
}

template <typename T>
vector<T> vector<T>::operator/ (const T x) {    // OperatorDivide
	if (x == (T)0) throw("Cant divide by zero");
	vector<T> Newbie = *this;
	Newbie /= x;
	return Newbie;
}

template <typename T>
bool vector<T>::operator== (const vector<T>& vec) const {    //OperatorIsEqual
	if (v.size() != vec.v.size()) return false;
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] != vec.v[i]) return false;
	}
	return true;
}

template <typename T>
bool vector<T>::operator!= (const vector<T>& vec) const {     // OperatorNotEqual
	return (!(*this == vec));
}

template <typename T>
auto vector<T>::Erase(typename std::vector<T>::const_iterator index) {  //MethodErase
	return v.erase(index);
}
template <typename T>
auto vector<T>::begin() const
{
	return v.begin();
}
template <typename T>
auto vector<T>::end() const
{
	return v.end();
}

template <typename T>
void vector<T>::PushBack(const T& data) { //MethodPushBack
	v.push_back(data);
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& rhs) //Operator equal
{
	if (this == &rhs) return *this;
	for (size_t i = 0; i < rhs.v.size(); ++i) {
		v[i] = rhs.v[i];
	}
	return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const vector<T>& v) {
	stream << "Size : " << v.GetSize() << std::endl;
	for (size_t i = 0; i < v.GetSize(); ++i) {
		stream << i + 1 << " : " << v[i] << std::endl;
	}
	return stream;
}


