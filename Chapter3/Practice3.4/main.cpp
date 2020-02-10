#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    istream_iterator<int> is(cin);
    istream_iterator<int> eof;
    vector<int> text;
    //从标准输入设备读取时，windows平台通过Ctrl+D回车结束输入
    copy(is, eof, back_inserter(text));

    vector<int> text_odd;
    vector<int> text_even;
    ofstream odd_file("odd_num.txt");
    ofstream even_file("even_num.txt");
    if(!odd_file || !even_file)
    {
        cerr << "Unable to open the necessary file.\n";
        return -1;
    }   
    ostream_iterator<int> os_odd(odd_file, " ");
    ostream_iterator<int> os_even(even_file, "\n");

    vector<int>::iterator it = text.begin();
    for (; it != text.end(); ++it)
    {
        if((*it)%2)
            text_odd.push_back(*it);
        else
            text_even.push_back(*it);
    }

    copy(text_odd.begin(), text_odd.end(), os_odd);
    copy(text_even.begin(), text_even.end(), os_even);

    return 0; 
}