#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

class LessThan {
public:
	bool operator()( const string &s1, const string &s2 ) 
	               { return s1.size() < s2.size(); }
};

int main() {
    ifstream in_file("input_file.txt");
    if(!in_file)
    {
        cerr << "Unable to open the necessary file.\n";
        return -1;
    }

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;
    vector<string> text;
    copy(is, eof, back_inserter(text));

    string a, b;
    sort(text.begin(), text.end(), LessThan());

    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);

    return 0; 
}