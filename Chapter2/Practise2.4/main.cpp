#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

inline bool pent_valid(int pos)
{
	return (pos <= 0 || pos > 64)?false:true;
}

void pent_cal(vector<int> &pent,int pos)
{
	cout<<"calculate"<<endl; 
	for(int i=pent.size()+1;i <= pos;i++)
	{
		pent.push_back(i*(3*i-1)/2);
	}
}

const vector<int> *pent_seq(int pos)
{
	static vector<int> pent;
	if(!pent_valid(pos))
		return 0;
		
	if(pent.size() < pos)
		pent_cal(pent,pos);
	
	return &pent;
}

bool pent_elem(const vector<int> *seq,int &elem,int pos)
{
	if(!seq)
	{
		elem = 0;
		return false;
	}
	elem = (*seq)[pos-1];
	return true;
}

int main()
{
	int pos,elem;
	cout<<"Please input the position:";
	cin>>pos;
	
	const vector<int> *seq = pent_seq(pos);
	if(!pent_elem(seq,elem,pos))
		cerr<<"Sorry. Invalid position: " << pos << endl;
	else
		cout<<"Position "<<pos<<" in Pentagonal is "<<elem<<endl;
	
	//测试static可以加一个while循环 
	
	return 0;
}
