// BOJ - 2178 미로 탐색

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n,m;

int map[101][101]={0},check[101][101]={0};
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int inside(int x,int y)
{
	return x<0 || x>=n || y<0 || y>=m;
}
int bfs()
{
	int cur_x=0,cur_y=0;
	queue< pair<int,int> > q;
	q.push(make_pair(cur_x,cur_y));
	check[0][0]=1;
	while(!q.empty())
	{
		int cur_x=q.front().first;
		int cur_y=q.front().second;
		q.pop();
		if(cur_x==n && cur_y==m) break;
		for(int i=0; i<4; i++)
		{
			int next_x=cur_x+dx[i];
			int next_y=cur_y+dy[i];
			if(!inside(next_x,next_y) && !check[next_x][next_y] && map[next_x][next_y])
			{
				check[next_x][next_y]=check[cur_x][cur_y]+1;
				q.push(make_pair(next_x,next_y));
			}
		}
	}



	return check[n-1][m-1];
}
int main()
{
	cin >> n >> m;
	
	//입력
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}
	
	printf("%d",bfs());
	
		
}