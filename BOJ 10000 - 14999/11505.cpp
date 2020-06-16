// BOJ - 11505

#include <iostream>
#include <vector>

#define ll long long
#define MOD 1000000007

using namespace std;

vector<ll> a;
vector<ll> tree;

int n, m, k;

ll init(int nd, int s, int e)
{
	if(s == e) return tree[nd] = a[s];
	int m = (s + e) / 2;
	return tree[nd] = init((nd << 1), s, m)
		* init((nd << 1) + 1, m + 1, e) % MOD;
}
ll update(int nd, int s, int e, int i, int val)
{
	if(e < i | i < s) return tree[nd];
	if(s == e) return tree[nd] = val;
	int m = (s + e) >> 1;
	return tree[nd] = update(nd << 1, s, m, i, val) * 
	update((nd << 1) | 1, m + 1, e, i, val) % MOD;
}
ll query(ll nd, ll s, ll e, ll l, ll r)
{
	if(l > e | s > r) return 1;
	if(l <= s & e <= r) return tree[nd] % MOD;
	int m = (s + e) / 2;
	return query(nd << 1, s, m, l, r)
		* query((nd << 1) | 1, m + 1, e, l, r) % MOD;
}
int main()
{
	cin >> n >> m >> k;
	m += k;
	a.resize(n); tree.resize(n * 4);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	init(1, 0, n-1);
	
	while(m--)
	{
		ll sel; cin >> sel;
		if(sel == 1)
		{
			ll idx, change;
			cin >> idx >> change; idx -= 1;
			a[idx] = change;
			update(1, 0, n-1, idx, change);
		}
		else
		{
			ll start, end;
			cin >> start >> end; start -= 1, end -= 1;
			cout << query(1, 0, n-1, start, end) << '\n';
		}
	}
	
	
}
