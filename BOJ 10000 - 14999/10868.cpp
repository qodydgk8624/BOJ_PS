// BOJ - 10868

#include <iostream>
#include <vector>

#define ll long long

#define INF 0x7FFFFFFFFFFFFFFF

using namespace std;

ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end)
{
	if(start == end) return tree[node]=a[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(a,tree,node*2,start,mid),init(a,tree,node*2+1,mid+1,end));
}
ll get_min(vector<ll> &t, int nd, int s, int e, int l, int r)
{
	if(r<s || e<l) return INF;
	if(l<=s && e<=r) return t[nd];
	int m = (s+e)/2;
	return min(get_min(t,2*nd,s,m,l,r),get_min(t,2*nd+1,m+1,e,l,r));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> tree(4*n);
	for(int i=0; i<n; i++) cin >> a[i];
	
	// init - Tree Making
	init(a,tree,1,0,n-1);
	
	while(m--)
	{
		int l,r;
		cin >> l >> r;
		cout << get_min(tree,1,0,n-1,l-1,r-1) << '\n';
	}
}
