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

## Chapter3. 泛型编程风格

> Standard Template Library(STL)主要由两种组件组成：一是容器(container)，包括vecotr、list、set、map等类；另一种组件是用以操作这些容器的所谓泛型算法(generic algorithm)，包括`find()`、`sort()`、`replace()`、`merge()`等。
>

- 容器分为**顺序性容器**(sequential container)和**关联容器**(associative container)。`vector`和`list`属于顺序性容器，会依次维护第一个、第二个······直到最后一个元素。顺序性容器身上主要进行所谓的**迭代(iterate)**操作。`map`和`set`属于关联容器，关联容器可以让我们快速查找容器中的元素值。
- `map`是一对对的`key/value`组合。*key*用于查找，*value*用来表示我们要储存或取出的数据。`set`其中仅含有`key`。我们对它进行查询操作，为的是判断其值是否存在于其中。
- 泛型算法提供了许多可作用于**容器类及数组类型**上的操作。这些算法之所以被称之为泛型(generic)，是因为它们和它们想要**操作的元素类型无关**，同样也和**容器类彼此独立**。 
- 泛型算法系通过**`function template`技术**，达到"与操作对象的类型相互独立"的目的。而实现"与容器无关"的诀窍，就是不要直接在容器身上进行操作。而是借由**一对iterator(`first`和`last`)**，标示我们要进行迭代的元素范围。

### 3.1 指针的算术运算

- 当数组被传给函数，或是由函数中返回，仅有**第一个元素的地址**会被传递。(数组名的二义性)
- 即使我们是通过指针来访问`array`的元素，我们也可以通过`subscript(下标)`运算符

> 所谓的下标操作就是将`array`的起始地址加上索引值，产生出某个元素的地址，然后该地址再被提领(dereference)以返回元素值
>
> ```c++
> 	//假设array表示一个int数组的第一个元素地址
> 	array[2] == *(array + 2)
>     //其中array+2表示的是指针的算术运算。在指针的算术运算中，会把"指针所指的类型"大小考虑进去
>     //当我们写下array[2]，指针的算术运算以及提领操作都会自动进行
> ```

- 通常数组最后一个元素的下一个地址，扮演着我们所说的标兵角色，用以指示我们的迭代操作何时完成
- 如果完成"不论`vector`的元素类型是什么，都能一一访问`vecotr`内的每个元素"？`vector`和`array`相同，都是以一块连续内存储存所有元素，所以我们可以用和`array`一样的处理方式，将一组用来表示"起始地址/结束地址"的参数传入`find()`。但是**切记、`vecotr`可以是空的，`array`则不然**。

> `begin()`函数中通常会加入判断`vector`是否为0的操作，并返回0或是`vecotr`第一个元素的地址；其对应函数`end()`，会返回0或是`vector`最后元素的下一个地址

- `list`也是一个容器。不同的是，`list`的元素**以一组指针相互链接：前向(*forward*)指针指向下一个(*next*)元素，后向(*backward*)指针指向上一个(*preceding*)元素**。**指针的算术运算并不适用于`list`**，因为指针的算术运算必须首先假设所有元素都储存在连续空间里，然后才能根据当前指针，加上元素大小之后，指向下一个元素。
- 对于`vector`和`list`它们的`find()`函数的底层指针工作方式，就标准语法而言的确大不相同；但事实上，除了参数列表之外，`find()`的实现内容一点也不需要改变。我们仅仅只需要**在底层指针的行为之上提供一层抽象，取代程序原本的"指针直接操作"方式，把底层指针的处理通通放在抽象层中**，便可以处理标准库所提供的所有容器类。

### 3.2 了解lterator(泛型指针)

- 上述抽象层的实现，借助C++的类机制来设计一组`iterator class`，让我们得以使用"和指针相同的语法"来进行程序的编写。
- 对于`list iterator`而言，其递增函数会沿着`list`的指针前进到下一个元素；对于`vector iterator`而言，其递增函数前进至下一个元素的方式，是将目前的地址加上一个元素的大小。本节先看看如何定义并使用标准容器的`iterator`
- 在定义`iterator`之前，我们首先应明确这份定义需要提供的信息有：(1)**迭代对象(某个容器)的类型**，这可用来决定如何访问下一个元素；(2)**`iterator`所指的元素类型**，这可决定`iterator`提领操作的返回值。

```c++
	vector<string> svec;
	//以下是标准库中的iterator语法
	//iter指向一个vector,后者的元素类型为string
	//iter一开始指向svec的第一个元素
	vector<string>::iterator iter = svec.begin();
```

> 双冒号【::】表示此`iterator`乃是位于`string vector`定义内的嵌套(nested)类型

