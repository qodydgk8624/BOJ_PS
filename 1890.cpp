// BOJ - 1890

#include <iostream>
#include <memory.h>

#define ll long long int

using namespace std;

ll n;
ll map[505][505]={0};
ll dp[505][505];
ll dx[2]={0,1};
ll dy[2]={1,0};

ll InMap(ll x,ll y)
{
	return x>=1 && x<=n && y>=1 && y<=n;
}
ll dfs(ll x,ll y)
{
	if(x==n && y==n) return dp[x][y]=1;
	if(dp[x][y] >= 0) return dp[x][y];
	if(!map[x][y]) return 0;
	dp[x][y]=0;
	for(int i=0; i<2; i++)
	{
		ll nx=x+dx[i]*map[x][y];
		ll ny=y+dy[i]*map[x][y];
		if(InMap(nx,ny))
			dp[x][y]+=dfs(nx,ny);
	}
	return dp[x][y];
}
void Input()
{
	cin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> map[i][j];
	memset(dp,-1,sizeof(dp));
}

void Output()
{
	if(map[1][1]!=0) 
		cout << dfs(1,1);
	else cout << 0;
}
int main()
{
	Input();
	Output();
} 
