// BOJ - 1654 랜선 자르기

#include <iostream>
#define MAXN 10000 + 1
#define ll long long

using namespace std;

ll lan[MAXN] = {0, }; ll n, k, ans = 0;

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

ll eval(ll val)
{
    ll res = 0;
    for(ll i = 0; i < n; i++)
        res += (lan[i] / val);
    return res;
}

void parametric_search(ll start, ll end)
{
    while(start <= end)
    {
        ll mid = (start + end) / 2;
        ll eval_mid = eval(mid);
        if(eval_mid < k) end = mid - 1;
        else
        {
            start = mid + 1;
            ans = max(ans, mid);
        }
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> lan[i];

    parametric_search(0, 0x7FFFFFFFFFFFFFFF);

    cout << ans;
}