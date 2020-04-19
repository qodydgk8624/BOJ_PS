// BOJ - 2243

// Segment Tree or Fenwick Tree

/*
찾을려는 사탕 N번째 구하기
1. left -> right 탐색
2. l_c < N -> right node search
3. l_c >= N -> left node search
*/

#include <iostream>
#include <vector>
#define ll long long
#define MAXC 1000000

using namespace std;

ll idx = 0;
vector<ll> a, tree;
void update(ll nd, int s, int e, int fl, int n)
{
	if(fl < s | fl > e) return;
	tree[nd] += n;
	if(s != e)
	{
		int m = (s + e) >> 1;
		update(nd << 1, s, m, fl, n);
		update((nd << 1) | 1, m + 1, e, fl, n);
	}
}
ll query(ll nd, int s, int e, int r)
{
	ll l_c = tree[nd << 1], r_c = tree[(nd << 1) | 1], m = (s + e) >> 1;
	
	if(s == e) return s;
	if(idx == -1 & l_c >= r)	return query((nd << 1), s, m, r);
	if(idx == -1 & l_c < r) return query((nd << 1) | 1, m + 1, e, r - l_c);
	
}
int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	int q; cin >> q;
	a.resize(MAXC); tree.resize(4*MAXC);
	
	while(q--)
	{
		int sel; cin >> sel;
		if(sel == 2)
		{
			int flavor, n; cin >> flavor >> n;
			update(1, 0, MAXC-1, flavor-1, n);
		}
		else
		{
			int rank; cin >> rank; idx = -1;
			idx = query(1, 0, MAXC-1, rank);
			cout << idx+1 << '\n';
			update(1, 0, MAXC-1, idx, -1);
		}
	}
}
