// BOJ - 10773 제로

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n; cin >> n;
    stack<int> s;
    while(n--)
    {
        int _t; cin >> _t;
        if(!_t)
            s.pop();
        else
            s.push(_t);
    }

    int sum = 0;
    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum;
}