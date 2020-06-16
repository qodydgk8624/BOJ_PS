// BOJ - 10828 스택

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    stack<int> s;

    int t; cin >> t;
    while(t--)
    {
        string cmd; cin >> cmd;
        if(cmd == "push")
        {
            int push_val; cin >> push_val;
            s.push(push_val);
        }
        else if(cmd == "top")
            if(s.empty())
                cout << "-1\n";
            else
                cout << s.top() << '\n';
        else if(cmd == "size")
            cout << s.size() << '\n';
        else if(cmd == "empty")
            cout << s.empty() << '\n';
        else if(cmd == "pop")
        {
            if(s.empty())
                cout << "-1\n";
            else
            {
                cout << s.top() << '\n';
                s.pop();
            }
        }
    }
}