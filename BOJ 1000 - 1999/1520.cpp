// BOJ - 1520

#include <iostream>
#include <memory.h>

using namespace std;

int n,m;

int dp[501][501];

int map[501][501];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int isInside(int x,int y)
{
	return x>=1 && x<=n && y>=1 && y<=m;
}
int dfs(int x,int y)
{
	if(dp[x][y]>=0) return dp[x][y];
	dp[x][y]=0;
	int cmp=map[x][y];
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(isInside(nx,ny) && cmp>map[nx][ny])
			dp[x][y]+=dfs(nx,ny);
	}
	
	return dp[x][y];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin >> map[i][j];
	
	dp[n][m]=1;
			
	cout << dfs(1,1);
	
}
