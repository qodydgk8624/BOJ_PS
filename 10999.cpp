// BOJ - 10999

// Segment Tree with Lazy propagation

#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<ll> a, tree, lazy;

ll init(ll nd, ll s, ll e)
{
	if(s == e) return tree[nd] = a[s];
	ll m = (s + e) >> 1;
	return tree[nd] = init(nd << 1, s, m) + init((nd << 1) | 1, m + 1, e);
}

void update_lazy(ll nd, ll s, ll e)
{
	// lazy before 
	if(lazy[nd] != 0)
	{
		tree[nd] += (e - s + 1) * lazy[nd];
		if(s ^ e)
		{
			lazy[nd << 1] += lazy[nd];
			lazy[(nd << 1) | 1] += lazy[nd];
		}
		lazy[nd] = 0;
	}
}
void update(ll nd, ll s, ll e, ll l, ll r, ll diff)
{
	// lazy update
	update_lazy(nd, s, e);
	
	if(r < s | e < l) return;
	if(l <= s & e <= r)
	{
		tree[nd] += (e - s + 1) * diff;
		if(s ^ e)
		{
			lazy[nd << 1] += diff;
			lazy[(nd << 1) | 1] += diff;
		}
		return;
	}
	ll m = (s + e) >> 1;
	update(nd << 1, s, m, l, r, diff);
	update((nd << 1) | 1, m + 1, e, l, r, diff);
	tree[nd] = tree[nd << 1] + tree[(nd << 1) | 1];
}
ll sum(ll nd, ll s, ll e, ll l, ll r)
{
	update_lazy(nd, s, e);
	if(r < s | e < l) return 0;
	if(l <= s & e <= r) return tree[nd];
	ll m = (s + e) >> 1;
	return sum(nd << 1, s, m, l, r) + sum((nd << 1) | 1, m + 1, e, l, r);
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	a.resize(n); tree.resize(4*n); lazy.resize(4*n);
	
	for(int i = 0; i < n; i++) cin >> a[i];
	m += k;
	
	// initialize tree
	init(1, 0, n-1);
	
	while(m--)
	{
		int sel; cin >> sel;
		if(sel == 1)
		{
			int rs, re, diff; cin >> rs >> re >> diff;
			update(1, 0, n-1, rs-1, re-1, diff);
		}
		else
		{
			int rs, re; cin >> rs >> re;
			cout << sum(1, 0, n-1, rs-1, re-1) << '\n';
		}
	}
;}
