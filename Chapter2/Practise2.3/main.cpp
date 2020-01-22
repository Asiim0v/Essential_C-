#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

inline bool pent_valid(int pos);
bool pent_seq(vector<int> &seq,int pos);
void display_pent(vector<int> &seq,const string &title,ostream &os = cout);

inline bool pent_valid(int pos)
{
	if(pos <= 0 || pos > 64)
	{
		cerr<<"Sorry. Invalid position: " << pos << endl;
		return false;	
	}
	else return true;
}

bool pent_seq(vector<int> &seq,int pos)
{
	if(pent_valid(pos))
	{
		for(int i=seq.size()+1;i<=pos;i++)
		{
			seq.push_back(i*(3*i-1)/2); 
		}
		return true;
	}	
	else return false;
}

void display_pent(vector<int> &seq,const string &title,ostream &os)
{
	os<<title<<endl;
	for(int i=0;i < seq.size();i++)
	{
		os<<setw(6)<<seq[i]<<' ';
		if(!((i+1)%10)) os<<endl;
	}	
}

int main()
{
	int num;
	vector<int> seq;
	const string title = "Pentagonal Numeric Series";
	cout<<"Please input the sequence size:";
	cin>>num;
	
	if(pent_seq(seq,num))
		display_pent(seq,title);
	
	return 0;
} 
