# Essential_Cplusplus

> 说明：笔记按照Essential C++(中文版)中章节与段落顺序记录重点语句

## Chapter1. C++编程基础

### 1.1 如何撰写C++程序

- 函数包含**四个部分**：返回值类型、函数名称、参数列表、函数体
- 类(class)是用户自定义的数据类型(user-defined data type)
- C++事先定义了一些基础数据类型：布尔值(Boolean)、字符(character)、整数(integer)、浮点数(floating point)
- 头文件用来声明该class所提供的各种操作行动。程序代码文件包含了这些操作行为的实现内容
- 语句(statement)是C++程序的**最小**独立单元
- 字符常量分为两类：第一类是可打印字符，例如英文字母(`'a'`、`'A'`)、数字、标点符号(`';'`、`'-'`)。另一类是不可打印字符，例如换行符(`'\n'`)或制表符(tab，`'\t'`)
- **using** 和 **namespace**都是C++中的关键字。**std**是标准库所驻的命名空间(namespace)的名称。标准库所提供的的任何事物(诸如string class以及cout、cin这两个iostream类对象)都被封装在命名空间std内
- 命名空间(namespace)是一种将库名称封装起来的方法，可以避免和应用程序发生命名冲突的问题

> [练习 1.1](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter1/Practise1.1/main.cpp)

### 1.2 对象的定义与初始化

- 定义对象，我们必须为它**命名**，并赋予其**数据类型**。对象名称不能以数字开头，区分大小写字母
- 初始化对象有两种语法。“**用assignment运算符(=)进行初始化**"这个操作系沿袭自C语言。如果对象属于内置类型或者对象可以单一值加以初始化，这种方式没有问题，例如：

```c++
	string sequence_name = "Fibonacci";
```

- 如果对象需要多个初值，便引入了处理"多值初始化"的**构造函数初始化语法**(constructor initialization syntax)

```c++
	#include <complex>
	complex<double> purei(0,7);
```

出现于complex之后的尖括号，表示complex是一个`template class`(模板类)，template class允许我们在"不必指明data member类型"的情况下定义class，使程序员得以直到使用template class时才决定真正的数据类型

- C++中被定义为`const`的对象，在获得初值之后，无法再有任何变动

### 1.3 撰写表达式

- 复合赋值运算符可以和每个算术运算符结合
- 可以利用小括号改变内置的运算符优先级
- flase在算术表达式中被视为0，true被视为1

### 1.4 条件语句和循环语句

- 关键字switch之后紧接着一个由小括号括住的表达式(对象名称也可视为表达式)，该表达式的值必须是整数形式

### 1.5 如何运用Array和Vector

- C++允许我们以内置的`array`(数组)类型或标准库提供的`vector`类来定义容器
- 要定义`array`，我们必须制定array的元素类型，还得给予array一个名称，并指定其尺度大小——亦即array所能储存的元素个数。array的大小必须是个常量表达式(constant expression)
- 定义`vector object`，我们必须包含vector头文件。vector是一个class template，所以我们必须在类名之后的尖括号内指定其元素类型，其大小则写在小括号中

```c++
	#include <vector>
	vector<int> pell_seq(18);
```

无论array或vector，我们都可以指定容器中的某个位置，进而访问该位置上的元素

- vector相较于array，可以借助`.size()`知道自己的大小是多少

### 1.6 指针带来弹性

- 指针内含某特定类型对象的内存地址

- 如果要访问一个由指针所指的对象，我们必须对该指针进行**提领(dereference)**操作——也就是取得"位于该指针所指内存地址上"的对象。在指针之前使用*号，便可以达到这个目的

- 指针具有的双重特性：既可以让我们操作指针包含的**内存地址**；也可以让我们操作指针所指的**对象值**

- 指针可能并不指向任何对象。当我们写*pi时，如果`pi`定位到某个对象，则对`pi`进行提领(dereference)操作没有错误。但如果`pi`不指向任何对象，则提领`pi`会导致未知的执行结果

