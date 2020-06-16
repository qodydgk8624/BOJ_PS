// BOJ - 6549
// Segment Tree

#include <iostream>
#include <vector>

using namespace std;

#define INF 0xFFFFFFFFFFFFFFF
#define ll long long

ll max(ll a, ll b)
{
	return a>b?a:b;
}
void init(vector<ll> &a, vector<ll> &tree, int nd, int s, int e)
{
	if(s == e) { tree[nd] = s; return; }
	int m = (s + e) / 2;
	init(a, tree, nd*2, s, m);
	init(a, tree, nd*2+1, m+1, e);
	// tree[] = idx value 
	if(a[tree[nd*2]] <= a[tree[nd*2+1]])
		tree[nd]=tree[nd*2];
	else
		tree[nd]=tree[nd*2+1];
}

ll get_idx(vector<ll> &a, vector<ll> &tree, int nd, int s, int e, int l, int r)
{
	if(r<s | e<l) return -1;
	if(l<=s & e<=r) return tree[nd];
	int m = (s + e) / 2;
	int c1 = get_idx(a, tree, 2*nd, s, m, l, r);
	int c2 = get_idx(a, tree, 2*nd+1, m+1, e, l, r);
	
	if(c1 == -1) return c2;
	else if(c2 == -1) return c1;
	
	if(a[c1] <= a[c2]) return c1;
	else return c2;
	
}

ll solve(vector<ll> &a, vector<ll> &tree, int s, int e)
{
	int n = a.size();
	int m = get_idx(a, tree, 1, 0, n-1, s, e);
	ll width = (e-s+1)*a[m];
	if(s <= m-1) width = max(width, solve(a, tree, s, m-1));
	if(m+1 <= e) width = max(width, solve(a, tree, m+1, e));
	return width;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(1)
	{
		int n;
		cin >> n;
		if(n==0) return 0;
		vector<ll> a(n);
		vector<ll> tree(n*4);
		for(int i=0; i<n; i++)
			cin >> a[i];
		init(a, tree, 1, 0, n-1);
		cout << solve(a, tree, 0, n-1) << '\n';
	}
}
