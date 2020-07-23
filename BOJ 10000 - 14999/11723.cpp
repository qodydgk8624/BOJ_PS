// BOJ - 11723 집합

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    unsigned int number = 0;

    int m; cin >> m;
    for(int i = 0; i < m; i++)
    {
        string cmd; cin >> cmd;
        int k;
        if(cmd == "add")
        {
            cin >> k;
            number |= (1 << k);
        }
        else if(cmd == "remove")
        {
            cin >> k;
            number &= ~(1 << k);
        }
        else if(cmd == "check")
        {
            cin >> k;
            cout << !!(number & (1 << k)) << '\n';
        }
        else if(cmd == "toggle")
        {
            cin >> k;
            number ^= (1 << k);
        }
        else if(cmd == "all")
            number = (1 << 21) - 1;
        else if(cmd == "empty")
            number = 0;
    }
}