- 对于`const vector`，我们使用`const_iterator`来进行遍历操作：

```c++
	const vector<string> cs_vec;
	vector<string>::const_iterator iter = cs_vec.begin();
```

> 预通过`iterator`取得元素值，我们可以采用一般指针的提领方式；如果要通过`iter`调用底部的`string`元素所提供的操作，我们可以使用`arrow`(箭头)运算符

### 3.3 所有容器的共通操作

> 下列为所有容器类(以及`string`类)的共通操作：

- equality( == ) 和 inequality( != ) 运算符，返回`true`或`false`
- assignment( = ) 运算符，将某个容器复制给另一个容器
- `empty()`会在容器无任何元素时返回`true`，否则返回`false`
- `size()`返回容器内目前持有的元素个数
- `clear()`删除所有元素
- `begin()`和`end()`，分别返回指向容器的第一个元素和最后一个元素的下一位置的`iterator`
- `insert()`将单一或某个范围内的元素插入容器内
- `erase()`将容器内的单一元素或某个范围内的元素删除

> `insert()`和`erase()`的行为视容器本身为顺序性容器或关联容器而有所不同

### 3.4 使用顺序性容器

- `vector`以一块连续内存来存放元素，`vector`内的每个元素都被储存在距离起始点的固定偏移位置上。**对`vector`进行随机访问颇有效率**；但如果**将元素插入任意位置**，而此位置不是`vector`的末端，**或者删除`vector`内最后一个元素以外的任意元素**，**效率将很低**。因为插入或删除位置右端的每个元素，都必须被复制一份，依次向右或向左移动。
- `list`系以双向链接(*double-linked*)而非连续内存来储存内容，可以执行前进或后退操作。**`list`中的每个元素都包含三个字段：`value`、`back`指针(指向前一个元素)、`front`指针(指向下一个元素)**。在`list`的**任意位置进行元素的插入或删除都颇具效率**，因为`list`本身只需要适当设定`back`指针和`front`指针即可。但如果要**对`list`进行随机访问操作，则效率不高**。

-  第三种顺序性容器是所谓的`deque`，`deque`的行为和`vector`很相似——都**以连续内存储存元素**。和`vector`不同的是，**`deque`对于最前端元素的插入和删除操作，效率更高；末端元素亦同**。如果我们需要在容器的最前端插入元素，并执行末端删除操作，那么`deque`便很理想。

定义顺序性容器对象的方式有五种：

1. 产生空的容器

   ```c++
   	list<string> slist;
   ```

2. 产生特定大小的容器。每个元素都以其默认值作为初值

   ```c++
   	list<int> ilist(1024);
   ```

3. 产生特定大小的容器，并为每个元素指定初值

   ```c++
   	vector<int> ivec(10,-1);
   ```

4. 通过一对`iterator`产生容器。这对`iterator`用来标示一整组作为初值的元素的范围

   ```c++
   	int ia[4] = {1,1,2,3};
   	vector<int> seq(ia,ia+4);
   ```

5. 根据某个容器产生出新容器。复制原容器内的元素，作为新容器的初值

   ```c++
   	list<string> slist;
   	list<string> slist2(slist);
   ```

### 3.5 使用泛型算法

下面为四种可能被我们采用的泛型搜索算法：

1. `find()`用于搜索**无序集合**中是否存在某值。如果找到目标，`find()`会返回一个`iterator`指向该值，否则返回一个`iterator`指向`last`
2. `binary_search()`用于**有序集合**的搜索。如果搜索到目标，就返回`true`；否则返回`false`
3. `count()`返回数值相符的元素数目
4. `search()`比对某个**容器内是否存在某个子序列**。如果存在，`search()`会返回一个`iterator`指向子序列起始处；如果不存在，就返回一个`iterator`指向容器末尾。

- 泛型算法`max_element()`，将一对`iterator`传给`max_element()`，它会返回该范围内的最大值
- `copy()`允许我们将容器复制一份，`copy()`接受两个`iterator`，标示出复制范围。第三个`iterator`指向复制行为的**目的地(也是个容器)的第一元素**，后续元素会被依次放入。

### 3.6 如何设计一个泛型算法

#### Function Object

- **所谓function object，是某种class的实例对象**，这类class对 function call 运算符做了重载操作，如此一来**可使function object被当成一般函数来使用**
- 利用`function object`来替代"通过函数指针来调用函数"主要是**为了效率**
- 标准库实现定义了一组`function object`，分为算术运算、关系运算和逻辑运算三大类。以下列表中的`type`在实际使用时会被替换为内置类型或`class`类型：

