// BOJ - 13544

#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define INF 0x7FFFFFFFFFFFFFFF

using namespace std;

void update(vector<ll> &a, vector<vector<ll> > &tree, ll nd, ll s, ll e, ll x)
{
	// [s,e] ������ x�� ���� ��� 
	if(s > x | x > e) return; 
	tree[nd].push_back(a[x]);
	ll m=(s+e) / 2;
	if(s != e)
	{
		update(a, tree, nd << 1, s, m, x);
		update(a, tree, (nd << 1) + 1, m+1, e, x);
	}
}

ll seg_query(vector<ll> &a, vector<vector<ll> > &tree, ll nd, ll l, ll r, ll s, ll e, ll k)
{
	// ������ �ƿ� ��ġ�� �ʴ� ��� 
	if(e < l | r < s) return 0;
	// upper_bound() �� �̿��Ͽ� ����. 
	if(l <= s & e <= r) return tree[nd].end() - upper_bound(tree[nd].begin(), tree[nd].end(), k);
	ll m = (s + e) >> 1;
	return seg_query(a, tree, nd*2, l, r, s, m, k)
		+ seg_query(a, tree, nd*2+1, l, r, m+1, e, k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<vector<ll> > tree(n*4);
	for(int i=0; i<n; i++) 
	{
		cin >> a[i];
		// tree�� node���� ������ �ش��ϴ� ���ҵ��� �������ݴϴ�. 
		update(a,tree,1,0,n-1,i);
	}
	
	// ���� 
	for(int i=1; i<n*4; i++) sort(tree[i].begin(), tree[i].end());
	
	ll query,ans=0;
	cin >> query;
	
	while(query--)
	{
		ll i,j,k;
		cin >> i >> j >> k;
		i^=ans;
		j^=ans;
		k^=ans;
		ans = seg_query(a, tree, 1, i-1, j-1, 0, n-1, k);
		cout << ans << '\n';
		
	}
	
}
