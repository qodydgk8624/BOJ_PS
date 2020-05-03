// BOJ - 10866 덱

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int cmd_n; cin >> cmd_n;
    deque<int> dq;
    while(cmd_n--)
    {
        string cmd; cin >> cmd;
        if(cmd == "push_front")
        {
            int x; cin >> x;
            dq.push_front(x);
        }
        else if(cmd == "push_back")
        {
            int x; cin >> x;
            dq.push_back(x);
        }
        else if(cmd == "pop_front")
        {
            if(dq.empty()) cout << "-1\n";
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back")
        {
            if(dq.empty()) cout << "-1\n";
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd == "size")
            cout << dq.size() << '\n';
        else if(cmd == "empty")
            cout << dq.empty() << '\n';
        else if(cmd == "front")
        {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.front() << '\n';
        }
        else if(cmd == "back")
        {
            if(dq.empty()) cout << "-1\n";
            else cout << dq.back() << '\n';
        }
    }
}