```c++
六个算术运算:
plus<type>,minus<type>,negate<type>,multiplies<type>,divides<type>,modules<type>
六个关系运算:			less<type>,less_equal<type>,greater<type>,greater_equal<type>,equal_to<type>,not_equal_to<type>
三个逻辑运算：
logical_and<type>,logical_or<type>,logical_not<type>
```

> 欲使用事先定义的`function object`，首先得包含头文件 #include <functional>

举个例子，默认情形下，`sort()`会使用底部元素的类型所提供的的`less-than`运算符，将元素升序排列。如果我们传入`greater_than function object`，元素就会以降序排列，调用方法如下：

```c++
	sort(vec.begin(),vec.end(),greater<int>());
```

其中的`greater<int>()`会产生一个未命名的`class template object`，传给`sort()`

#### Function Object Adapter

举个例子，`function object `中的`less<type>`期望外界传入两个值，如果第一个值小于第二个值返回`true`。但假如我们希望将每个元素都和用户所指定的数值进行比较，那么理想情况下，我们需要做的是**将`less<type>`转化为一个一元(*unary*)运算符**。这可以通过"**将该`function object`的第二个参数绑定(*bind*)至用户指定的数值**"来完成。标准库提供的**`adapter`(适配器)**便应此而生。

- `function object adapter`会对`function object`进行修改操作。所谓**`binder adapter`(绑定适配器)**会将`function object`的参数绑定至某特定值，使`binary function object`转化为`unary function object`
- 标准库提供了两个`binder adapter`: `bind1st`会将指定值绑定至第一操作数；`bind2nd`会将指定值绑定至第二操作数

```c++
	//bind2nd(less<int>(),val);
	//会把val绑定至less<int>的第二个参数上
	//于是，less<int>会将每个元素与val进行比较，如果比val要小返回true
```

- **另一个`adapter`是所谓的`negator`**，它会对`function object`的真伪值取反。`not1`可对`unary function object`的真伪值取反；`not2`可对`binary function object`的真伪值取反

```c++
	//not1(bind2nd(less<int>,10))
	//将10绑定至less<int>的第二个参数上，并对绑定后的function object的真伪值取反
	//当元素大于等于10时返回true
```

### 3.7 使用Map

- `map`被定义为一对(*pair*)数值，其中的`key`通常是个字符串，扮演索引的角色，另一个数值是`value`
- 定义`map`需要包含头文件`#include <map>`

```c++
	#include <map>
	#include <string>
	map<string,int> words;
	words["vermeer"] = 1;//输入key/value的最简单方式
	string tword;
	while(cin>>tword) words[tword]++;
	//words[tword]会取出与tword相应的value；如果tword不在map内，它会自动被放入map内，并获得默认值0
	map<string,int>::iterator it = words.begin();//map的遍历依然通过iterator
	for(; it != words.end(); ++it)
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
	//map对象有一个名为 first 的member,对应于key；另有一个名为 second 的member,对应于value
```

- 欲查询`map`内是否存在某个`key`，**不建议直接把`key`当成索引使用**：因为如果索引的`key`不在`map`内，这个`key`会被自动放入`map`中，而其`value`也会被设置为所属类型的默认值。
- 查询`map`**建议利用`map`的`find()`函数**(不要和泛型算法`find()`搞混)

```c++
	int count = 0;
	map<string,int>::iterator member;
	member = words.find("vermeer");//map的find()函数内放入key值
	if(member != words.end())
        count = member->second;
	//如果key在map中,find()会返回一个iterator,指向key/value形成的一个pair；反之会返回end()
```

- 另一种查询`map`的方法是**利用`map`的`count()`函数**。`count()`会返回特定项在`map`内的个数

```c++
	int count = 0;
	if(words.count("vermeer")) //ok,它存在
        count = words["vermeer"];
```

**注意：**任何一个`key`值在`map`内最多只会有一份。如果我们需要储存多份相同的`key`值，就必须使用`multimap`

### 3.8 使用Set

- `set`由一群`key`组合而成。如果我们想知道某值是否存在于某个集合内，就可以使用`set`
- 对于任何`key`值，`set`只能储存一份。(如果要储存多份相同的`key`值，必须使用`multiset`)
- 默认情况下，`set`元素皆依据**其所属类型默认的`less-than`运算符**进行排序，例如：

```c++
	int ia[10] = {1,3,5,8,5,3,1,5,8,1};
	vector<int> vec(ia,ia+10);
	set<int> iset(vec.begin(),vec.end());
	//得到的iset的元素将是{1,3,5,8}

	//如果要给set加入单一元素，可以使用单一参数的insert()
	iset.insert(ival);
	//如果要给set加入某个范围的元素，可以使用双参数的insert()
	iset.insert(vec.begin(),vec.end());
	//在set身上进行迭代，形式与map等相似
	set<int>::iterator it = iset.begin();
	for(; it != iset.end(); ++it)
        cout<< *it << " ";
	cout<<endl;
```

