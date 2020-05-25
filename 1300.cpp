// BOJ - 1300 K번째 수

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, k; cin >> n >> k;

    ll s = 1, e = n * n; ll ans = 0;

    while(s <= e)
    {
        ll cnt = 0;
        ll m = (s + e) / 2;
        for(int i = 1; i <= n; i++) cnt += min(m / i, n);
        if(k > cnt) s = m + 1;
        else
        {
            ans = m;
            e = m - 1;
        }
    }

    cout << ans;
}

// O(NlgK)