- 一个未指向任何对象的指针，其地址值为0. 有时候我们称之为`null`指针

  > 欲检验某指针是否为`null`，我们通常使用逻辑运算符`NOT`:
  >
  > ```c++
  > if(!pi) //当pi值为0时，此表达式方为true
  > ```
  >
  > 通常指针具有以下形式：
  >
  > `type_of_object_pointed_to * name_of_pointer_object`

- `rand()`和`srand()`都是标准库提供的所谓伪随机数(pseudo-random number)生成器。`srand()`的参数是所谓随机数生成器种子(seed)。每次调用`rand()`，都会返回一个介于0和"`int`所能表示的最大整数"间的一个整数。这两个函数的声明位于`cstdlib`头文件

- 使用`class object`的指针，和使用内置类型的指针略有不同。这是因为`class object`关联了一组我们可以调用的操作——通过`dot`成员选择运算符进行调用。因而如果要通过指针来选择操作，必须改用`arrow`(而非`dot`)成员选择运算符。同时，如果要使用`[]`下标运算符，我们必须先对指针提领(注意下标运算符的优先级更高)。例如：

  ```c++
  	vector<int> *pv = 0;
  	//...
  	if(pv && !pv->empty() && ((*pv)[1] == 1))
  ```

### 1.7 文件的读写

- 要对文件进行读写操作，首先得包含`fstream`头文件 `#include <fstream>`

- 为了打开一个可供输出的文件，我们定义一个`ofstream`(供输出用的 file stream)对象

  > 声明outfile时，如果指定的文件并不存在，便会有一个文件被产生出来并打开供输出使用。如果指定的文件已经存在，这个文件会被打开用于输出，而文件中原有的数据会被丢弃，如果我们只是希望将新数据增加到该文件中，那我们必须以追加模式(append mode)打开这个文件：在定义`ofstream`对象时提供第二个参数`ios_base::app`

在进行写入操作之前，我们必须确定文件的确打开成功，最简单的方法是检验`class object`的真伪，如果文件未能成功打开，我们可以将信息写入`cerr`并告知用户。**`cerr`代表标准错误设备(standard error)。和`cout`一样，`cerr`将其输出结果定向到用户的终端。两者的唯一差别是，`cerr`的输出结果并无缓冲(bufferred)情形——它会立即显示于用户终端中。**

- 如果要打开一个可供读取的文件，我们就定义一个`ifstream`(供输入的 file stream)对象，并将文件名传入

- 如果想要同时读写同一个文件，我们得定义一个`fstream`对象

  > 当我们以追加模式来打开档案，文件位置会位于末尾，同时任何的写入操作将会将数据添加在文件末尾。如果我们没有先重新定位，就试着读取文件内容，那么立刻会遇上"文件结束"的状况。

- `.seekg()`可将我们定义的`fstream`对象重新定位至文件的起始处

> [练习 1.5](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter1/Practise1.5/main.cpp)
>
> [练习 1.6](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter1/Practise1.6/main.cpp)
>
> [练习 1.7](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter1/Practise1.7/main.cpp)



## Chapter2. 面向过程的编程风格

> 将函数独立出来的做法可带来 ***三个*** 主要好处：第一、以一连串函数调用操作，取代重复编写相同的程序代码，可使程序更容易读懂。第二、我们可以在不同的程序中使用这些函数。第三、我们可以更容易地将工作分配给协作开发团队。

### 2.1 如何编写函数

- 函数必须先被声明，然后才能被调用(使用)。函数的声明让编译器得以检查后续出现的使用方式是否正确——是否有足够的参数、参数类型是否正确等等
- 当用户输入一个不合理的参数时，程序应该怎么处理？最极端的做法是终止整个程序。标准库的`exit()`函数可以派上用场，我们传一个值给`exit()`，此值将成为程序结束时的状态值。`exit()`需要包含`cstdlib`头文件。这种方式太过激烈，另一种方法是**抛出异常**。
- 我们可以通过**传址(pass by reference)**的方式定义函数以实现从一个函数中**返回两个值**

