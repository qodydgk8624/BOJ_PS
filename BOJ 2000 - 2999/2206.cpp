// BOJ - 2206

#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

#define INF 987654321

using namespace std;

struct Q
{
	int x,y,broken;
};

int n,m;
int w_x,w_y;
int map[1001][1001];
int dist[1001][1001];
int visited[1001][1001];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int min_v=INF;

queue< pair<int,int> > q;

queue< pair<int,int> > q2;

int getCoordinateInside(int x,int y)
{
	return (x>=1) && (x<=n) && (y>=1) && (y<=m);
}
void bfs()
{
	int x,y;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			visited[i][j]=0,dist[i][j]=INF;
	q2.push(make_pair(1,1));
	visited[1][1]=1;
	dist[1][1]=1;
	while(!q2.empty())
	{
		x=q2.front().first;
		y=q2.front().second;
		q2.pop();
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(getCoordinateInside(nx,ny) && !visited[nx][ny] && !map[nx][ny])
			{
				dist[nx][ny]=min(dist[x][y]+1,dist[nx][ny]);
				//dist[nx][ny]=dist[x][y]+1;
				visited[nx][ny]=1;
				q2.push(make_pair(nx,ny));
			}
		}
	}
	/*for(int i=1; i<=n; puts(""),i++)
		for(int j=1; j<=m; j++)
			printf("%d ",dist[i][j]==INF?0:dist[i][j]);
	puts("==========");*/
	if(dist[n][m]!=INF)
		min_v=min(min_v,dist[n][m]);
}

int main()
{
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			scanf("%1d",&map[i][j]);
			if(map[i][j]) q.push(make_pair(i,j));
		}
		
	while(!q.empty())
	{
		w_x=q.front().first;
		w_y=q.front().second;
		map[w_x][w_y]=0;
		q.pop();
		bfs();
		map[w_x][w_y]=1;
	}
	
	printf("%d",min_v==INF?-1:min_v);
			
}
