//数据放入array
#if 0
#define arr_size 128
#include <iostream>
using namespace std;

int main() {
    int num_arr[arr_size];
    int num_cnt = 0,num_val;
    long long num_sum = 0;
    long double num_ave = 0;
    while(cin >> num_val && num_cnt < arr_size)
    {
        num_arr[num_cnt++] = num_val;
    }
    for(int i=0;i < num_cnt;i++)
    {
        num_sum += num_arr[i];
    }
    num_ave = (long double)num_sum/num_cnt;
    cout<<"sum:"<<num_sum<<"  ave:"<<num_ave<<endl;
    return 0;
}
#endif

//数据放入vector
#if 1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num_vect;
    int num_val = 0;
    while(cin >> num_val)
    {
        num_vect.push_back(num_val);
    }
    long long sum = 0;
    long double ave = 0;
    for(int i=0;i<num_vect.size();i++)
    {
        sum += num_vect[i];
    }
    ave = (long double)sum/num_vect.size();
    cout<<"sum:"<<sum<<"  ave:"<<ave<<endl;
    return 0;
}
#endif
