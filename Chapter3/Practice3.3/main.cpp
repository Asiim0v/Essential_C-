#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> family = {
        {"John", "Smith"},      {"Kevin", "Durant"}, {"Thierry", "Henry"},
        {"Dennis", "Bergkamp"}, {"David",""},        {"Roberto", "Carlos"}};

    string First_Name;
    map<string, string>::iterator it;
    while(true)
    {
        cout << "Please input the First Name u want to search or \'q\' to quit:";
        cin >> First_Name;
        if(First_Name == "q" || First_Name == "Q")
            break;
        else
        {
            it = family.find(First_Name);
            if(it != family.end())
            {
                if(it->second.empty())
                    cout << "The " << it->first << " Family has no child."
                         << endl;
                else
                    cout << "The " << it->first << " Family's child is called "
                        << it->first << " " << it->second << endl;
            }
            else
            {
                cout << "Sry! We don't find what u searched." << endl;
            }     
        }        
    }

    return 0; 
}