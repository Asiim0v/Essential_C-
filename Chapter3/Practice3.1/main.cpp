#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    ifstream in_file("input_file.txt");
    if (!in_file) {
        cerr << "Unable to open the necessary file.\n";
        return -1;
    }

    set<string> word_exclusion{"a", "an", "or", "the", "and", "but"};
    string tword;
    map<string, int> words;
    while (in_file >> tword) {
        if (word_exclusion.count(tword))
            continue;
        words[tword]++;
    }

    bool search = true;
    char y_or_n;
    string search_word;
    while (search) {
        cout << "Whether u want to search any word in input_file.txt?(y/n):";
        cin >> y_or_n;
        if (y_or_n == 'y' || y_or_n == 'Y') {
            cout << "Please input the word u want to search:";
            cin >> search_word;
            if (words.count(search_word)) {
                cout << "The word u searched is in this file.\n";
            } else {
                cout << "Sry! The word u searched is not in this file.\n";
            }
        } else {
            search = false;
            break;
        }
    }

    map<string, int>::iterator it = words.begin();
    for (; it != words.end(); ++it) {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }

    return 0;
}