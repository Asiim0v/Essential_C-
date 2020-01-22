#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//ʹ�ú���template���������⣺call of overloaded ��max(int int)��is ambiguous
//��������ԭ��: max�������׼���std::max������ͻ��
//���������
//1������ʱ�������ֿռ䣬�� max(a,b);�ĳ� ::max(a,b);ǰ��::�������ͻ
//2���ı亯�����ƣ����Զ���ĺ��� max�ĳ� myMax��������

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

//����������У�����֪���Լ�д�ĺ��������׺ͱ�׼��������ļ���ĺ�����ͻ����ôC++����ô����������ͻ���أ�����õ��������ռ䡣

//���ƿռ���һ��c++�����ԣ�����������ڱ�д���ͳ����в�ͬ�ļ������̣�����ͬ���������⡣
//���磺�����ұ�д�ĺ���max�ͱ�׼��max��Ϊ���ܹ�׼ȷ��������һ��max()���������ǽ������������ֱ���ڲ�ͬ�������ռ䵥Ԫ�С�
//�����Ϳ����� "�����ռ�::������" �ķ�ʽ׼ȷ�������躯����

// ::max();//���õ��Լ�д��max()
// std::max();//���õı�׼ģ����max
//���Ǿ�����ʹ�� using namespace std; ���е�std��c++�ı�׼�����ռ䡣

//Ҫ�ó������std���������ַ���:

//1����using namespace std;���ں�������֮ǰ�����ļ������еĺ������ܹ�ʹ�������ռ�std����Ԫ�ء�
//2����using namespace std;�����ض��ں��������У��øú����ܹ�ʹ�������ռ�std��Ԫ�ء�
//3�����ض�������ʹ��using std::cout; �����ı���ָ��øú���ʹ�������ռ�std����ָ����Ԫ�أ��� cout�����ַ����ںô��ǣ���ֹ�Լ�����ı�������std����Ԫ�����ظ���
//4����ȫ��ʹ�ñ���ָ��using������Ҫʹ��std��Ԫ��ʱ��ʹ��ǰ׺std::��
//ͨ������ĵ�4�����������Ľ����������һ�֣����ǲ�ʹ�� using namespace std; ������cout,cin��һЩ��׼�Ŀ⺯���Ͳ���ʹ���ˣ�������õİ취���޸ĺ�������

