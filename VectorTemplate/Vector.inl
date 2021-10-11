#pragma once
#include <iostream>
#include <complex>
#include "Vector.h"

template <typename T>
vector<T>::vector() {  // CONSTRUCTION
	grow_size = 10;
	size = 0;
	capacity = 10;
	v = NULL;
}

template <typename T>
vector<T>::vector(const size_t size) {  // CONSTRUCTION PARAM
	grow_size = 10;
	capacity = grow_size;
	while (size > capacity) {
		capacity += grow_size;
	}
	this->size = size;
	v = new T[capacity];
	for (size_t i = 0; i < size; ++i) {
		if (size >= capacity) break;
		v[i] = 0;
	}
}
template <typename T>
vector<T>::vector(const vector<T>& vec) {   // ConstructorCopy
	grow_size = 10;
	capacity = vec.capacity;
	size = vec.size;
	v = new T[vec.capacity];
	if (size < capacity)
	{
		for (size_t i = 0; i < vec.capacity; ++i) {
			v[i] = vec.v[i];
		}
	}
}
template <typename T>
size_t vector<T>::GetSize() const {  //GetSize
	return size;
}

template <typename T>
T& vector<T>::operator[] (const size_t index) {
	if (index >= size) throw ("Index is out of range");
	return v[index];
}

template <typename T>
T vector<T>::operator[] (const size_t index) const {       // SquareBrackets
	if (index >= size) throw("Index is out of ragne");
	return v[index];
}

template <typename T>
vector<T> vector<T>::operator+= (const vector<T>& vec) {       // OperatorPlusEqual
	if (size != vec.size) throw("Difference between sizes");
	for (size_t i = 0; i < size; ++i) {
		v[i] += vec.v[i];
	}
	return *this;
}

template <typename T>
vector<T> vector<T>::operator+ (const vector<T>& vec) {     //OperatorPlus
	if (size != vec.size) throw("Difference between sizes");
	vector<T> Newbie(*this);
	Newbie += vec;
	return Newbie;
}

template <typename T>
vector<T>& vector<T>::operator= (const vector<T>& vec) { //OperatorEqual
	if (this == &vec) return *this;
	if (size != vec.size)
	{
		delete[] v;
		size = vec.size;
		capacity = vec.capacity;
		v = new T[capacity];
		for (size_t i = 0; i < size; ++i)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}
}

template <typename T>
vector<T> vector<T>::operator- (const vector<T>& vec) {   // OperatorMinus
	vector<T> Newbie = *this;
	Newbie -= vec;
	return Newbie;
}

template <typename T>
vector<T> vector<T>::operator-= (const vector<T>& vec) {    //OperatorMinusEqual
	if (size != vec.size) throw("Difference between sizes");
	for (size_t i = 0; i < size; ++i) {
		v[i] = v[i] - vec.v[i];
	}
	return *this;
}

template <typename T>
vector<T> vector<T>::operator/= (const T x) {   // OperatorDivideEqual
	if (x == (T)0) throw("Cant divide by zero");
	for (size_t i = 0; i < size; ++i) {
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
bool vector<T>::operator== (const vector<T>& vec) {    //OperatorIsEqual
	if (size != vec.size) return false;
	for (size_t i = 0; i < size; ++i) {
		if (v[i] != vec.v[i]) return false;
	}
	return true;
}

template <typename T>
bool vector<T>::operator!= (const vector<T>& vec) {     // OperatorNotEqual
//	if (size != vec.size) return true;
//	for (size_t i = 0; i < size; ++i) {
//		if (v[i] != vec.v[i]) return true;
//	}
//	return false;
	return (!(*this == vec));
}

template <typename T>
void vector<T>::Erase(const size_t index) {  //MethodErase
	if (index >= size) throw ("Index is out of range");
	for (size_t i = index; i < size - 1; ++i) {
		v[i] = v[i + 1];
	}
	size--;
}

template <typename T>
void vector<T>::PushBack(const T &data) { //MethodPushBack
	if (capacity <= size + 1) {
		capacity += grow_size;
		T* temp = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			if (size >= capacity) break;
			temp[i] = 0;
		}
		if (size < capacity)
		{
			for (size_t i = 0; i < size; ++i) {
				temp[i] = v[i];
			}
		}
		delete[] v;
		v = new T[capacity];
		if (size < capacity)
		{
			for (size_t i = 0; i < size; ++i)
			{
				v[i] = temp[i];
			}
			v[size] = data;
		}
		size++;
		delete[] temp;
	}
	else {
		if (v == nullptr) {
			v = new T[capacity];
			v[size] = data;
			size++;
		}
		else {
			v[size] = data;
			size++;
		}
	}
}

template <typename T>
vector<T>::~vector<T>() {
	delete[] v;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const vector<T>& v) {
	stream << "Size : " << v.GetSize() << std::endl;
	for (size_t i = 0; i < v.GetSize(); ++i) {
		stream << i + 1 << " : " << v[i]<< std::endl;
	}
	return stream;
}


