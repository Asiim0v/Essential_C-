#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("test.txt");
    if(!infile)
    {
        cerr<<"Unable to open file-\"text.txt\""<<endl;
        return -1;
    }
    ofstream outfile("test_sort.txt");
    if(!outfile)
    {
        cerr<<"Unable to open file-\"test_sort.txt\""<<endl;
        return -1;
    }

    vector<string> file_string;
    string str_val;
    while (infile >> str_val)
    {
        file_string.push_back(str_val);
    }
    cout<<"Unsorted file:"<<endl;
    for(int i=0;i<file_string.size();i++)
    {
        cout<<file_string[i]<<" ";
    }
    cout<<"Sorted file:"<<endl;
    sort(file_string.begin(),file_string.end());
    for(int i=0;i<file_string.size();i++)
    {
        outfile<<file_string[i]<<" ";
        cout<<file_string[i]<<" ";
    }
    outfile<<endl;
    return 0;
}
