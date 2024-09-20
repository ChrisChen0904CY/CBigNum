#ifndef CBIGNUM_H
#define CBIGNUM_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

// Display a vector
template <typename T>
void vecDisplay(vector<T> vec) {
	for (auto element:vec) {
		cout << element << " " << endl;
	}
}

/**
* @Brief: A Big Num Class store data in two vectors
* @Author: Chris Chan
* @Date: 2024/08/19
*/
class CBigNum {

friend ostream& operator<<(ostream& os, const CBigNum& num);
friend ostream& operator<<(ostream& os, const CBigNum* num);

public:
	/**
	* @Breif: Construct & Deconstruct Functions
	* @Author: Chris Chan
	* @Date: 2024/08/19
	*/
	CBigNum();
	// Copy Construction
	CBigNum(const CBigNum& other);
	CBigNum& operator=(const CBigNum& other);
	// Signed Num
	CBigNum(short n) : CBigNum(static_cast<long long int>(n)) {};
	CBigNum(int n) : CBigNum(static_cast<long long int>(n)) {};
	CBigNum(long int n) : CBigNum(static_cast<long long int>(n)) {};
	CBigNum(long long int n);
	CBigNum(float n) : CBigNum(to_string(n)) {};
	CBigNum(double n) : CBigNum(to_string(n)) {};
	CBigNum(long double n) : CBigNum(to_string(n)) {};
	// Unsigned Num
	CBigNum(unsigned short n) : CBigNum(static_cast<unsigned long long int>(n)) {};
	CBigNum(unsigned int n) : CBigNum(static_cast<unsigned long long int>(n)) {};
	CBigNum(unsigned long int n) : CBigNum(static_cast<unsigned long long int>(n)) {};
	CBigNum(unsigned long long int n);
	// String & Vector
	CBigNum(string s);
	CBigNum(vector<char> ints, vector<char> fracs);
	~CBigNum();
	
	/**
	* @Breif: Get & Set functions
	* @Author: Chris Chan
	* @Date: 2024/08/19
	*/
	bool getPositive() const;
	vector<char> getInts() const;
	vector<char> getFracs() const;
	long long getResFracBits() const;
	void setPositive(bool p);
	void setInts(vector<char> newInts);
	void setFracs(vector<char> newFracs);
	
	/**
	* @Breif: Aid functions
	* @Author: Chris Chan
	* @Date: 2024/08/19
	*/
	bool isNum(char c);
	void zeroClear();
	CBigNum getInt() const;
	CBigNum getFrac() const;
	void round(long long bits);
	
	/**
	* @Breif: Compare Operators
	* @Author: Chris Chan
	* @Date: 2024/08/20
	*/
	bool operator>(const CBigNum other) const;
	bool operator<(const CBigNum other) const;
	bool operator==(const CBigNum other) const;
	bool operator!=(const CBigNum other) const;
	bool operator>=(const CBigNum other) const;
	bool operator<=(const CBigNum other) const;
	
	/**
	* @Breif: Compute Operators
	* @Author: Chris Chan
	* @Date: 2024/08/20
	*/
	// Add
	CBigNum operator+(const CBigNum& other) const;
	void operator+=(const CBigNum& other);
	// Minus
	CBigNum operator-() const;
	CBigNum operator-(const CBigNum& other) const;
	void operator-=(const CBigNum& other);
	// Move Left
	CBigNum operator<<(const long long& bits) const;
	void operator<<=(const long long& bits);
	// Move Right
	CBigNum operator>>(const long long& bits) const;
	void operator>>=(const long long& bits);
	// Multiply
	CBigNum operator*(const CBigNum& other) const;
	void operator*=(const CBigNum& other);
	// Int Division
	pair<CBigNum, CBigNum> intDivision(const CBigNum& other) const;
	// Division
	CBigNum operator/(const CBigNum& other) const;
	void operator/=(const CBigNum& other);
	void setResFracBits(long long bits);
	// Mod
	CBigNum operator%(const CBigNum& other) const;
	void operator%=(const CBigNum& other);
	
private:
	/* Main Data Struct */
	bool positive = true;
	vector<char> ints;
	vector<char> fracs;
	// Residual fraction bits
	long long resFracBits = 8;
};

/* Operatoin Template */
template <typename T>
CBigNum any2BigNum(T value) {
  CBigNum num(value);
  return num;
}


// Addition Template
template <typename T>
CBigNum operator+(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num + other;
}
// +=
template <typename T>
void operator+=(CBigNum& num, const T& value) {
    num += any2BigNum(value);
}

// Subtraction Template
template <typename T>
CBigNum operator-(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num - other;
}
// -=
template <typename T>
void operator-=(CBigNum& num, const T& value) {
    num -= any2BigNum(value);
}

// Multiplication Template
template <typename T>
CBigNum operator*(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num * other;
}
// *=
template <typename T>
void operator*=(CBigNum& num, const T& value) {
    num *= any2BigNum(value);
}

// Division Template
template <typename T>
CBigNum operator/(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num / other;
}
// /=
template <typename T>
void operator/=(CBigNum& num, const T& value) {
    num /= any2BigNum(value);
}

// Modulo Template
template <typename T>
CBigNum operator%(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num % other;
}
// %=
template <typename T>
void operator%=(CBigNum& num, const T& value) {
    num %= any2BigNum(value);
}

/* Compare Template */
// > & >=
template <typename T>
bool operator>(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num > other;
}
template <typename T>
bool operator>=(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num >= other;
}
// < & <=
template <typename T>
bool operator<(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num < other;
}
template <typename T>
bool operator<=(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num <= other;
}
// == & !=
template <typename T>
bool operator==(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num == other;
}
template <typename T>
bool operator!=(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    return num != other;
}

// abs Function
CBigNum abs(const CBigNum& num);

#endif