```c++
	bool fibon_elem(int pos, int &elem);
```

- 如果函数的返回类型不为`void`，那么它必须在每个可能的退出点上将值返回。函数中的每条`return`语句都被用来明确表示该处就是函数的退出点。如果函数体的最后一条语句不是`return`，那么最后一条语句之后便是该函数的隐式退出点。`return`语句的第二种形式不返回任何数值。这种形式只在返回值为`void`时才会被使用，它用来提前结束函数的执行。

> [练习 2.1](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter2/Practise2.1/main.cpp)

### 2.2 调用函数

- 参数传递的两种方式：**传址**(by reference)及**传值**(by value)

- 当我们调用一个函数时，会在内存中建立起一块特殊区域，称为"**程序堆栈**(program stack)"。这块特殊区域提供了**每个函数参数**的存储空间。它也提供了函数所定义的**每个对象**的内存空间——我们将这些对象称为`local object`(**局部对象**)。一旦函数完成，这块内存就会被释放掉，或者说从程序堆栈中被`pop`出来

- 当我们通过**传值**的方式将对象传入函数时，默认情形下其值会被复制一份，成为**参数的局部性定义**(local definition)，因而我们传入的对象和在函数内操作的对象其实是没有任何关系的两组对象
- 为了让函数内的参数和传入的实际对象产生关联，我们需要通过所谓的**传址**，要达成这个目的，最简单的做法便是**将参数声明为一个reference**

#### Pass by Reference 语义

> 本质复制的是传入对象的地址

- 只要在类型名称和reference名称之间插入`&`符号，便是声明了一个reference

```c++
	int ival = 1024;	
	int &rval = ival;
```

- C++不允许我们改变reference所代表的对象，一经声明它们必须从一而终

- **重点：面对`reference`的所有操作都和面对"`reference`所代表的对象"所进行的操作一般无二**

- 当我们以 `by reference`的方式将对象作为函数参数传入时，对象本身并不会复制出另一份——**复制的是对象的地址**。函数中对对象进行的任何操作，都相当于是**对传入的对象进行间接操作**

- 将参数声明为reference的理由一是：**希望得以直接对所传入的对象进行修改**。二是，**降低复制大型对象的额外负担**。

> 例如我打算将要显示的vector以传值的方式传入`display()`中。这意味着每当我想进行显示操作时，vector内所有的元素都会被复制。这并不会造成错误。但是如果直接传入vector的地址，速度会更快

- 我们也可以以`pointer`的形式传递参数。这和以`reference`传递的效果相同：传递的都是对象地址，而不是整个对象的副本。唯一差别在于两者的用法不同
- `pointer`参数和`reference`参数之间更重要的差异是，`pointer`可能(也可能不)指向某个实际对象。当我们提领`pointer`时，一定要先确定其值并非0。至于`reference`，则必定会代表某个对象，所以不需要做此检查
- 在传递**内置类型**时，除非你希望在函数内更改参数值，否则建议不要使用传址方式。传址机制主要用于传递`class object`

#### 作用域及范围

- 函数内定义的对象，只存在于函数执行期间。函数是暂时位于程序堆栈之上。局部对象就放在这块区域中。当函数执行完毕，这块区域的内容便会被弃置。于是局部对象不复存在。
- 为对象分配的内存，其**存活时间**称为储存期(storage duration)或**范围(extent)**。函数内定义的对象具有局部性范围(local extent)
- 对象在程序内**存活的区域**称为该对象的**scope(作用域)**。如果某个对象仅具有local scope(局部作用域)，其名称在local scope之外便不可见
- 对象如果在函数以外声明，具有所谓的file scope。对象如果拥有file scope，从其声明点至文件末尾都是可见的。file scope内的对象也具备所谓的static extent，意即该对象的内存在`main()`开始执行之前便已经分配好了，可以一直存在至程序结束
- **内置类型的对象**，如果**定义在file scope之内，必定被初始化为0**。但如果它们被定义于local scope之内，那么除非程序员指定其初值，否则不会被初始化

