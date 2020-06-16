// BOJ - 2206 ( 최종 정리본 )


#include <iostream>
#include <cstdio>
#include <queue>

#define INF 987654321

using namespace std;

struct Q
{
	int broken,x,y;
};

int n,m;
int map[1001][1001];
int visited[2][1001][1001];
int dist[2][1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

queue<Q> q;

int min(int a,int b)
{
	return a<b?a:b;
}
int isCoordinateInside(int x,int y)
{
	return (x>=1) && (x<=n) && (y>=1) && (y<=m);
}
int bfs()
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			dist[0][i][j]=dist[1][i][j]=INF;
			
	visited[0][1][1]=1; // 처음 좌표는 건넜다. 
	dist[0][1][1]=1;
	q.push({0,1,1});
	while(!q.empty())
	{
		int x=q.front().x;
		int y=q.front().y;
		int broken=q.front().broken;
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i]; // 가고자 하는 x 좌표 
			int ny=y+dy[i]; // 가고자 하는 y 좌표 
			int iswall=map[nx][ny]; // 가고자 하는 좌표가 벽인가 
			int bi=broken+iswall; // 벽 부셨는지 안부셨는지에 대해서 더하기로 표현..(?) 
			if(!isCoordinateInside(nx,ny)) continue; // 가고자 하는 좌표가 map를 벗어나면 continue
			if(bi==2) continue; // 이미 벽을 부셨고, 가고자 하는 곳이 벽이므로 continue
			if(visited[bi][nx][ny]) continue; // 이미 온 적이 있으면 continue
			visited[bi][nx][ny]=1;
			dist[bi][nx][ny]=min(dist[bi][nx][ny],dist[broken][x][y]+1);
			q.push({bi,nx,ny}); 
		}
	}
	int min_value=min(dist[0][n][m],dist[1][n][m]);
	return min_value==INF?-1:min_value;
}

int main()
{
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%1d",&map[i][j]);
	
	printf("%d",bfs());
	
}


