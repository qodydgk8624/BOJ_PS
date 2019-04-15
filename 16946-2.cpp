// BOJ - 16946 ( 2 tries )

// BFS 로 다시 풀 것이다.

// 그리고 나는 맞을 것이다. ㅠㅠㅠㅠㅠ

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Q
{
	int x,y;
};

int n,m,t=2;
int map[1001][1001];

vector<int> v;
queue<Q> q;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int isInside(int x,int y)
{
	return x>=1 && x<=n && y>=1 && y<=m;
}
void bfs(int s,int e)
{
	q.push({s,e});
	map[s][e]=t;
	v[t]=1;
	while(!q.empty())
	{
		int x=q.front().x , y=q.front().y;
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!map[nx][ny] && isInside(nx,ny))
			{
				v[t]++;
				map[nx][ny]=t;
				q.push({nx,ny});
			}
		}
	}
}
void solve()
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(map[i][j]==0)
			{
				v.push_back(0);
				bfs(i,j);
				t++;
			}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	v.push_back(0);
	v.push_back(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			scanf("%1d",&map[i][j]);
			if(map[i][j]) map[i][j]=-1;
		}
			
	solve();
	
	for(int i=1; i<=n; puts(""),i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(!~map[i][j])
			{
				vector<int> v2;
				v2.resize(t+1,0);
				int res=1;
				for(int k=0; k<4; k++)
				{
					int nx=i+dx[k],ny=j+dy[k];
					if(map[nx][ny]>=2 && isInside(nx,ny) && !v2[map[nx][ny]])
					{
						v2[map[nx][ny]]=1;
						res+=v[map[nx][ny]];
					}
				}
				printf("%d",res%10);
				
			}
			else printf("0");
		}
	}
}
