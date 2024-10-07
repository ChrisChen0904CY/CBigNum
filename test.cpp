#include "cbignum.h"
#include "cbigmath.h"

using namespace std;

int main() {
	/* Instantialize Testing */
	cout << "====== Instantialize Testing ======" << endl;
	CBigNum num1;
	cout << "Default Construction: " << num1 << endl;
	CBigNum num2(int(123));
	CBigNum num3(int(-556));
	CBigNum num4(int(0));
	cout << "Int Construction: " << num2 << " " << num3 << " " << num4 << endl;
	CBigNum num5("0001.2345678900");
	CBigNum num6("-123465789.987654321");
	CBigNum num7("1..02");
	CBigNum nume("1.7506827451479023e-07");
	cout << "String Construction: " << num5 << " " << num6 << " " << num7 << " " << nume << endl;
	CBigNum num8(1.23456);
	CBigNum num9(-23456.123);
	CBigNum num10(0.1);
	cout << "Double Construction: " << num8 << " " << num9 << " " << num10 << endl;
	CBigNum num11 = num8;
	CBigNum num12 = -num11;
	cout << "Copy Construction and Minus Operation: " << num11 << " " << num12 << endl;
	cout << "====== Instantialize Test Ending ======" << endl << endl;
	/* Comparing Testing */
	cout << "====== Comparing Testing ======" << endl;
	cout << num5 << " < " << num8 << ": " << (num5 < num8 ? "True" : "False") << endl;
	cout << num6 << " < " << num8 << ": " << (num6 < num8 ? "True" : "False") << endl;
	cout << num5 << " > " << num8 << ": " << (num5 > num8 ? "True" : "False") << endl;
	cout << num5 << " >= " << num8 << ": " << (num5 >= num8 ? "True" : "False") << endl;
	cout << num5 << " <= " << num8 << ": " << (num5 <= num8 ? "True" : "False") << endl;
	cout << num5 << " == " << num8 << ": " << (num5 == num8 ? "True" : "False") << endl;
	cout << num5 << " != " << num8 << ": " << (num5 != num8 ? "True" : "False") << endl;
	cout << CBigNum("12300000") << " < " << CBigNum("12345600") << ": " << (CBigNum("12300000") < CBigNum("12345600") ? "True" : "False") << endl;
	cout << "====== Comparing Test Ending ======" << endl << endl;
	/* Adding Testing */
	cout << "====== Adding Testing ======" << endl;
	cout << "(" << num1 << ") + (" << num2 << ")" << " = " << (num1 + num2) << endl;
	cout << "(" << num2 << ") + (" << num5 << ")" << " = " << (num2 + num5) << endl;
	cout << "(" << num1 << ") + (" << num4 << ")" << " = " << (num1 + num4) << endl;
	cout << "(" << num5 << ") + (" << num8 << ")" << " = " << (num5 + num8) << endl;
	cout << "(" << num3 << ") + (" << num3 << ")" << " = " << (num3 + num3) << endl;
	cout << "(" << num3 << ") + (" << num6 << ")" << " = " << (num3 + num6) << endl;
	cout << "(123456.123) + (1234.1) = " << (CBigNum(123456.123) + CBigNum(1234.1)) << endl;
	// Add convert to minus testing
	cout << "(" << num2 << ") + (" << num3 << ")" << " = " << (num2 + num3) << endl;
	cout << "(" << num3 << ") + (" << num2 << ")" << " = " << (num3 + num2) << endl;
	cout << "(" << num8 << ") + (" << num9 << ")" << " = " << (num8 + num9) << endl;
	cout << "(" << num9 << ") + (" << num8 << ")" << " = " << (num9 + num8) << endl;
	cout << "====== Adding Test Ending ======" << endl << endl;
	/* Minus Testing */
	cout << "====== Minus Testing ======" << endl;
	cout << "(" << num2 << ") - (" << num8 << ")" << " = " << (num2 - num8) << endl;
	cout << "(" << num6 << ") - (" << num9 << ")" << " = " << (num6 - num9) << endl;
	cout << "(12300000) - (12345600) = " << (CBigNum("12300000") - CBigNum("12345600")) << endl;
	// Minus convert to add testing
	cout << "(" << num2 << ") - (" << num6 << ")" << " = " << (num2 - num6) << endl;
	cout << "(" << num6 << ") - (" << num2 << ")" << " = " << (num6 - num2) << endl;
	cout << "====== Minus Test Ending ======" << endl << endl;
	/* Bits Operating Testing */
	cout << "====== Bits Operating Testing ======" << endl;
	cout << "(" << num8 << ") * (100)" << " = " << (num8 << 2) << endl;
	cout << "(" << num6 << ") * (1000)" << " = " << (num6 << 3) << endl;
	cout << "(" << num8 << ") / (10)" << " = " << (num8 >> 1) << endl;
	cout << "(" << num8 << ") / (100)" << " = " << (num8 >> 2) << endl;
	cout << "(" << num6 << ") / (1000000000)" << " = " << (num6 >> 9) << endl;
	cout << "====== Bits Operating Test Ending ======" << endl << endl;
	/* Multiplication Testing */
	cout << "====== Multiplication Testing ======" << endl;
	cout << "(" << num2 << ") * (" << num8 << ")" << " = " << (num2 * num8) << endl;
	cout << "(" << num3 << ") * (" << num9 << ")" << " = " << (num3 * num9) << endl;
	cout << "(" << num2 << ") * (" << num3 << ")" << " = " << (num2 * num3) << endl;
	cout << "(" << num9 << ") * (" << num8 << ")" << " = " << (num9 * num8) << endl;
	cout << "(99999.9999) * (99999.9999) = " << (CBigNum("99999.9999") * CBigNum("99999.9999")) << endl;
	cout << "====== Multiplication Test Ending ======" << endl << endl;
	/* Int Division Testing */
	cout << "====== Int Division Testing ======" << endl;
	cout << "(" << num2 << ") // (" << num8 << ")" << " = " << (num2.intDivision(num8)).first << " + " << (num2.intDivision(num8)).second << endl;
	cout << "(" << num3 << ") // (" << num9 << ")" << " = " << (num3.intDivision(num9)).first << " + " << (num3.intDivision(num9)).second << endl;
	cout << "(" << num2 << ") // (" << num3 << ")" << " = " << (num2.intDivision(num3)).first << " + " << (num2.intDivision(num3)).second << endl;
	cout << "(" << num9 << ") // (" << num8 << ")" << " = " << (num9.intDivision(num8)).first << " + " << (num9.intDivision(num8)).second << endl;
	cout << "(123.12) // (11.245) = " << (CBigNum(123.12).intDivision(CBigNum(11.245))).first << " + " << (CBigNum(123.12).intDivision(CBigNum(11.245))).second << endl;
	cout << "(-123.12) // (11.245) = " << (CBigNum(-123.12).intDivision(CBigNum(11.245))).first << " + " << (CBigNum(-123.12).intDivision(CBigNum(11.245))).second << endl;
	cout << "(10) // (2) = " << (CBigNum(10).intDivision(2)).first << " + " << (CBigNum(10).intDivision(CBigNum(2))).second << endl;
	cout << "====== Int Division Test Ending ======" << endl << endl;
	/* Division Testing */
	cout << "====== Division Testing ======" << endl;
	num2.setResFracBits(32);
	cout << "(" << num2 << ") / (" << num8 << ")" << " = " << (num2 / num8) << endl;
	num3.setResFracBits(32);
	cout << "(" << num3 << ") / (" << num9 << ")" << " = " << (num3 / num9) << endl;
	cout << "(" << num2 << ") / (" << num3 << ")" << " = " << (num2 / num3) << endl;
	num9.setResFracBits(64);
	cout << "(" << num9 << ") / (" << num8 << ")" << " = " << (num9 / num8) << endl;
	cout << "(123.12) / (11.245) = " << (CBigNum(123.12) / CBigNum(11.245)) << endl;
	cout << "(-123.12) / (11.245) = " << (CBigNum(-123.12) / CBigNum(11.245)) << endl;
	cout << "(1) / (64) = " << (CBigNum(1) / CBigNum(64)) << endl;
	cout << "(1000) / (25) = " << (CBigNum(1000) / CBigNum(25)) << endl;
	cout << "(1234567898765432123456789) / (12.3456789) = " << (CBigNum("1234567898765432123456789") / CBigNum("12.3456789")) << endl;
	cout << "====== Division Test Ending ======" << endl << endl;
	/* Mod Testing */
	cout << "====== Mod Testing ======" << endl;
	cout << "(" << num2 << ") % (" << num8 << ")" << " = " << (num2 % num8) << endl;
	cout << "(" << num3 << ") % (" << num9 << ")" << " = " << (num3 % num9) << endl;
	cout << "(" << num2 << ") % (" << num3 << ")" << " = " << (num2 % num3) << endl;
	cout << "(" << num9 << ") % (" << num8 << ")" << " = " << (num9 % num8) << endl;
	cout << "(123.12) % (11.245) = " << (CBigNum(123.12) % CBigNum(11.245)) << endl;
	cout << "(-123.12) % (11.245) = " << (CBigNum(-123.12) % CBigNum(11.245)) << endl;
	cout << "(1) % (64) = " << (CBigNum(1) % CBigNum(64)) << endl;
	cout << "(1000) % (25) = " << (CBigNum(1000) % CBigNum(25)) << endl;
	cout << "(1234567898765432123456789) % (12.3456789) = " << (CBigNum("1234567898765432123456789") % CBigNum("12.3456789")) << endl;
	cout << "====== Mod Test Ending ======" << endl << endl;
	/* Template Operation Testing */
	cout << "====== Template Operation Testing ======" << endl;
	cout << "(" << num2 << ") + (114.514)" << " = " << (num2 + 114.514) << endl;
	cout << "(" << num2 << ") - (114.514)" << " = " << (num2 - 114.514) << endl;
	cout << "(" << num2 << ") * (114.514)" << " = " << (num2 * 114.514) << endl;
	cout << "(" << num2 << ") / (114.514)" << " = " << (num2 / 114.514) << endl;
	cout << "(" << num2 << ") % (114.514)" << " = " << (num2 % CBigNum("114.514")) << endl;
	cout << "(" << num8 << ") + (1)" << " = " << (num8 + 1) << endl;
	cout << "(" << num8 << ") - (1)" << " = " << (num8 - 1) << endl;
	cout << "(" << num8 << ") * (114.514)" << " = " << (num8 * 114.514) << endl;
	cout << "(" << num8 << ") / (114.514)" << " = " << (num8 / 114.514) << endl;
	cout << "(" << num8 << ") % (114.514)" << " = " << (num8 % CBigNum("114.514")) << endl;
	cout << "====== Template Operation Test Ending ======" << endl << endl;
	/* Test for cbigmath */
	cout << "========== Test for cbigmath.h ==========" << endl;
	/* Polynomial Value Testing */
	cout << "====== Polynomial Value Testing ======" << endl;
  CBigNum x("114.514");
  CBigNum A[7] = {CBigNum(1), CBigNum(9), CBigNum(1), CBigNum(9),
	                CBigNum(8), CBigNum(1), CBigNum(0.1)};
  vector<CBigNum> AV;
  for (int i = 0; i <= 6; i++) {
  	AV.push_back(A[i]);
	}
  cout << "x is " << x << endl;
  cout << "1+9x+x^2+9x^3+8x^4+x^5+0.1x^6 = " << poly_value(x, A, 6) << endl;;
  cout << "1+9x+x^2+9x^3+8x^4+x^5+0.1x^6 = " << poly_value(x, AV) << endl;;
	cout << "====== Polynomial Value Test Ending ======" << endl << endl;
	/* Integer Power Testing */
	cout << "====== Integer Power Testing ======" << endl;
	cout << "(" << num2 << ") ^ (1)" << " = " << pow(num2, 1) << endl;
	cout << "(" << num2 << ") ^ (2)" << " = " << pow(num2, 2) << endl;
	cout << "(" << num2 << ") ^ (10)" << " = " << pow(num2, 10) << endl;
	cout << "(" << num2 << ") ^ (500)" << " = " << pow(num2, "500") << endl;
	num2.setResFracBits(64);
	cout << "(" << num2 << ") ^ (-1)" << " = " << pow(num2, -1) << endl;
	cout << "(" << num2 << ") ^ (-2)" << " = " << pow(num2, -2) << endl;
	cout << "(" << num2 << ") ^ (-10)" << " = " << pow(num2, -10) << endl;
	cout << "(" << num2 << ") ^ (-500)" << " = " << pow(num2, "-500") << endl;
	cout << "====== Integer Power Test Ending ======" << endl << endl;
	/* Sqrt Testing */
	cout << "====== nrt Testing ======" << endl;
	num2.setResFracBits(16);
	long long sqrtN = 2;
	cout << "sqrt(2, " << sqrtN << ")" << " = " << nrt(2, sqrtN) << endl;
	cout << "sqrt(3, " << sqrtN << ")" << " = " << nrt(3, sqrtN) << endl;
	cout << "sqrt(14.123456, " << sqrtN << ")" << " = " << nrt(14.123456, sqrtN) << endl;
	cout << "sqrt(" << num2 << ", " << sqrtN << ")" << " = " << nrt(num2, sqrtN) << endl;
	cout << "sqrt(123456.123, " << sqrtN << ")" << " = " << nrt(123456.123, sqrtN) << endl;
	cout << "sqrt(123456789876543211111111111111000000000000000, " << sqrtN << ")" << " = " << nrt("123456789876543211111111111111000000000000000", sqrtN) << endl;
	cout << "sqrt(1.23456, " << sqrtN << ")" << " = " << nrt(1.23456, sqrtN) << endl;
	cout << "sqrt(0.23456, " << sqrtN << ")" << " = " << nrt(0.23456, sqrtN) << endl;
	cout << "====== Sqrt Test Ending ======" << endl << endl;
	/* Ln Testing */
	cout << "====== Ln Testing ======" << endl;
	num2.setResFracBits(16);
	cout << "ln(2)" << " = " << ln(2) << endl;
	cout << "ln(3)" << " = " << ln(3) << endl;
	cout << "ln(14.123456)" << " = " << ln(14.123456) << endl;
	cout << "ln(" << num2 << ")" << " = " << ln(num2) << endl;
	cout << "ln(123456.123)" << " = " << ln(123456.123) << endl;
	cout << "ln(123456789876543211111111111111000000000000000)" << " = " << ln("123456789876543211111111111111000000000000000") << endl;
	cout << "ln(1.23456)" << " = " << ln(1.23456) << endl;
	cout << "ln(0.23456)" << " = " << ln(0.23456) << endl;
	cout << "====== Ln Test Ending ======" << endl << endl;
	/* Log Testing */
	cout << "====== Log Testing ======" << endl;
	num2.setResFracBits(16);
	CBigNum base(2);
	base.setResFracBits(16);
	cout << "log(2)(2)" << " = " << log(base, 2) << endl;
	cout << "log(2)(3)" << " = " << log(base, 3) << endl;
	cout << "log(2)(14.123456)" << " = " << log(base, 14.123456) << endl;
	cout << "log(2)(" << num2 << ")" << " = " << log(base, num2) << endl;
	cout << "log(2)(123456.123)" << " = " << log(base, 123456.123) << endl;
	cout << "log(2)(123456789876543211111111111111000000000000000)" << " = " << log(base, "123456789876543211111111111111000000000000000") << endl;
	cout << "log(2)(1.23456)" << " = " << log(base, 1.23456) << endl;
	cout << "log(2)(0.23456)" << " = " << log(base, 0.23456) << endl;
	cout << "====== Log Test Ending ======" << endl << endl;
	/* Triangular Functions Testing */
	cout << "====== Sin Testing ======" << endl;
	num2.setResFracBits(16);
	cout << "sin(2)" << " = " << sin(CBigNum(2)) << endl;
	cout << "sin(3)" << " = " << sin(CBigNum(3)) << endl;
	cout << "sin(-14.123456)" << " = " << sin(-14.123456) << endl;
	cout << "sin(" << num2 << ")" << " = " << sin(num2) << endl;
	cout << "sin(123456.123)" << " = " << sin(123456.123) << endl;
	cout << "sin(123456789876543211111111111111000000000000000)" << " = " << sin("123456789876543211111111111111000000000000000") << endl;
	cout << "sin(1.23456)" << " = " << sin(1.23456) << endl;
	cout << "sin(0.23456)" << " = " << sin(0.23456) << endl;
	cout << "====== Sin Test Ending ======" << endl << endl;
	cout << "====== Cos Testing ======" << endl;
	cout << "cos(2)" << " = " << cos(CBigNum(2)) << endl;
	cout << "cos(3)" << " = " << cos(CBigNum(3)) << endl;
	cout << "cos(-14.123456)" << " = " << cos(-14.123456) << endl;
	cout << "cos(" << num2 << ")" << " = " << cos(num2) << endl;
	cout << "cos(123456.123)" << " = " << cos(123456.123) << endl;
	cout << "cos(123456789876543211111111111111000000000000000)" << " = " << cos("123456789876543211111111111111000000000000000") << endl;
	cout << "cos(1.23456)" << " = " << cos(1.23456) << endl;
	cout << "cos(0.23456)" << " = " << cos(0.23456) << endl;
	cout << "====== Cos Test Ending ======" << endl << endl;
	cout << "====== Tan Testing ======" << endl;
	cout << "tan(2)" << " = " << tan(CBigNum(2)) << endl;
	cout << "tan(3)" << " = " << tan(CBigNum(3)) << endl;
	cout << "tan(-14.123456)" << " = " << tan(-14.123456) << endl;
	cout << "tan(" << num2 << ")" << " = " << tan(num2) << endl;
	cout << "tan(123456.123)" << " = " << tan(123456.123) << endl;
	cout << "tan(123456789876543211111111111111000000000000000)" << " = " << tan("123456789876543211111111111111000000000000000") << endl;
	cout << "tan(1.23456)" << " = " << tan(1.23456) << endl;
	cout << "tan(0.23456)" << " = " << tan(0.23456) << endl;
	cout << "====== Tan Test Ending ======" << endl << endl;
	cout << "====== Cot Testing ======" << endl;
	cout << "cot(2)" << " = " << cot(2) << endl;
	cout << "cot(3)" << " = " << cot(3) << endl;
	cout << "cot(-14.123456)" << " = " << cot(-14.123456) << endl;
	cout << "cot(" << num2 << ")" << " = " << cot(num2) << endl;
	cout << "cot(123456.123)" << " = " << cot(123456.123) << endl;
	cout << "cot(123456789876543211111111111111000000000000000)" << " = " << cot("123456789876543211111111111111000000000000000") << endl;
	cout << "cot(1.23456)" << " = " << cot(1.23456) << endl;
	cout << "cot(0.23456)" << " = " << cot(0.23456) << endl;
	cout << "====== Cot Test Ending ======" << endl << endl;
	/* Exp Functions Testing */
	cout << "====== Exp Testing ======" << endl;
	num2.setResFracBits(16);
	cout << "e^(2)" << " = " << exp(CBigNum(2)) << endl;
	cout << "e^(3)" << " = " << exp(CBigNum(3)) << endl;
	cout << "e^(-14.123456)" << " = " << exp(-14.123456) << endl;
	cout << "e^(" << num2 << ")" << " = " << exp(num2) << endl;
	cout << "e^(1234.123)" << " = " << exp(1234.123) << endl;
	cout << "e^(2345)" << " = " << exp("2345") << endl;
	cout << "e^(1.23456)" << " = " << exp(1.23456) << endl;
	cout << "e^(0.23456)" << " = " << exp(0.23456) << endl;
	cout << "====== Exp Test Ending ======" << endl << endl;
	/* Power Testing */
	cout << "====== Power Testing ======" << endl;
	num2.setResFracBits(16);
	base = 1.114;
	cout << "1.114^(2)" << " = " << pow(base, 2) << endl;
	cout << "1.114^(3)" << " = " << pow(base, 3) << endl;
	cout << "1.114^(-14.123456)" << " = " << pow(base, -14.123456) << endl;
	cout << "1.114^(" << num2 << ")" << " = " << pow(base, num2) << endl;
	cout << "1.114^(1234.123)" << " = " << pow(base,1234.123) << endl;
	cout << "1.114^(2345)" << " = " << pow(base,"2345") << endl;
	cout << "1.114^(1.23456)" << " = " << pow(base,1.23456) << endl;
	cout << "1.114^(0.23456)" << " = " << pow(base,0.23456) << endl;
	cout << "====== Power Test Ending ======" << endl << endl;
	/* Anti-Triangular Functions Testing */
	cout << "====== Arcsin Testing ======" << endl;
	cout << "arcsin(1)" << " = " << asin(1, PI) << endl;
	cout << "arcsin(0)" << " = " << asin(0, PI) << endl;
	cout << "arcsin(-1)" << " = " << asin(-1, PI) << endl;
	cout << "arcsin(-0.123456)" << " = " << asin(-0.123456, PI) << endl;
	cout << "arcsin(0.56789)" << " = " << asin(0.56789, PI) << endl;
	cout << "arcsin(0.1145141919810)" << " = " << asin("0.1145141919810", PI) << endl;
	cout << "====== Arcsin Test Ending ======" << endl << endl;
	cout << "====== Arccos Testing ======" << endl;
	cout << "arccos(1)" << " = " << acos(1, PI) << endl;
	cout << "arccos(0)" << " = " << acos(0, PI) << endl;
	cout << "arccos(-1)" << " = " << acos(-1, PI) << endl;
	cout << "arccos(-0.123456)" << " = " << acos(-0.123456, PI) << endl;
	cout << "arccos(0.56789)" << " = " << acos(0.56789, PI) << endl;
	cout << "arccos(0.1145141919810)" << " = " << acos("0.1145141919810") << endl;
	cout << "====== Arccos Test Ending ======" << endl << endl;
	cout << "====== Arctan Testing ======" << endl;
	cout << "arctan(2)" << " = " << atan(2, PI) << endl;
	cout << "arctan(3)" << " = " << atan(3, PI) << endl;
	cout << "arctan(-14.123456)" << " = " << atan(-14.123456, PI) << endl;
	cout << "arctan(" << num2 << ")" << " = " << atan(num2, PI) << endl;
	cout << "arctan(123456.123)" << " = " << atan(123456.123, PI) << endl;
	cout << "arctan(123456789876543211111111111111000000000000000)" << " = " << atan("123456789876543211111111111111000000000000000", PI) << endl;
	cout << "arctan(1.23456)" << " = " << atan(1.23456) << endl;
	cout << "arctan(0.23456)" << " = " << atan(0.23456) << endl;
	cout << "====== Arctan Test Ending ======" << endl << endl;
	cout << "====== Arccot Testing ======" << endl;
	cout << "arccot(2)" << " = " << acot(2) << endl;
	cout << "arccot(3)" << " = " << acot(3) << endl;
	cout << "arccot(-14.123456)" << " = " << acot(-14.123456) << endl;
	cout << "arccot(" << num2 << ")" << " = " << acot(num2) << endl;
	cout << "arccot(123456.123)" << " = " << acot(123456.123) << endl;
	cout << "arccot(123456789876543211111111111111000000000000000)" << " = " << acot("123456789876543211111111111111000000000000000") << endl;
	cout << "arccot(1.23456)" << " = " << acot(1.23456) << endl;
	cout << "arccot(0.23456)" << " = " << acot(0.23456) << endl;
	cout << "====== Arccot Test Ending ======" << endl << endl;
}

