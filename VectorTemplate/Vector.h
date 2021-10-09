#pragma once
#include <iostream>
#include <string>
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
	T  operator* (const vector& vec); // OperatorScalarMullti
	vector operator*= (const vector& vec); //OperatorMulltipliedEqualVector
	vector operator*= (const T x); //OperatorMulltipliedEqualNumber
	vector operator* (const double x); // OperatorMultipliedbyNumberReturnNew
	vector operator/= (const T x); // OperatorDivideEqual
	vector operator/ (const double x); // OperatorDivide
	bool operator== (const vector& vec); //OperatorIsEqual
	bool operator!= (const vector& vec); // OperatorNotEqual
	void Erase(const size_t index); //MethodErase
	void PushBack(const T& data);  //MethodPushBack
	~vector();
};
template <typename T>
std::ostream& operator<<(std::ostream& stream, const	vector<T>& v);
template <typename T>
vector <T> operator* (const double x, vector  <T>& vec);
template <typename T>
vector <T> operator*= (const double x, vector<T>& vec);