#### 动态内存管理

- 不论**local scope**或**file scope**，对我们而言，都是由**系统自动管理**。第三种储存期形式称为**dynamic extent(动态范围)**。其内存系由**程序的空闲空间**(free store)分配而来，有时也称为**heap memory(堆内存)**。这种内存必须由程序员自行管理，其分配系通过`new`表达式来完成，而其释放则通过`delete`表达式完成

```c++
	int *pi;
	pi = new int; //由heap分配出一个类型为int的对象，再将地址赋值给pi
	int *pia = new int[24]; //由heap分配一个数组，拥有24个整数.pia被初始化为数组第一个元素的地址，数组中的每个元素都未经初始化
```

- 由heap分配而来的对象，被称为具有dynamic extent。因为它们是在运行时通过`new`表达式分配来的，因此可以持续存活直到以`delete`表达式加以释放为止

```c++
	delete pi;
	delete [] pia;//删除数组中的所有对象，必须在数组指针和delete表达式之间加上一个空的下标运算符
```

- **如果因为某种原因，程序员不想使用**`delete`**表达式，由heap分配而来的对象就永远不会被释放。这称为**`memory leak`**(内存泄漏)**

### 2.3 提供默认参数值

> 一般的程序编写法则是，以"参数传递"作为函数间的沟通方式，比"直接将对象定义于file scope"更适当

- C++允许我们为全部或部分参数设定默认值

- 关于默认参数值有两个不是很直观的规则。第一个规则是，默认值的解析(resolve)操作由**最右边**开始进行。第二个规则是，**默认值只能够指定一次**，可以在函数声明处， 亦可以在函数定义处，但不能够在两个地方都指定。

- 函数的定义通常被放在程序代码文件，该文件**只被编译一次**，当我们想要使用该函数时，会将它链接(link)到我们的程序中来。因而，**头文件可为函数带来更高的可见性**(visiblity)
- 为了更高的可见性，我们决定**将默认值放在函数声明处**而非定义处

### 2.4 使用局部静态对象

- 为了节省函数间的通信问题而将对象定义于file scope内，永远都是一种冒险。通常，file scope对象会打乱不同函数间的**独立性**，使它们难以理解。
- 局部静态对象所处的内存空间，即使在不同的函数调用过程中，依然持续存在。不会像以前一样在每次函数被调用时就被破坏又被重新建立。因此我们现在可以安全地定义的局部静态对象的地址返回

### 2.5 声明inline函数

- 将函数声明为`inline`，表示要求编译器在每个函数调用点上，将函数的内容展开。面对一个`inline`函数，编译器可将该函数的调用操作改为**以一份函数代码副本代替**。

- 将函数指定为`inline`，只是对编译器提出的一种要求。编译器是否执行这项请求，需视编译器而定。(`inline`仅仅是一种请求而没有强制性)
- 一般而言，最适合声明为`inline`的函数：**体积小**，**常被调用**，**所从事的计算并不复杂**
- **`inline`函数的定义，常常被放在头文件中。**由于编译器必须在它被调用时加以展开，所以这个时候其定义必须是有效的。

### 2.6 提供重载函数

> 函数重载(function overloading)机制：使得参数列表(parameter list)不相同(可能是参数类型不同，可能是参数个数不同)的两个或多个函数，可以拥有相同的函数名称

- 编译器无法根据函数**返回类型**来区分两个具有相同名称的函数

### 2.7 定义并使用模板函数

> function template(函数模板)提供了这样一种机制，让我们得以将单一函数的内容与希望显示的各种vector类型绑定(bind)起来

- function template将参数列表中**指定的全部(或部分)参数的类型信息**抽离出来
- function template以**关键字`template`**开场，其后紧接着以成对尖括号(`< >`)包围起来的一个或多个**标识符**。这些**标识符用以表示我们希望推迟决定的数据类型**。用户每次利用这一模块(template)产生函数，都必须提供确实的类型信息。这些标识符事实上扮演着**占位符**的角色，用来放置函数参数列表及函数体中的某些实际数据类型

