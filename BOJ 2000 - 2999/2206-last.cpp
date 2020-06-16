// BOJ - 2206 ( ���� ������ )


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
			
	visited[0][1][1]=1; // ó�� ��ǥ�� �ǳԴ�. 
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
			int nx=x+dx[i]; // ������ �ϴ� x ��ǥ 
			int ny=y+dy[i]; // ������ �ϴ� y ��ǥ 
			int iswall=map[nx][ny]; // ������ �ϴ� ��ǥ�� ���ΰ� 
			int bi=broken+iswall; // �� �μ̴��� �Ⱥμ̴����� ���ؼ� ���ϱ�� ǥ��..(?) 
			if(!isCoordinateInside(nx,ny)) continue; // ������ �ϴ� ��ǥ�� map�� ����� continue
			if(bi==2) continue; // �̹� ���� �μ̰�, ������ �ϴ� ���� ���̹Ƿ� continue
			if(visited[bi][nx][ny]) continue; // �̹� �� ���� ������ continue
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


