// BOJ - 1395

#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<ll> a, tree, lazy;
void update_lazy(ll nd, ll s, ll e)
{
	if(lazy[nd] != 0)
	{
		tree[nd] = (e - s + 1) - tree[nd];
		if(s != e)
		{
			lazy[nd << 1] = !lazy[nd << 1];
			lazy[(nd << 1) | 1] = !lazy[(nd << 1) | 1];
		}
		lazy[nd] = 0;
	}
}
ll update(ll nd, ll s, ll e, ll l, ll r)
{
	update_lazy(nd, s, e);
	if(r < s | e < l) return tree[nd];
	if(l <= s & e <= r)
	{
		tree[nd] = (e - s + 1) - tree[nd];
		if(s != e)
		{
			lazy[nd << 1] = !lazy[nd << 1];
			lazy[(nd << 1) | 1] = !lazy[(nd << 1) | 1];
		}
		return tree[nd];
	}
	int m = (s + e) >> 1;
	return tree[nd] = update(nd << 1, s, m, l, r) + update((nd << 1) | 1, m + 1, e, l, r);
}
ll query(ll nd, ll s, ll e, ll l, ll r)
{
	update_lazy(nd, s, e);
	if(r < s | e < l) return 0;
	if(l <= s & e <= r) return tree[nd];
	ll m = (s + e) >> 1;
	return query(nd << 1, s, m, l, r) + query((nd << 1) | 1, m + 1, e, l, r);
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	a.resize(n); tree.resize(n*4); lazy.resize(n*4);
	
	while(m--)
	{
		int sel; cin >> sel;
		if(sel == 0)
		{
			int s, t; cin >> s >> t;
			update(1, 0, n - 1, s - 1, t - 1);
		}
		else
		{
			int s, t; cin >> s >> t;
			cout << query(1, 0, n - 1, s - 1, t - 1) << '\n';
		}
	}
}
