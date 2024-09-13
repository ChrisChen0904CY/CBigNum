#include "cbignum.h"

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
	cout << "String Construction: " << num5 << " " << num6 << " " << num7 << endl;
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
	cout << "====== Int Division Test Ending ======" << endl << endl;
	/* Division Testing */
	cout << "====== Division Testing ======" << endl;
	num2.setResFracBits(16);
	cout << "(" << num2 << ") / (" << num8 << ")" << " = " << (num2 / num8) << endl;
	num3.setResFracBits(32);
	cout << "(" << num3 << ") / (" << num9 << ")" << " = " << (num3 / num9) << endl;
	cout << "(" << num2 << ") / (" << num3 << ")" << " = " << (num2 / num3) << endl;
	num9.setResFracBits(64);
	cout << "(" << num9 << ") / (" << num8 << ")" << " = " << (num9 / num8) << endl;
	cout << "(123.12) / (11.245) = " << (CBigNum(123.12) / CBigNum(11.245)) << endl;
	cout << "(-123.12) / (11.245) = " << (CBigNum(-123.12) / CBigNum(11.245)) << endl;
	cout << "====== Division Test Ending ======" << endl << endl;
}

