// BOJ - 14953

#include <vector>
#include <iostream>

#define MAXN 100000

using namespace std;

vector<int> map[MAXN];
int nei[MAXN]={0};
int dp[MAXN]={0};



int max(int a,int b)
{
	return a>b?a:b;
}
int dfs(int k)
{	
	if(dp[k]) return dp[k];
	int ret = 1;
	for(int i=0; i<map[k].size(); i++)
		if(nei[k] < nei[map[k][i]])
			ret = max(ret,1+dfs(map[k][i]));
	return dp[k] = ret;
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=m; i++)
	{
		int _1,_2;
		cin >> _1 >> _2;
		map[_1].push_back(_2);
		map[_2].push_back(_1);
		nei[_1]++,nei[_2]++;
	}
	int res = 0;
	for(int i=0; i<n; i++)
	{
		res = max(res,dfs(i));
	}
	cout << res;
}
