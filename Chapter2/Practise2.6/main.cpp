#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//使用函数template遇到的问题：call of overloaded ‘max(int int)’is ambiguous
//造成问题的原因: max函数与标准库的std::max函数冲突。
//解决方法：
//1、调用时声明名字空间，把 max(a,b);改成 ::max(a,b);前加::，避免冲突
//2、改变函数名称，把自定义的函数 max改成 myMax或其它。

template <typename Type>
inline Type max(Type t1,Type t2)
{
	return t1>t2?t1:t2;
}

template <typename Vec_Type>
inline Vec_Type max(const vector<Vec_Type> &seq)
{
	return *max_element(seq.begin(),seq.end());
}

template <typename Arr_Type>
inline Arr_Type max(const Arr_Type *arr,int num)
{
	return *max_element(arr,arr+num);
}

int main()
{
	int iarr[] = {12, 70, 2, 169, 1, 5, 29};
	vector<int> v_iarr(iarr,iarr+7);
	
	float farr[]={2.5, 24.8, 18.7, 4.1, 23.9};
	vector<float> v_farr(farr,farr+5);
	
	string sarr[]={"we", "were", "her", "pride", "of", "ten"};
	vector<string> v_sarr(sarr,sarr+6);
	
	int imax = ::max( ::max( v_iarr ), ::max( iarr, 7 ));
    float fmax = ::max( ::max( v_farr ), ::max( farr, 5 ));
    string smax = ::max( ::max( v_sarr ), ::max( sarr, 6 ));
    
    cout << "imax should be 169  -- found: " << imax << "\n"
	     << "fmax should be 24.8 -- found: " << fmax << "\n"
		 << "smax should be were -- found: " << smax << "\n";
	
	
	return 0;
}

//从这个错误中，我们知道自己写的函数名容易和标准库或其他文件里的函数冲突，那么C++是怎么处理函数名冲突的呢？这就用到了命名空间。

//名称空间是一项c++的特性，是用来解决在编写大型程序中不同文件（厂商）中相同变量名问题。
//例如：就像我编写的函数max和标准的max，为了能够准确调用其中一个max()函数，我们将这两个函数分别放在不同在命名空间单元中。
//这样就可以用 "命名空间::函数名" 的方式准确调用所需函数。

// ::max();//调用的自己写的max()
// std::max();//调用的标准模板库的max
//我们经常会使用 using namespace std; 其中的std是c++的标准命名空间。

//要让程序访问std有以下四种方法:

//1、将using namespace std;放在函数定义之前，让文件中所有的函数都能够使用命名空间std中在元素。
//2、将using namespace std;放在特定在函数定义中，让该函数能够使用命名空间std中元素。
//3、在特定函数中使用using std::cout; 这样的编译指令，让该函数使用命名空间std中所指定在元素，如 cout。这种方法在好处是，防止自己定义的变量名与std中在元素名重复。
//4、完全不使用编译指令using，在需要使用std中元素时，使用前缀std::。
//通过上面的第4条，这个问题的解决方法还有一种，就是不使用 using namespace std; ，但是cout,cin等一些标准的库函数就不能使用了，所以最好的办法是修改函数名。

