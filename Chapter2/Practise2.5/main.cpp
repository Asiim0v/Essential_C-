#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline int max(int a,int b)
{
	return a>b?a:b;
}
inline float max(float a,float b)
{
	return a>b?a:b;
}
inline string max(const string& a,const string &b)
{
	return a>b?a:b;
}
inline int max(const vector<int> &seq)
{
	return *max_element(seq.begin(),seq.end());
}
inline float max(const vector<float> &seq)
{
	return *max_element(seq.begin(),seq.end());
}
inline string max(const vector<string> &seq)
{
	return *max_element(seq.begin(),seq.end());
}
inline int max(const int* iarr,int num)
{
	return *max_element(iarr,iarr+num);
}
inline float max(const float* farr,int num)
{
	return *max_element(farr,farr+num);
}
inline string max(const string* sarr,int num)
{
	return *max_element(sarr,sarr+num);
}

int main()
{
	int iarr[] = {12, 70, 2, 169, 1, 5, 29};
	vector<int> v_iarr(iarr,iarr+7);
	
	float farr[]={2.5, 24.8, 18.7, 4.1, 23.9};
	vector<float> v_farr(farr,farr+5);
	
	string sarr[]={"we", "were", "her", "pride", "of", "ten"};
	vector<string> v_sarr(sarr,sarr+6);
	
	int imax = max( max( v_iarr ), max( iarr, 7 ));
    float fmax = max( max( v_farr ), max( farr, 5 ));
    string smax = max( max( v_sarr ), max( sarr, 6 ));
    
    cout << "imax should be 169  -- found: " << imax << "\n"
	     << "fmax should be 24.8 -- found: " << fmax << "\n"
		 << "smax should be were -- found: " << smax << "\n";
	
	
	return 0;
}
