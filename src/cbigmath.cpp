#include "cbigmath.h"

CBigNum pow(const CBigNum& num, long long value) {
    CBigNum other = any2BigNum(value);
    // Deal with 0 power
    if (other == 0) {
    	return CBigNum(1);
		}
    CBigNum res(1);
    bool posPower = other.getPositive();
    other = abs(other);
    // Integer Power
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

// Find the log_N
long long log_N_find(const CBigNum& a) {
	long long log_N = 1;
	CBigNum xx = a*a;
	CBigNum Rn = xx/(2*log_N)*(1/(1-xx));
	CBigNum epsilon = CBigNum(1) >> (a.getResFracBits()+1);
	while (1) {
		if (abs(Rn) < epsilon) {
			break;
		}
		log_N += 1;
		Rn *= xx*log_N/(log_N+1);
	}
	return log_N;
}

CBigNum ln(const CBigNum& a) {
    CBigNum num = a;
    long long scaled_k = 0;
    
    while (num < 1) {
  		num <<= 1;
  		scaled_k++;
    }
    
    // Check the natural first
    if (num <= 0) {
      throw "Log Natural Error: Natural must be positive.";
      return CBigNum(0);  
    }
    
    // Handle numbers greater than 1 by reducing them
    long long k = 0;
    while (num > 10) {
        num >>= 1;
        k++;
    }

    CBigNum x = (num - 1)/(num + 1);
    CBigNum xx = x*x;
    long long log_N = log_N_find(x);
    long long nk = 2*log_N+1;
    CBigNum y = CBigNum(1)/nk;
    
    for(int i = 0; i < log_N; i++)
    {
      nk = nk - 2;
      y = CBigNum(1)/nk+xx*y;
      y.round(num.getResFracBits()+1);
    }

    // Adding the correction term for the number of divisions we performed
    CBigNum result = 2.0*x*y + (k-scaled_k) * ln10;

    result.round(num.getResFracBits());
    result.setResFracBits(num.getResFracBits());
    return result;
}

/* Trigonometric functions */
long long SINCOS_N_find(const CBigNum& x) {
	long long N = 1;
	CBigNum xx = x*x;
	CBigNum Rn = xx/2;
	CBigNum epsilon = CBigNum(1) >> (x.getResFracBits()+1);
	while (1) {
		if (abs(Rn) < epsilon) {
			break;
		}
		N += 1;
		Rn *= xx/(2*N*(2*N-1));
	}
	return N;
}
CBigNum SINTNV(const CBigNum& x) {
	long long N = SINCOS_N_find(x);
	CBigNum y(1), xx(x*x), tmp;
	CBigNum k(2*N);
	while (k > 0) {
		y = 1 - y*xx/k/(k+1);
		k -= 2;
		y.round(x.getResFracBits()+1);
	}
	y *= x;
	y.round(x.getResFracBits());
	return y;
}
CBigNum COSTNV(const CBigNum& x) {
	long long N = SINCOS_N_find(x);
	CBigNum y(1), xx(x*x), tmp;
	CBigNum k(2*N);
	while (k > 0) {
		y = 1 - y*xx/k/(k-1);
		k -= 2;
		y.round(x.getResFracBits()+1);
	}
	y.round(x.getResFracBits());
	return y;
}
// sin
CBigNum sin(const CBigNum& a) {
	if (a < 0) {
		return -sin(-a);
	}
	CBigNum rad(a);
	// Scaled to [0, 2pi) first
	rad %= 2*PI;
	// Judge for special value
	if (rad % PI == 0) {
		return CBigNum(0);
	}
	else if (rad == PI_2) {
		return CBigNum(1);
	}
	else if (rad == 3*PI_2) {
		return CBigNum(-1);
	}
	// Scaled to [0, pi/2) then
	pair<CBigNum, CBigNum> intd;
	intd = rad.intDivision(CBigNum(PI_2));
	CBigNum k = intd.first;
	CBigNum x = intd.second;
	// sin(0+x) = sin(x)
	// sin(PI+x) = sin(x)
	if (k == 0 || k == 2) {
		CBigNum ans = SINTNV(x);
		ans = (k==0) ? ans : -ans;
		return ans;
	}
	// sin(PI/2+x) = cos(x)
	// sin(3PI/2+x) = -cos(x)
	else {
		CBigNum ans = COSTNV(x);
		ans = (k==1) ? ans : -ans;
		return ans;
	}
}

// cos
CBigNum cos(const CBigNum& a) {
	if (a < 0) {
		return cos(-a);
	}
	CBigNum rad(a);
	// Scaled to [0, 2pi) first
	rad = abs(rad % (2*PI));
	// Judge for special value
	if (rad == 0) {
		return CBigNum(1);
	}
	else if (rad == PI_2 || rad == 3*PI_2) {
		return CBigNum(0);
	}
	else if (rad == PI) {
		return CBigNum(-1);
	}
	// Scaled to [0, pi/2) then
	pair<CBigNum, CBigNum> intd;
	intd = rad.intDivision(CBigNum(PI_2));
	CBigNum k = intd.first;
	CBigNum x = intd.second;
	// cos(0+x) = cos(x)
	// cos(PI+x) = -cos(x)
	if (k == 0 || k == 2) {
		CBigNum ans = COSTNV(x);
		return (k==0) ? ans : -ans;
	}
	// cos(PI/2+x) = -sin(x)
	// cos(3PI/2+x) = sin(x)
	else {
		CBigNum ans = SINTNV(x);
		return (k==1) ? -ans : ans;
	}
}

// tan
CBigNum tan(const CBigNum& a) {
	if (cos(a) == 0) {
		throw "Unavailable to compute undefine tan(x).";
	}
	return sin(a)/cos(a);
}

// cot
CBigNum cot(const CBigNum& a) {
	if (sin(a) == 0) {
		throw "Unavailable to compute undefine cot(x).";
	}
	return cos(a)/sin(a);
}

/* e^x */
long long EXP_N_find(const CBigNum& x) {
	long long n = 1;
	CBigNum Rn = x * (1/(1 - x/n));
	CBigNum epsilon = CBigNum(1) >> (x.getResFracBits());
	while (abs(Rn) >= epsilon) {
		Rn *= x/(++n);
		Rn.round(x.getResFracBits()+1);
	}
	return n;
}

CBigNum EXPTNV(const CBigNum& x) {
	long long EXP_N = EXP_N_find(x);
	CBigNum y(1.0);
	for(long long k = EXP_N; k > 0; k--) {
		y = 1 + y*x/k;
	}
	y.round(x.getResFracBits());
	return y;
}

CBigNum exp(const CBigNum& a) {
	if (a == 0) {
		return CBigNum(1);
	}
	else if (a < 0) {
		return 1/exp(-a);
	}
	// Scaled bit number to (0, 10)
	CBigNum x(a);
	long long k = 0;
	if (x > 10) {
		k = x.getInts().size() - 1;
		x >>= k;
	}
	CBigNum ans = pow(EXPTNV(x), pow(10, k));
	ans.round(a.getResFracBits()); 
	return ans;
}

// ASin Iteratoin
long long ASIN_N_find(const CBigNum& x) {
	long long N = 1;
	CBigNum epsilon = CBigNum(1) >> (x.getResFracBits());
	CBigNum xx = x*x;
	CBigNum tmp = 1/(1-xx);
	CBigNum Rn = tmp/(2*N);
	long long k1, k2;
	k1 = 1; k2 = 2;
	while(1) {
		if(Rn < epsilon) break;
		tmp *= xx*k1/k2;
		Rn = tmp/(2*N);
		tmp.round(x.getResFracBits()+1);
		Rn.round(x.getResFracBits()+1);
		k1 += 2;
		k2 += 2;
		N++;
	}
	return N;
}
CBigNum ASINTNV(const CBigNum& x) {
  long long N = ASIN_N_find(x);
	CBigNum y(1);
	long long k2 = 2*N;
	long long k1 = k2 - 1;
	CBigNum xx = x*x;
	CBigNum one(1);
	one.setResFracBits(x.getResFracBits());
	for(long long k = N; k >= 1; k--) {
		y = y*xx*k1/k2 + one/k1;
		y.round(x.getResFracBits()+1);
		k1 -= 2;
		k2 -= 2;
	}
	y *= x; 
	y.round(x.getResFracBits());
	return y;
}

// arcsin
CBigNum asin(const CBigNum& a) {
	// Check the given number first
	if(a < -1 || a > 1) {
		throw "Out of the domain of definition when compute asin().";
	}
	if (a < 0) {
		return -asin(-a);
	}
	// Deal with special case
	if (a == 1) {
		return CBigNum(PI_2);
	}
	else if (a == 0) {
		return CBigNum(0);
	}
	// Shift Simplification
	CBigNum x(a);
	CBigNum y(0), y0(0), x0(0);
	while (x > SINA4) {
		x0 = x; y0 += PI_6;
		x = x0*COSA3-SINA3*sqrt(1-x0*x0);
	}
	while (x > SINA3) {
		x0 = x; y0 += PI_12;
		x = x0*COSA2-SINA2*sqrt(1-x0*x0);
	}
	while (x > SINA2) {
		x0 = x; y0 += PI_24;
		x = x0*COSA1-SINA1*sqrt(1-x0*x0);
	}
	y = ASINTNV(x)+y0;
	y.round(a.getResFracBits());
	return y;
}

// arccos
CBigNum acos(const CBigNum& a) {
	// Check the given number first
	if(a < -1 || a > 1) {
		throw "Out of the domain of definition when compute asin().";
	}
	return asin(sqrt(1-(a*a)));
}

// ATan Iteratoin
long long ATAN_N_find(const CBigNum& x) {
	long long N = 1;
	CBigNum epsilon = CBigNum(x) >> x.getResFracBits();
	CBigNum xx = x*x;
	CBigNum y = xx;
	CBigNum Rn = y/3;
	while(Rn >= epsilon) {
		y *= xx;
		Rn = y/(2*(++N)+1);
	}
	return N;
}
CBigNum ATANTNV(const CBigNum& x) {
	long long N = ATAN_N_find(x);
	CBigNum xx = x*x;
	long long nk = 2*N - 1;
	CBigNum one(1);
	one.setResFracBits(x.getResFracBits());
	CBigNum y = one/(nk+2);
	for(long long k = N; k > 0; k--) {
		y = one/nk - xx*y;
		nk -= 2;
		y.round(x.getResFracBits()+1);
	}
	y *= x;
	y.round(x.getResFracBits());
	return y;
}

// arctan
CBigNum atan(const CBigNum& a) {
	if (a < 0) {
		return -atan(-a);
	}
	else if (a <= (CBigNum(1) >> 16)) {
		return CBigNum(0);
	}
	CBigNum x(a), y(0);
	long long k = 1;
	while(1) {
		if (x < 0.26) break;
		k <<= 1;
		y = x/(1+sqrt(1+x*x));
		y.round(x.getResFracBits()+1);
		x=y;
	}
	y = (k*ATANTNV(x))%PI;
	y.round(x.getResFracBits());
	return y;
}

// arccot
CBigNum acot(const CBigNum& a) {
	if (a < 0) {
		return -acot(-a);
	}
	CBigNum one(1);
	one.setResFracBits(a.getResFracBits());
	if (a > 0.5) return atan(one/a);
	return PI_2-atan(a);
}