```c++
	template <typename elemType>
	void display_message(const string &msg, const vector<elemType> &vec)
	{
     	cout<<msg;
        for(int ix=0; ix<vec.size(); ++ix)
        {
            elemType t = vec[ix];
            cout<< t << ' ';
        }
    }
```

> 关键字`typename`表示，`elemType`在`display_message()`函数中是一个暂时放置类型的占位符。`elemType`只是一个任意名称。在这个例子中我们希望推迟指定要显示的`vector`的元素类型，因此把`elemType`放在`vector`的尖括号内。

- 使用function template的方式看起来和普通函数极为相似

```c++
	vector<int> ivec;
	string msg;
	display_message(msg, ivec);
```

> 编译器会将`elemType`绑定(bind)为`int`类型，然后产生一份`display_message()`函数实例，于是其第二参数的类型即变成`vector<int>`。

- 当然，function template同时也可以是重载函数

```c++
	template <typename elemType>
	void display_message(const string &msg, const vector<elemType> &vec);	
	
	template <typename elemType>
	void display_message(const string &msg, const list<elemType> &lt)
```

### 2.8 函数指针带来更大的弹性

> 所谓函数指针(pointer to function)，它必须指明其所指函数的返回类型及参数列表。此外，函数指针的定义必须将`*`放在某个位置，表示这份定义所表现的是一个指针。最后再给予一个名称。

```c++
	const vector<int>* (*seq_ptr)(int);
```

`seq_ptr`现在可以指向"具有所列返回类型及参数列表"的**任何一个函数**，我们也可以给予函数指针初值。如果初值为0，表示并未指向任何函数；也可以拿某个函数的地址作为函数指针的初值(**在C++中，只要提供函数名称就可以取得函数的地址**)。

由函数指针指向的函数，其调用方式和一般函数相同：

```c++
	const vector<int> *pseq = seq_ptr(pos);
```

### 2.9 设定头文件

> 头文件的拓展名，习惯上是`.h`，标准库例外，它们没有扩展名。

- 函数的定义只能有一份。但可以有许多份声明。我们不把函数的定义放入头文件，因为同一个程序的多个代码文件可能都会包含这个头文件
- 但"**函数只能定义一份**"的规则有个**例外：`inline`函数的定义**。为了能够扩展`inline`函数的内容，**在每个调用点上，编译器都得取得其定义**。这意味着我们**必须将`inline`函数的定义放在头文件中**，而不是把它放在各个不同的程序代码文件中。

- 在file scope内定义的对象，如果可能被多个文件访问，就应该被**声明于头文件**中。和函数一样，**一个对象只能在程序中被定义一次**。对象的定义与函数定义一样，**必须放在程序代码文件中**。在其他文件中以声明出现，只要在定义前加上关键字`extern`

- 同时，`const object`和`inline`函数一样，是**"一次定义"规则**下的例外。**`const object`的定义只要一出文件之外便不可见。这意味着我们可以在多个程序代码文件中加以定义**，不会导致任何错误。

最后！头文件为什么有时是用双引号(" ")，有时又是尖括号(< >)括起来呢？

> 如果此文件被认定为**标准的或是项目专属的**头文件，我们便以尖括号将文件名括起来；编译器搜索此文件时，会**先在某些默认的磁盘目录中寻找**。如果文件名由成对的双引号括住，此文件便被认为是一个**用户提供的**头文件；搜索此文件时，会由**要包含此文件的文件所在的磁盘目录**开始找起。

> [练习 2.2](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter2/Practise2.2/main.cpp)
>
> [练习 2.3](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter2/Practise2.3/main.cpp)
>
> [练习 2.4](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter2/Practise2.4/main.cpp)
>
> [练习 2.5](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter2/Practise2.5/main.cpp)
>
> [练习 2.6](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter2/Practise2.6/main.cpp)











