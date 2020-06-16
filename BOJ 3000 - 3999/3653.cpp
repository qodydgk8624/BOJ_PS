// BOJ - 3653

// Fenwick Tree

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr,tree;

void update(int i, int val)
{
	while(i < 200005)
	{
		tree[i] += val;
		i += (i & -i);
	}
}
int query(int i)
{
	int ret = 0;
	while(i > 0)
	{
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		arr = vector<int>(100005);
		tree = vector<int>(200005);
		for(int i=1; i<=n; i++)
		{
			arr[i]=i+m; // arr = location 
			update(i+m, 1);
		}
		for(int i=0; i<m; i++)
		{
			int t; cin >> t;
			cout << query(arr[t])-1 << ' ';
			update(arr[t], -1);
			arr[t] = m-i;
			update(arr[t], 1);
		}
		cout << '\n';
	}
} 
