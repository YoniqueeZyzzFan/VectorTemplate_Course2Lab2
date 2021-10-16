#include "../VectorTemplate/Vector.h"
#include "gmock/gmock.h"

TEST(VectorTemplate, ConstructionAndContrstuctionParam) {
	vector<int> a_int;
	vector<int> b_int;
	vector<double> a_double(2);
	vector<double> b_double(2);
	vector<float> a_float(2);
	vector<float> b_float(2);
	vector<std::complex<double>> a_cd(2);
	vector<std::complex<double>> b_cd(2);
	vector<std::complex<float>> a_cf(2);
	vector<std::complex<float>> b_cf(2);
	EXPECT_EQ(0, a_int.GetSize());
	EXPECT_EQ(0, b_int.GetSize());
	EXPECT_EQ(2, a_double.GetSize());
	EXPECT_EQ(2, b_double.GetSize());
	EXPECT_EQ(2, a_float.GetSize());
	EXPECT_EQ(2, b_float.GetSize());
	EXPECT_EQ(2, a_cd.GetSize());
	EXPECT_EQ(2, b_cd.GetSize());
	EXPECT_EQ(2, a_cf.GetSize());
	EXPECT_EQ(2, b_cf.GetSize());
}
TEST(VectorTemplate, Getsize) {
	vector<int> x;
	EXPECT_EQ(0, x.GetSize());
	vector <std::complex<double>> y;
	y.PushBack(std::complex<double>(1, 2));
	y.PushBack(std::complex<double>(2, 1));
	EXPECT_EQ(2, y.GetSize());
}
TEST(VectorTemplate, ConstructionCopy)
{
	vector<int> a_int;
	for (size_t i = 0; i < 2; ++i) {
		a_int.PushBack(((int)i + 1) * 2);
	}
	vector<int> b_int(a_int);
	vector<std::complex<double>> a_cd;
	for (size_t i = 0; i < 2; ++i) {
		a_cd.PushBack(std::complex<double>(((double)i + 1) * 2, (double)i - 1));
	}
	vector<std::complex<double>> b_cd(a_cd);
	EXPECT_EQ(true, a_int == b_int);
	EXPECT_EQ(true, a_cd == b_cd);
}
TEST(VectorTemplate, OperatorIsEqual)
{
	vector<int> a_int;
	for (size_t i = 0; i < 2; ++i) {
		a_int.PushBack(((int)i + 1) * 2);
	}
	vector<int> b_int(a_int);
	vector<std::complex<double>> a_cd;
	for (size_t i = 0; i < 2; ++i) {
		a_cd.PushBack(std::complex<double>(((double)i + 1) * 2, (double)i - 1));
	}
	vector<std::complex<double>> b_cd(a_cd);
	EXPECT_EQ(true, a_int == b_int);
	EXPECT_EQ(true, a_cd == b_cd);
}
TEST(VectorTemplate, OperatorNotEqual)
{
	vector<int> a_int;
	for (size_t i = 0; i < 2; ++i) {
		a_int.PushBack(((int)i + 1) * 2);
	}
	vector<int> b_int(a_int);
	vector<std::complex<double>> a_cd;
	for (size_t i = 0; i < 2; ++i) {
		a_cd.PushBack(std::complex<double>(((double)i + 1) * 2, (double)i - 1));
	}
	vector<std::complex<double>> b_cd(a_cd);
	EXPECT_EQ(false, a_int != b_int);
	EXPECT_EQ(false, a_cd != b_cd);
}

TEST(VectorTemplate, OperatorSqBrackets) {
	vector<std::complex<float>> x(2);
	vector<std::complex<float>> y(x);
	x[1] = std::complex<float>(1, 2);
	std::complex<float> number = x[1];
	EXPECT_EQ(std::complex<float>(1, 2), number);
	EXPECT_EQ(y[0], x[0]);
	EXPECT_EQ(number, x[1]);
}

TEST(VectorTemplate, OperatorEqual) {
	vector<double> second(3);
	for (size_t i = 0; i < 3; ++i) {
		second[i] = (double)i * 2; +1;
	}
	vector<double> first = second;
	EXPECT_EQ(second[0], first[0]);
	EXPECT_EQ(second[1], first[1]);
	EXPECT_EQ(second[2], first[2]);
}

TEST(VectorTempalte, OperatorPluses) {
	vector<float> first(2);
	vector<float> second(2);
	for (size_t i = 0; i < 2; ++i) {
		first[i] = (float)i - 1;
	}
	for (size_t i = 0; i < 2; ++i) {
		second[i] = (float)i + 2;
	}
	first += second;
	vector<float> third = first + second;
	EXPECT_EQ(1, first[0]);
	EXPECT_EQ(3, first[1]);
	EXPECT_EQ(third[0], first[0] + second[0]);
	EXPECT_EQ(third[1], first[1] + second[1]);
}
TEST(VectorTempalte, OperatorDivide) {
	vector<float> first(2);
	for (size_t i = 0; i < 2; ++i) {
		first[i] = (float)i - 1;
	}
	first /= 2;
	EXPECT_EQ(first[0], -0.5);
	EXPECT_EQ(first[1], 0);
}

TEST(VectorTempalte, OperatorMinuses) {
	vector<std::complex<double>> first(2);
	vector<std::complex<double>> second(2);
	for (size_t i = 0; i < 2; ++i) {
		first[i] = std::complex<double>((double)i, (double)i + 1);
	}
	for (size_t i = 0; i < 2; ++i) {
		second[i] = std::complex<double>((double)i + 1, (double)i);
	}
	vector<std::complex<double>> third = first - second;
	first -= second;
	EXPECT_EQ(third[0], first[0]);
	EXPECT_EQ(third[1], first[1]);
}

TEST(VectorTemplate, OperatorScalar)
{
	vector<double> a_d(2);
	vector<double> b_d(2);
	vector<std::complex<double>> a_cd(2);
	vector<std::complex<double>> b_cd(2);
	for (size_t i = 0; i < 2; ++i) {
		a_d[i] = (double)i + 2;
		b_d[i] = a_d[i] - 1;
		a_cd[i] = std::complex<double>(a_d[i], b_d[i]);
		b_cd[i] = std::complex<double>(b_d[i], a_d[i]);
	}
	vector<double> c_d = a_d * b_d;
	double scalar_d = a_d.dot_point(b_d);
	vector <std::complex<double>> c_cd;
	c_cd = a_cd * b_cd;
	std::complex<double> scalar_cd = a_cd.dot_point(b_cd);
	EXPECT_EQ(c_d[0], 2);
	EXPECT_EQ(c_d[1], 6);
	EXPECT_EQ(scalar_cd, a_cd.dot_point(b_cd));
}
TEST(VectorTemplate, MethodErase)
{
	vector<int> a_int;
	for (size_t i = 0; i < 2; ++i) {
		a_int.PushBack(((int)i + 1) * 2);
	}
	vector<int> b_int(a_int);
	b_int.Erase(b_int.begin()+1);
	EXPECT_EQ(1, b_int.GetSize());
	for (size_t i = 0; i < 10; ++i) {
		a_int.PushBack((int)i + 2);
	}

	/*auto i = a_int.begin();
	while (i != a_int.end()) {
		a_int.Erase(i);
		i = a_int.begin();
	}*/
	auto it = a_int.begin();
	for (; it != a_int.end();) {
		it = a_int.Erase(it);
	}
	EXPECT_EQ(0, a_int.GetSize());
}