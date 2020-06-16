// BOJ - 14003 가장 긴 증가하는 부분 수열 5

#include <iostream>
#include <vector>
#include <stack>

#define ll long long

using namespace std;

struct p {
    ll f, s;
};
int main()
{
    ll n; cin >> n;
    ll ans = 0; vector<int> v; vector<p> path;

    v.push_back(-1000000001);

    for(int i = 0 ; i < n; i++)
    {
        ll t; cin >> t;
        if(t > v.back())
        {
            v.push_back(t);
            path.push_back({ans, t}); ans++;
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), t);
            path.push_back({it - v.begin() - 1, t});
            *it = t;
        }
    }
    
    cout << ans << '\n';

    stack<int> s;
    int idx = ans - 1;
    for(int i = n - 1; i >= 0; i--)
        if(path[i].f == idx)
        {
            s.push(path[i].s); idx--;
        }

    while(!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}