// BOJ - 4963

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int n,m;
int map[51][51];
int dx[8]={-1,1,-1,1,-1,1,0,0};
int dy[8]={0,0,1,1,-1,-1,-1,1};

bool isInside(int x,int y)
{
	return x>0 && x<=n && y>0 && y<=m;
}

void dfs(int x,int y)
{
	for(int i=0; i<8; i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(map[nx][ny] && isInside(nx,ny))
			map[nx][ny]=0,dfs(nx,ny);
	}
}
int main()
{
	while(1)
	{
		int ans=0;
		memset(map,0,sizeof(map));
		cin >> m >> n;
		if(!m&&!n)break;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				cin >> map[i][j];
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				if(map[i][j])
					ans++,dfs(i,j);
		printf("%d\n",ans);
	}
 } 

