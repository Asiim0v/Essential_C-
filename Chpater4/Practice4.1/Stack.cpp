#include "Stack.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool Stack::push(const string &elem)
{
    if (full()) return false;
    _stack.push_back(elem);
    return true;
}

bool Stack::pop(string &elem)
{
    if (empty()) return false;

    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string &elem)
{
    if (empty()) return false;
    elem = _stack.back();
    return true;
}

int main()
{
    Stack  myStack;
    string str;
    // ifstream infile("read.txt");

    // Windows平台循环输入字符串跳不出循环解决办法：输入完数据后->回车->ctrl+z->回车
    while (cin >> str && !myStack.full())
        myStack.push(str);

    if (myStack.empty()) {
        cout << "\n"
             << "Oops: no strings were read\n";
        return 0;
    }

    myStack.peek(str);
    if (myStack.size() == 1 && str.empty()) {
        cout << "\n"
             << "Oops: no strings were read\n";
        return 0;
    }
    cout << "\n"
         << "Read in " << myStack.size() << " Strings!\n"
         << "The Strings in reverse order: \n";
    while (myStack.size()) {
        if (myStack.pop(str)) cout << str << " ";
    }
    cout << "\n"
         << "There are now " << myStack.size() << " elements in the stack\n";

    return 0;
}