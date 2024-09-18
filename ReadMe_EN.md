<div align="center">
	<p>
      <img width="50%" src="./Logo_Long_Width.png">
  </p>
	<a href="./README.md">中文</a>|<a href="./ReadMe_EN.md">English</a>
</div>

## Contents

- [0. How to Deploy](#chapter-0)
- [1. How to Use](#chapter-1)
- [2. Usage Examples](#chapter-2)
- [3. Data Structure Explanation](#chapter-3)
- [4. Donation Channels & Contact Email](#chapter-4)

## <a id="chapter-0">0. How to Deploy</a><a href="#">⬆️</a>

This open-source library supports local deployment installation via `CMake`, with the following steps:

<div style="position: relative; width: 96%; border: 1px solid #ccc; border-radius: 12px; padding: 10px;">
  <div style="position: absolute; top: 10px; right: 10px;">
    <label>
      <input type="radio" name="os" value="linux" checked onclick="document.getElementById('linux').style.display='block'; document.getElementById('windowsV').style.display='none';document.getElementById('windowsM').style.display='none';"> Linux
    </label>
    <label>
      <input type="radio" name="os" value="windowsV" onclick="document.getElementById('linux').style.display='none';document.getElementById('windowsM').style.display='none';document.getElementById('windowsV').style.display='block';"> Windows(With VS)
    </label>
		<label>
      <input type="radio" name="os" value="windowsM" onclick="document.getElementById('linux').style.display='none';document.getElementById('windowsV').style.display='none';document.getElementById('windowsM').style.display='block';"> Windows(With MinGW)
    </label>
  </div>

  <div id="linux" style="display: block;">
    <h3>Linux Deployment Instructions</h3>
    <p>
      1. First, clone or download this project locally.<br><br>
      2. Open the terminal in the project directory and run the following commands:
    </p>
    <pre>
mkdir build
cd build
cmake ..
cmake --build .</pre>
		<p>
			3. If you want to install this big number library into your system environment, continue with the following command:
		</p>
		<pre>
cmake --install . </pre>
  </div>

  <div id="windowsV" style="display: none;">
    <h3>Windows Deployment Instructions(with VS)</h3>
    <p>
      1. First, clone or download this project locally.<br><br>
      2. Open the Command Prompt cmd in the project directory and run the following operations:
    </p>
    <pre>
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A x64
    </pre>
		<p>
			3. Then open the generated .sln file in Visual Studio to compile the output.
		</p>
		<p>
			4. If you want to install this big number library into your system environment, continue with the following command:
		</p>
		<pre>
cmake --install . </pre>
  </div>

<div id="windowsM" style="display: none;">
    <h3>Windows Deployment Instructions(MinGW)</h3>
    <p>
      1. First, clone or download this project locally.<br><br>
      2. Open the Command Prompt cmd in the project directory and run the following operations:
    </p>
    <pre>
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
    </pre>
		<p>
			3. Then run the following command to compile the library:
		</p>
	  <pre>mingw32-make</pre>
		<p>
			4. If you want to install this big number library into your system environment, continue with the following command:
		</p>
		<pre>
cmake --install . </pre>
  </div>
</div>

<br>

If you only wish to use this library temporarily, you can directly copy the `cbignum.h` and `cbignum.cpp` files into your project and call them directly:

```cpp
#include "cbignum.h"
```

## <a id="chapter-1">1. How to Use</a><a href="#">⬆️</a>

### 1.1 Instantiation

This big number library supports multiple ways to instantiate data. The instantiation methods are as follows:

```cpp
CBigNum num(xxx);
```

Here `xxx` can be any constant or variable of the following types:

| Data Type                             | Note                                                                                                                                                                                                                                           |
|:-------------------------------------:|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| short; unsigned short                 | None                                                                                                                                                                                                                                           |
| int; unsigned int                     | None                                                                                                                                                                                                                                           |
| long int; unsigned long int           | None                                                                                                                                                                                                                                           |
| long long int; unsigned long long int | None                                                                                                                                                                                                                                           |
| float                                 | None                                                                                                                                                                                                                                           |
| double                                | None                                                                                                                                                                                                                                           |
| long double                           | None                                                                                                                                                                                                                                           |
| string                                | Must be a strictly formatted floating-point or integer string. Strings that cannot be parsed will follow the default constructor. Extra leading and trailing zeros will be automatically removed when constructing a big number from a string. |
| vector\<char\>, vector\<char\>        | The first represents the integer part data, the second represents the decimal part data, explained further in Chapter 3.                                                                                                                       |

### 1.2 Supported Operations

This open-source library currently supports **arithmetic operations** and **mixed arithmetic operations**, as well as **left and right shifts in decimal form**, **integer division**, and **modulo**. Various **comparison operators** and **negation** are also supported.

The table below provides specific descriptions of each operation:

| Operation Type   | Operator/Function                                                 | Note                                                                                                                                                 |
|:----------------:|:-----------------------------------------------------------------:|:----------------------------------------------------------------------------------------------------------------------------------------------------:|
| Addition         | +, +=                                                             | None                                                                                                                                                 |
| Subtraction      | -, -=                                                             | None                                                                                                                                                 |
| Multiplication   | *, *=                                                             | None                                                                                                                                                 |
| Division         | /, /=                                                             | Denominator cannot be zero, and you can use the function void setResFracBits(long long bits); to control the number of decimal places in the result. |
| Left Shift       | <<, <<=                                                           | Only integers can follow the shift operator. Negative numbers will be treated as right shifts.                                                       |
| Right Shift      | \>\>, >>=                                                         | Only integers can follow the shift operator. Negative numbers will be treated as left shifts.                                                        |
| Integer Division | `pair<CBigNum, CBigNum> intDivision(const CBigNum& other) const;` | Returns a pair of `CBigNum`, with the first being the integer quotient and the second being the floating-point remainder.                            |
| Modulo           | %, %=                                                             | Returns a floating-point remainder.                                                                                                                  |
| Negation         | \-                                                                | None                                                                                                                                                 |
| Comparison Ops   | >, >=, <, <=, ==, !=                                              | None                                                                                                                                                 |
| Absolute Value   | `CBigNum abs(const CBigNum& num) const`                           | None                                                                                                                                                 |

### 1.3 Output Support

Objects instantiated from the `CBigNum` type can be directly output via `cout`, and pointers to big numbers can also be directly output.

## <a id="chapter-2">2. Usage Examples</a><a href="#">⬆️</a>

- Instantiation and Output

```CPP
CBigNum num1; // 0
CBigNum num2(123); // 123
CBigNum num3(-556); // -556
CBigNum num4(0); // 0
CBigNum num5("0001.2345678900"); // 1.23456789
CBigNum num6("-123465789.987654321"); // -123456789.987654321
CBigNum num7("1..02"); // 0
CBigNum num8(1.23456); // 1.23456
CBigNum num9(-23456.123); // -23456.123
CBigNum num10(0.1); // 0.1
```

- Usage of Various Operations and Comparison Operators

```CPP
num1 + num2; // 123
num1 - num2; // -123
num1 * num2; // 0
num1 / num2; // 0
num1.intDivision(num2); // 0 123
num1 % num2; // 0
abs(num2); // 123
-num2; // 123
num2 << 1; // -1230
num2 << -1; // -12.3
num2 >> 1; // -12.3
num2 >> -1; // -1230
```

- Controlling Decimal Places in Division

```CPP
/* 123 / 1.23456 */
num2.setResFracBits(16);
num2 / num8; // 99.6306376360808709
num2.setResFracBits(32);
num2 / num8; // 99.63063763608087091757387247278383
```

## <a id="chapter-3">3. Data Structure Explanation</a><a href="#">⬆️</a>

The core data structure of the big number library is defined as follows:

- Stores integer part in `vector<char> ints`
- Stores fractional part in `vector<char> fracs`
- Bool type member `bool positive` denotes whether the big number is positive

## <a id="chapter-4">4. Donation Channels & Contact</a><a href="#">⬆️</a>

If this library has been helpful to you, you can donate to support this open-source project via the following donation channels. I appreciate your contributions and support!

<div style="text-align: center;"> 
	<img src="./SupportOnMe_Paypal.png" alt="Support QR Code">
</div>

Alternatively, you can email me at the email below with any questions or feedback you may have.

📫chrischanyedu@gmail.com
