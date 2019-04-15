// BOJ - 14442

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Q
{
	int broken,x,y;
};

int n,m,max_broken=0;
int map[1001][1001];
int visited[12][1001][1001];
int dist[12][1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

queue<Q> q;

int isCoordinateInside(int x,int y)
{
	return (x>=1) && (x<=n) && (y>=1) && (y<=m);
}
int bfs()
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			for(int oo=0; oo<=11; oo++)
				dist[oo][i][j]=INF;
			
	visited[0][1][1]=1; // 처음 좌표는 건넜다. 
	dist[0][1][1]=1;
	q.push({0,1,1});
	while(!q.empty())
	{
		int x=q.front().x;
		int y=q.front().y;
		int broken=q.front().broken;
		if(x==n && y==m) return dist[broken][x][y];
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i]; // 가고자 하는 x 좌표 
			int ny=y+dy[i]; // 가고자 하는 y 좌표 
			int iswall=map[nx][ny]; // 가고자 하는 좌표가 벽인가 
			if(!isCoordinateInside(nx,ny)) continue; // 가고자 하는 좌표가 map를 벗어나면 continue
			if(broken+iswall>max_broken) continue;
			if(visited[broken+iswall][nx][ny]) continue; // 이미 온 적이 있으면 continue
			visited[broken+iswall][nx][ny]=1;
			dist[broken+iswall][nx][ny]=dist[broken][x][y]+1;
			q.push({broken+iswall,nx,ny}); 
		}
	}
	/*
	puts("==");
	for(int i=1; i<=n; puts(""),i++)
		for(int j=1; j<=m; j++)
			printf("%d ",dist[0][i][j]==INF?0:dist[0][i][j]);
	puts("==");
	for(int i=1; i<=n; puts(""),i++)
		for(int j=1; j<=m; j++)
			printf("%d ",dist[1][i][j]==INF?0:dist[1][i][j]);
	puts("==");
	*/
	return -1;
}

int main()
{
	cin >> n >> m >> max_broken;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%1d",&map[i][j]);
	
	printf("%d",bfs());
	
}