### 3.9 如何使用iterator insertor

- 所有"会对元素进行复制行为"的泛型算法，例如`copy()`、`copy_backwards()`、`remove_copy()`、`replace_copy()`、`unique_copy()`等等，每个算法都接受一个`iterator`，标示出复制的起始位置。每复制一个元素，都会被赋值(*assigned*)，`iterator`则会递增到下一个位置。因此，**我们必须保证在每一次复制操作中，目的端容器足够大，保证`iterator`处于一个合法的位置**。
- 为了解决每次总是传入某个固定大小的容器至上述算法中，标准库提供了三个所谓的**`insertion adapter`，**这些`adapter`让我们得以避免使用容器的`assignment`运算符：

1. `back_inserter()`会**以容器的`push_back()`函数取代`assignment`运算符**。对于`vector`来说，这是十分适合的`inserter`。传入`back_inserter()`的参数就是容器本身：

   ```c++
   	vector<int> result_vec;
   	copy(ivec.begin(),ivec.end(),back_inserter(result_vec));
   ```

2. `inserter()`会**以容器的`insert()`函数取代`assignment`运算符**。`inserter()`接受两个参数：一个是容器，另一个是**`iterator`，指向容器内的插入操作起点**。

   ```c++
   	vector<string> svec_res;
   	copy(svec.begin(),svec.end(),inserter(svec_res,svec_res.end()));
   ```

3. `front_inserter()`会以容器的`push_front()`函数取代`assignment`运算符。这个`front_inserter`只适用于`list`和`deque`：

   ```c++
   	list<int> list_clone;
   	copy(ilist.begin(),ilist_end(),front_inserter(list_clone));
   ```

> 欲使用上述三种`adapter`，需要包含头文件：`#include<iterator>`

**注意：**这些`adapter`并不能用在`array`上。**`array`并不支持元素插入操作。**

### 3.10 使用iostream iterator

- 标准库定义有供输入及输出使用的`iostream iterator`类，称为`istream_iterator`和`ostream_iterator`，分别支持**单一类型的元素**读取和写入。
- 使用这两个`iterator class`之前需要包含头文件`#include <iterator>`

- 如何利用`istream_iterator`**从标准输入设备读取字符串？**和所有的`iterator`一样，我们需要一对`iterator`：first 和 last，用来标示元素范围。


```c++
	istream_iterator<string> is(cin);
	//该定义为我们提供了一个first iterator,它将is定义为一个"绑定至标准输入设备"的istream_iterator
	//last iterator表示"要读取的最后一个元素的下一位置"。对于标准输入设备而言，end-of-file表示last
	//只要在定义istream_iterator的时候不为它指定任何istream对象，即表示了end-of-file，如下：
	istream_iterator<string> eof;
	//定义完一对iterator之后，我们将它们和储存字符串元素的vector，一起传给泛型算法copy()用作读取：
	vector<string> text;
	copy( is, eof, back_inserter(text));
```

- 对于输出，我需要一个`ostream_iterator`，标示字符串元素的输出位置：

```c++
	ostream_iterator<string> os(cout, " ");
	//该定义将os定义为一个"绑定至标准输出设备"的ostream_iterator
	//上述第二个参数可以是C-style字符串，也可以是字符串常量。它用来表示各个元素被输出时的分隔符，默认情况下，输出的各个元素间没有分隔符。
	copy( text.begin(), text.end(), os);//copy会将储存在text中的每个元素一一写到由os所表示的ostream上
```

- 通常我们不需要从标准输入设备进行读取，也不需要写到标准输出设备中。而是**更多的希望从文件中读取或是写入到文件中**。这时候，只需要将定义的`istream_iterator`绑定至`ifstream object`上，将`ostream_iterator`绑定至`ofstream object`上即可：

```c++
	ifstream in_file("input_file.txt");
	ofstream out_file("output_file.txt");
	
	istream_iterator<string> is(in_file);
	istream_iterator<string> eof;
	ostream_iterator<string> os(out_file, " ");
	vector<string> text;
	copy( is, eof, back_inserter(text)); //从file中读取至vector
	copy( text.begin(), text.end(), os); //从vector中写入至file
```

> [练习 3.1](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter3/Practice3.1/main.cpp)
>
> [练习 3.2](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter3/Practice3.2/main.cpp)
>
> [练习 3.3](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter3/Practice3.3/main.cpp)
>
> [练习 3.4](https://github.com/Asiim0v/Essential_Cplusplus/blob/master/Chapter3/Practice3.4/main.cpp)









