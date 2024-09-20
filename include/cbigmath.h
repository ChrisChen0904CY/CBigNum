#ifndef CBIGMATH_H
#define CBIGMATH_H

#include "cbignum.h"

// Calculate number of Continued Fraction Expansion
#define Expansion_N 51
#define log_N 100

const CBigNum ln3("1.0986122886681096");
const CBigNum ln10("2.302585092994046");

/**
* @Brief: Power operation
* @Author: Chris Chan
* @Date: 2024/09/18
*/
template <typename T>
CBigNum pow(const CBigNum& num, const T& value) {
    CBigNum other = any2BigNum(value);
    // Deal with 0 power
    if (other == 0) {
    	return CBigNum(1);
		}
    CBigNum res(1);
    bool posPower = other.getPositive();
    other = abs(other);
    // Integer Power
    if (other.getFracs().empty()) {
    	CBigNum base = num;
    	while (other > 0) {
				if (other % 2 == 1) {
          res *= base;
        }
        base *= base;
        other = other.intDivision(2).first;
   		}
   		// Deal with the negative power
   		CBigNum one(1);
   		one.setResFracBits(num.getResFracBits());
   		return posPower ? res : (one/res);
		}
}

/**
* @Brief: Ln & Log
* @Author: Chris Chan
* @Date: 2024/09/18
*/
// ln
CBigNum ln(const CBigNum& a);
CBigNum cheby_ln(const CBigNum& a);
template <typename T>
CBigNum ln(const T& value) {
    CBigNum num = any2BigNum(value);
    return ln(num);
}
// log
template <typename T>
CBigNum log(const CBigNum& base, const T& value) {
	// Check the base first
	if (base <= 0 || base == 1) {
		throw "Log Base Error: Base must be positive and not 1.";
	}
	CBigNum natrual = CBigNum(value);
	natrual.setResFracBits(base.getResFracBits());
	// Check the natrual then
	if (natrual <= 0) {
		throw "Log Natrual Error: Natrual must be positive.";
	}
	// Return 1 when natrual == base
	if (natrual == base) {
		CBigNum one(1);
		one.setResFracBits(base.getResFracBits());
		return one;
	}
	return ln(natrual) / ln(base);
}

#endif

