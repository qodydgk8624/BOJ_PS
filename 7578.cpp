// BOJ - 7578

// Counting Inversion
// Segment Tree
// Map tle

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ll long long

#define INF 0xFFFFFFFFFFFFFFF

ll B[1000010];

void update(vector<ll> &a, vector<ll> &tree, ll nd, ll s, ll e, ll i, ll val)
{
	if(i < s | e < i) return;
	tree[nd] += val;
	if(s ^ e)
	{
		ll m = (s + e) / 2;
		update(a, tree, nd<<1, s, m, i, val);
		update(a, tree, (nd<<1)+1, m+1, e, i, val);
	}
}
ll sum(vector<ll> &a, vector<ll> &tree, ll nd, ll s, ll e, ll l, ll r)
{
	if(l > e | s > r) return 0;
	if(l <= s & e <= r) return tree[nd];
	ll m = (s + e) / 2;
	return sum(a, tree, nd<<1, s, m, l, r)
	+ sum(a, tree, (nd<<1)+1, m+1, e, l, r);
}
int main()
{
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	ll n; cin >> n;
	
	vector<ll> arr(n);
	vector<ll> tree(4*n);
	ll A[n];
	for(int i=0; i<n; i++) cin >> A[i];
	for(int i=0; i<n; i++) {
		ll t; cin >> t; B[t]=i;
	}
	ll ans = 0;
	for(int i=0; i<n; i++)
	{
		ans += sum(arr, tree, 1, 0, n-1, B[A[i]]+1, n-1);
		update(arr, tree, 1, 0, n-1, B[A[i]], 1);
	}
	
	cout << ans;
}
