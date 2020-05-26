// BOJ - 12738 가장 긴 증가하는 부분 수열 3

#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    ll n; cin >> n;
    ll ans = 0; vector<int> v;

    v.push_back(-1000000001);

    for(int i = 0 ; i < n; i++)
    {
        ll t; cin >> t;
        if(t > v.back())
        {
            ans++; v.push_back(t);
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), t);
            *it = t;
        }
    }

    cout << ans;
}