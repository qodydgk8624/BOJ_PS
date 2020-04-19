// BOJ - 12844

// Segment Tree with Lazy Propagation

#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<ll> a, tree, lazy;

ll init(int nd, int s, int e)
{
	if(s == e) return tree[nd] = a[s];
	int m = (s + e) >> 1;
	return tree[nd] = init(nd << 1, s, m) ^ init((nd << 1) | 1, m + 1, e);
}
void update_lazy(int nd, int s, int e)
{
	if(lazy[nd] != 0)
	{
		tree[nd] ^= lazy[nd] * ( (e - s + 1) % 2 );
		if(s != e)
		{
			lazy[nd << 1] ^= lazy[nd];
			lazy[(nd << 1) | 1] ^= lazy[nd];
		}
		lazy[nd] = 0;
	}
}
int update_range(int nd, int s, int e, int l, int r, int c)
{
	update_lazy(nd, s, e);
	if(r < s | e < l) return tree[nd];
	if(l <= s & e <= r)
	{
		tree[nd] ^= c * ( (e - s + 1) % 2);
		if(s != e)
		{
			lazy[nd << 1] ^= c;
			lazy[(nd << 1) | 1] ^= c;
		}
		return tree[nd];
	}
	int m = (s + e) >> 1;
	return tree[nd] = update_range(nd << 1, s, m, l, r, c) ^ update_range((nd << 1) | 1, m + 1, e, l, r, c);
}
ll query(int nd, int s, int e, int l, int r)
{
	update_lazy(nd, s, e);
	if(r < s | e < l) return 0;
	if(l <= s & e <= r) return tree[nd];
	int m = (s + e) >> 1;
	return query(nd << 1, s, m, l, r) ^ query((nd << 1) | 1, m + 1, e, l, r);
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	int n; cin >> n;
	if(n == 0) return 0;
	a.resize(n); tree.resize(4*n); lazy.resize(4*n);
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	init(1, 0, n - 1);
	
	int m; cin >> m;
	while(m--)
	{
		int sel; cin >> sel;
		if(sel == 1)
		{
			int t;
			int l, r, c; cin >> l >> r >> c;
			if(l > r) t=l,l=r,r=t;
			update_range(1, 0, n - 1, l, r, c);
		}
		else
		{
			int t;
			int l, r; cin >> l >> r;
			if(l > r) t=l,l=r,r=t;
			cout << query(1, 0, n - 1, l, r) << '\n';
		}
	}
}

