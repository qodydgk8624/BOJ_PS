// BOJ - 1275

// ±¸°£ÇÕ - Segment Tree

#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll init(vector<ll> &a, vector<ll> &tree, int nd, int s, int e)
{
	if(s == e) return tree[nd] = a[s];
	int m = (s + e) / 2;
	return tree[nd] = init(a, tree, nd << 1, s, m) + init(a, tree, (nd << 1) + 1, m+1, e);
}
ll sum(vector<ll> &tree, int nd, int s, int e, int l, int r)
{
	if(e < l | r < s) return 0;
	if(l <= s & e <= r) return tree[nd];
	int m = (s + e) / 2;
	return sum(tree, nd << 1, s, m, l, r) + sum(tree, (nd << 1) + 1, m+1, e, l, r);
}
void update(vector<ll> &a, vector<ll> &tree, int nd, int s, int e, int i, ll diff)
{
	if(e < i | i < s) return;
	tree[nd] += diff;
	int m = (s + e) >> 1;
	if(s ^ e)
	{
		update(a, tree, (nd << 1), s, m, i, diff);
		update(a, tree, (nd << 1) + 1, m+1, e, i, diff);
	}
}
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	ll n,q;
	cin >> n >> q;
	vector<ll> a(n);
	vector<ll> tree(n*4);
	for(int i=0; i<n; i++) cin >> a[i];
	
	init(a, tree, 1, 0, n-1);
	
	while(q--)
	{
		ll s,e,idx,change;
		cin >> s >> e >> idx >> change;
		s-=1,e-=1,idx-=1;
		if(s <= e)
			cout << sum(tree, 1, 0, n-1, s, e) << '\n';
		else
			cout << sum(tree, 1, 0, n-1, e, s) << '\n';
		ll diff = change - a[idx];
		a[idx] = change;
		update(a, tree, 1, 0, n-1, idx, diff);
	}
} 
