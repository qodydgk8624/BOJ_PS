// BOJ - 18258 큐 2

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int cmd_n; cin >> cmd_n;
    queue<int> q;
    while(cmd_n--)
    {
        string cmd; cin >> cmd;
        if(cmd == "push")
        {
            int t; cin >> t;
            q.push(t);
        }
        else if(cmd == "pop")
        {
            if(q.size() == 0) cout << "-1\n";
            else 
            {
                cout << q.front() << '\n'; q.pop();
            }
        }
        else if(cmd == "size")
            cout << q.size() << '\n';
        else if(cmd == "empty")
            cout << q.empty() << '\n';
        else if(cmd == "front")
        {
            if(q.size() == 0) cout << "-1\n";
            else 
            {
                cout << q.front() << '\n';
            }
        }
        else if(cmd == "back")
        {
            if(q.size() == 0) cout << "-1\n";
            else 
            {
                cout << q.back() << '\n';
            }
        }
    }
}