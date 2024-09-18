<div align="center">
	<p>
      <img width="50%" src="./Logo_Long_Width.png">
  </p>
	<a href="./README.md">中文</a>|<a href="./ReadMe_EN.md">English</a>
</div>

## 目录

- [0. 如何部署](#chapter-0)
- [1. 如何使用](#chapter-1)
- [2. 使用示范](#chapter-2)
- [3. 数据结构说明](#chapter-3)
- [4. 打赏渠道 & 联系邮箱](#chapter-4)

## <a id="chapter-0">0. 如何部署</a><a href="#">⬆️</a>

本开源库支持通过`CMake`进行本地部署安装，具体操作如下：

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
    <h3>Linux 部署说明</h3>
    <p>
      1. 首先，您需要克隆或下载本项目到本地。<br><br>
      2. 在本项目地址打开终端，执行以下命令：
    </p>
    <pre>
mkdir build
cd build
cmake ..
cmake --build .</pre>
		<p>
			3. 如果您希望将本大数库安装到您的系统环境中，请接着执行如下命令：
		</p>
		<pre>
cmake --install . </pre>
  </div>

  <div id="windowsV" style="display: none;">
    <h3>Windows 部署说明(有VS)</h3>
    <p>
      1. 首先，您需要克隆或下载本项目到本地。<br><br>
      2. 在本项目地址打开命令提示符 cd，执行以下操作：
    </p>
    <pre>
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019" -A x64
    </pre>
		<p>
			3. 接着请以VS打开构建出的 .sln 文件进行编译输出。
		</p>
		<p>
			4. 如果您希望将本大数库安装到您的系统环境中，请接着执行如下命令：
		</p>
		<pre>
cmake --install . </pre>
  </div>

<div id="windowsM" style="display: none;">
    <h3>Windows 部署说明(MinGW)</h3>
    <p>
      1. 首先，您需要克隆或下载本项目到本地。<br><br>
      2. 在本项目地址打开命令提示符 cmd，执行以下操作：
    </p>
    <pre>
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
    </pre>
		<p>
			3. 接着执行如下命令编译库
		</p>
	  <pre>mingw32-make</pre>
		<p>
			4. 如果您希望将本大数库安装到您的系统环境中，请接着执行如下命令：
		</p>
		<pre>
cmake --install . </pre>
  </div>
</div>

<br>

如果您只是希望短暂地使用本库，你可以直接将 `cbignum.h` 和 `cbignum.cpp` 两个文件复制到您的项目工程中，并直接调用即可：

```cpp
#include "cbignum.h"
```

## <a id="chapter-1">1. 如何使用</a><a href="#">⬆️</a>

### 1.1 实例化

本大数库支持多种类型的数据实例化方法，实例化的方法如下：

```cpp
CBigNum num(xxx);
```

此处 `xxx` 可以是以下类型的任意常量或变量：

| 数据类型                                  | 备注                                                        |
|:-------------------------------------:|:---------------------------------------------------------:|
| short; unsigned short                 | 无                                                         |
| int; unsigned int                     | 无                                                         |
| long int; unsigned long int           | 无                                                         |
| long long int; unsigned long long int | 无                                                         |
| float                                 | 无                                                         |
| double                                | 无                                                         |
| long double                           | 无                                                         |
| string                                | 需要是严格的浮点数或整数字符串，无法解析的字符串会按照默认构造实现。另外从字符串构造大数时会自动去除前缀和后缀零。 |
| vector\<char\>, vector\<char\>        | 前者代表整数部分数据，后者代表小数点部分数据，详见第三章解释                            |

### 1.2 运算支持

本开源库目前支持**四则运算**以及**四则运算的混合运算**，同时实现了**十进制上的左右移运算**以及**整除**和**取余**。同时支持各种**比较符**和**负号**的使用。

下表是关于各运算或操作的具体说明：

| 运算类型  | 运算符号或函数                                                           | 备注                                                                  |
|:-----:|:-----------------------------------------------------------------:|:-------------------------------------------------------------------:|
| 加法    | +, +=                                                             | 无                                                                   |
| 减法    | -, -=                                                             | 无                                                                   |
| 乘法    | *, *=                                                             | 无                                                                   |
| 除法    | /, /=                                                             | 不可以用零做分母，并且可以调用函数`void setResFracBits(long long bits);`来控制结果保留的小数位数 |
| 左移    | <<, <<=                                                           | 左移符号后只能跟随整数，负数的时候会视作右移                                              |
| 右移    | \>\>, >>=                                                         | 右移符号后只能跟随整数，负数的时候会视作左移                                              |
| 整除    | `pair<CBigNum, CBigNum> intDivision(const CBigNum& other) const;` | 返回一个pair，前者是整除的商，后者是余数且为浮点余数                                        |
| 取余    | %, %=                                                             | 返回浮点余数                                                              |
| 负号    | \-                                                                | 无                                                                   |
| 大小比较符 | >, >=, <, <=, ==, !=                                              | 无                                                                   |
| 绝对值   | `CBigNum abs(const CBigNum& num) const`                           | 无                                                                   |

### 1.3 输出支持

本大数类型实例化的对象可以直接通过 `cout` 输出，并且大数指针也可以直接输出。

## <a id="chapter-2">2. 使用示范</a><a href="#">⬆️</a>

- 实例化和输出

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

- 各种运算和比较符的使用

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

- 除法保留位数的控制

```CPP
/* 123 / 1.23456 */
num2.setResFracBits(16);
num2 / num8; // 99.6306376360808709
num2.setResFracBits(32);
num2 / num8; // 99.63063763608087091757387247278383
```

## <a id="chapter-3">3. 数据结构说明</a><a href="#">⬆️</a>

本项目用两个`vector<char>`数组来分别存储大数的整数部分和小数部分。以一个`bool`类型变量`positive`来标记大数的正负情况。另外每个大数还有一个`long long`类型的成员变量`resFracBits`用来控制该数做除数时商的小数点后保留位数。

## <a id="chapter-4">4. 打赏渠道 & 联系邮箱</a><a href="#">⬆️</a>

如果本开源库对您有帮助或启发，请在经济条件允许的情况下支持我一下吧！

<div style="text-align: center;"> 
	<img src="./SupportOnMe.jpg" alt="打赏二维码">
</div>

另外，如果您对本项目有任何建议、想法或疑惑请联系我的邮箱：

📫chrischanyedu@gmail.com
