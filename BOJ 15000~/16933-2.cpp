// BOJ - 16933 ( 2 tries )

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
		int time=dist[broken][x][y];
		if(x==n && y==m) return dist[broken][x][y];
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i]; // 가고자 하는 x 좌표 
			int ny=y+dy[i]; // 가고자 하는 y 좌표 
			int iswall=map[nx][ny]; // 가고자 하는 좌표가 벽인가 
			int bi=broken+iswall;
			if(isCoordinateInside(nx,ny))
			{
				if(iswall) // 벽인가? 
				{
					if(bi<=max_broken) // 벽을 부술 수 있는가? 
					{
						if(time%2) // 낮인가?
						{
							if(time+1 < dist[bi][nx][ny])
							{
								dist[bi][nx][ny]=time+1;
								q.push({bi,nx,ny});
							}
						}
						else
						{
							dist[bi][nx][ny]=time+1;
							q.push({bi,x,y});
						}
					}
				}
				else
				{
					if(time+1 < dist[bi][nx][ny])
					{
						dist[bi][nx][ny]=time+1;
						q.push({bi,nx,ny});
					}
				}
			}
		}
	}
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


