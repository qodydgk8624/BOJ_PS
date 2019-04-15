// BOJ - 16933 ( 3 tries )

#include <iostream>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int n,m,max_broken;

int map[1001][1001];
int dist[11][1001][1001];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

struct Q
{
	int x,y,broken,time;
	// x, y 좌표
	// broken -> 벽을 얼마나 부셨는지
	// time -> 시간 
};

queue<Q> q;

int isCoordinateInside(int x,int y)
{
	return x>=1 && x<=n && y>=1 && y<=m;
}
int bfs()
{
	q.push({1,1,0,0});
	// (1,1) 이 시작좌표이고 , 시작시간이 낮인데 time 값이 0 이므로 짝수상태일때가 낮임을 알 수 있습니다.
	dist[0][0][0]=1;
	while(!q.empty()) 
	{
		int x=q.front().x;
		int y=q.front().y;
		int broken=q.front().broken;
		int time=q.front().time;
		if(x==n && y==m) return time+1;
		/*
		마지막에 내가 착각하였던 부분!
		dist[0~max_broken][n][m] 중에서 최소값을 찾을 필요는 없었다.
		왜냐하면 (n,m)에 처음으로 도달한 순간은 항상 최단거리이기 때문이다. 
		또한 dist는 1부터 시작했지만 time은 0부터 시작했으므로 1을 더한다. 
		*/
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			int iswall=map[nx][ny];
			if(!isCoordinateInside(nx,ny)) continue; // (nx,ny)이 맵 밖에 있으면 중단합니다. 
			if(iswall) // 벽이 있다면
			{
				int bi=broken+iswall; 
				if(bi>max_broken) continue; // 벽을 더이상 못부수는 경우는 배제한다. 
				if(time%2==0) // 낮이라면?
				{
					// time 를 dist에 계속 그냥 갱신하면 최단거리가 안 나올 수도 있다.
					// 그러므로 time+1(다음날까지 시간=거리) 이 현재 저장된 최단거리보다 작으면
					// 갱신한다. 
					if(time+1<dist[bi][nx][ny]) 
					{
						dist[bi][nx][ny]=time+1;
						q.push({nx,ny,bi,time+1});
					}
				}
				else // 밤이라면? 
				{
					// 밤이면 다음날로 미룬다.
					// 위치는 변동없이 시간만 흐르면 된다.
					// 하지만 다음날로 미룬 형태가 최단거리(시간)이라 말하기에는 힘들다. 
					// 또한, dist 와 time 이 의미하는 바는 동일하지만 dist 는 최단거리만 집어넣는 형태이므로
					// time 은 현재 최단거리가 아닌 그냥 거리(시간)이므로  time을 넘겨준다. 
					q.push({x,y,broken,time+1}); 
				}
			}
			else // 벽이 없다면 
			{
				// 벽이 없는 경우 또한 동일하다 보면 된다.
				// 단지 낮과 밤의 구분없이 가면 된다.
				// 하지만 역시나 이동한다고 최단경로라고 판단할 수는 없다.
				// 그러므로 최단경로이면 dist 에 집어넣고 queue 에 push한다.
				if(time+1<dist[broken][nx][ny])
				{
					dist[broken][nx][ny]=time+1;
					q.push({nx,ny,broken,time+1});
				 } 
			} 
		}
	}
	
	return -1;
	
	// (n,m) 에 도달하지 못하고 queue를 빠져나왔으니 경우의 수가 없으므로 -1이다. 
}
int main()
{
	cin >> n >> m >> max_broken;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			scanf("%1d",&map[i][j]);
			for(int oo=0; oo<=10; oo++) dist[oo][i][j]=INF;
		}
		
	cout << bfs();
	
}
