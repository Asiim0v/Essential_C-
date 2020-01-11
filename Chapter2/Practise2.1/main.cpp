#include <iostream>
using namespace std;

bool fibon_print(int pos,int &elem);

int main() {
    int pos,elem;
    bool next_try = true;
    char next_cin;
    while(next_try)
    {
        cout<<"Please enter a position:";
        cin>>pos;
        if(!fibon_print(pos,elem))
        {
            cout<<"Sorry.Could not calculate element # "<<pos<<endl;
        }
        cout<<"Want to try again?(Y/N):";
        cin>>next_cin;
        while(true)
        {
            if(next_cin == 'Y' || next_cin == 'y')
            {
                next_try = true;
                break;
            }
            else if(next_cin == 'N' || next_cin == 'n')
            {
                next_try = false;
                break;
            }
            else
            {
                cout<<"Sorry.Please input Y or N,try again(Y/N):";
                cin>>next_cin;
            }

        }
    }
    return 0;
}

bool fibon_print(int pos,int &elem)
{
    if(pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    cout<<"The Fibonacci Sequence for "
        <<pos<<" positions:"<<"\n\t";
    switch(pos)
    {
        default:
        case 2:
            cout<<"1 ";
        case 1:
            cout<<"1 ";
            break;
    }
    int n_2 = 1;int n_1 = 1;
    elem = 1;
    for(int i=3;i<=pos;i++)
    {
        elem = n_1 + n_2;
        n_2 = n_1; n_1 = elem;
        cout<<elem<<(!(i % 10)?"\n\t":" ");
    }
    cout<<endl<<"element # "<<pos<<" is "<<elem<<endl;
    return true;
}
