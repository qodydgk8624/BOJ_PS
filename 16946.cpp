// BOJ - 16946
#include <iostream>
#include <vector>

using namespace std;

int n,m,t=2;
int map[1001][1001]={0};
vector<int> v;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int isInside(int x,int y)
{
	return x>=1 && x<=n && y>=1 && y<=m;
}
void dfs(int x,int y)
{
	v[t]++;
	map[x][y]=t;
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(isInside(nx,ny) && !map[nx][ny])
			dfs(nx,ny);
	}
	
}
void solve()
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(!map[i][j])
			{
				v.push_back(0);
				dfs(i,j);
				t++;
			}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	v.push_back(0);
	v.push_back(0);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			scanf("%1d",&map[i][j]);
			if(map[i][j]) map[i][j]=-1;
		}
			

	solve();
	
	int duplicate[t+1]={0};
	
	for(int i=1; i<=n; puts(""),i++)
		for(int j=1; j<=m; j++)
		{
			if(!~map[i][j])
			{
				for(int k=0; k<=t; k++) duplicate[k]=0;
				int sum=1;
				for(int k=0; k<4; k++)
				{
					int nx=i+dx[k],ny=j+dy[k];
					if(map[nx][ny]>=2 && isInside(nx,ny) && !duplicate[map[nx][ny]]) sum+=v[map[nx][ny]],duplicate[map[nx][ny]]=1;
				}
				printf("%d",sum%10);
			}
			else printf("0");
		}
			
		
}
