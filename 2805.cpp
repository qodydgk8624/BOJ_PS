// BOJ - 2805 나무 자르기

#include <iostream>
#define ll long long
#define MAXN 1000000 + 1
#define MAXK 2000000000 + 1

using namespace std;

ll n, k, ans = 0; ll tree[MAXN] = {0, };

ll max(ll a, ll b)
{
    return a > b ? a : b;
}

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

ll eval(ll val)
{
    ll ret = 0;
    for(int i = 0; i < n; i++)
        ret += (tree[i] > val) ? (tree[i] - val) : 0;
    return ret;
}
void parametric_search(ll s, ll e)
{
    while(s <= e)
    {
        ll m = (s + e) / 2;
        ll em = eval(m);
        if(em < k) e = m - 1;
        else
        {
            s = m + 1;
            ans = max(m, ans);
        }
        
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n >> k;

    ll maxtree = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> tree[i];
        maxtree = max(tree[i], maxtree);
    }

    parametric_search(0, maxtree);

    cout << ans;
}