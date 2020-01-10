//string对象
#if 1
#include <iostream>
#include <string>
using namespace std;

int main() {
    string user_name;
    const int name_cnt = 2;
    cout<<"Plz input your name:";
    while(cin>>user_name)
    {
        if(user_name.size() <= name_cnt)
        {
            cout<<"Your name is smaller than two chars,Plz input again:";
            continue;
        }
        else
        {
            cout<<"Hello! "<<user_name<<endl;
            break;
        }
    }
    return 0;
}
#endif

//C-style字符串
#if 0
#define user_name_size 128
#include <iostream>
#include <iomanip>
//#include <cstring>
using namespace std;

int name_count(const char* ptr)
{
    int count=0;
    while(*ptr++)
    {
        count++;
    }
    return count;
}

int main()
{
    char user_name[user_name_size];
    const int name_cnt = 2;
    cout<<"Plz input your name:";
    while(cin>>setw(user_name_size)>>user_name)
    {
        if(name_count(user_name) <= name_cnt)
        {
            cout<<"Your name is too small,Plz input again:";
            continue;
        }
        else if(name_count(user_name) == user_name_size-1)
        {
            cout<<"Your name is too long,maybe try to shorten it."<<endl;
            cout<<"Hi!"<<user_name<<endl;
            break;
        }
        else
        {
            cout<<"Hello! "<<user_name<<endl;
            break;
        }
    }
    return 0;
}
#endif