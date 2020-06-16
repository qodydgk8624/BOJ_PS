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
	// x, y ��ǥ
	// broken -> ���� �󸶳� �μ̴���
	// time -> �ð� 
};

queue<Q> q;

int isCoordinateInside(int x,int y)
{
	return x>=1 && x<=n && y>=1 && y<=m;
}
int bfs()
{
	q.push({1,1,0,0});
	// (1,1) �� ������ǥ�̰� , ���۽ð��� ���ε� time ���� 0 �̹Ƿ� ¦�������϶��� ������ �� �� �ֽ��ϴ�.
	dist[0][0][0]=1;
	while(!q.empty()) 
	{
		int x=q.front().x;
		int y=q.front().y;
		int broken=q.front().broken;
		int time=q.front().time;
		if(x==n && y==m) return time+1;
		/*
		�������� ���� �����Ͽ��� �κ�!
		dist[0~max_broken][n][m] �߿��� �ּҰ��� ã�� �ʿ�� ������.
		�ֳ��ϸ� (n,m)�� ó������ ������ ������ �׻� �ִܰŸ��̱� �����̴�. 
		���� dist�� 1���� ���������� time�� 0���� ���������Ƿ� 1�� ���Ѵ�. 
		*/
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			int iswall=map[nx][ny];
			if(!isCoordinateInside(nx,ny)) continue; // (nx,ny)�� �� �ۿ� ������ �ߴ��մϴ�. 
			if(iswall) // ���� �ִٸ�
			{
				int bi=broken+iswall; 
				if(bi>max_broken) continue; // ���� ���̻� ���μ��� ���� �����Ѵ�. 
				if(time%2==0) // ���̶��?
				{
					// time �� dist�� ��� �׳� �����ϸ� �ִܰŸ��� �� ���� ���� �ִ�.
					// �׷��Ƿ� time+1(���������� �ð�=�Ÿ�) �� ���� ����� �ִܰŸ����� ������
					// �����Ѵ�. 
					if(time+1<dist[bi][nx][ny]) 
					{
						dist[bi][nx][ny]=time+1;
						q.push({nx,ny,bi,time+1});
					}
				}
				else // ���̶��? 
				{
					// ���̸� �������� �̷��.
					// ��ġ�� �������� �ð��� �帣�� �ȴ�.
					// ������ �������� �̷� ���°� �ִܰŸ�(�ð�)�̶� ���ϱ⿡�� �����. 
					// ����, dist �� time �� �ǹ��ϴ� �ٴ� ���������� dist �� �ִܰŸ��� ����ִ� �����̹Ƿ�
					// time �� ���� �ִܰŸ��� �ƴ� �׳� �Ÿ�(�ð�)�̹Ƿ�  time�� �Ѱ��ش�. 
					q.push({x,y,broken,time+1}); 
				}
			}
			else // ���� ���ٸ� 
			{
				// ���� ���� ��� ���� �����ϴ� ���� �ȴ�.
				// ���� ���� ���� ���о��� ���� �ȴ�.
				// ������ ���ó� �̵��Ѵٰ� �ִܰ�ζ�� �Ǵ��� ���� ����.
				// �׷��Ƿ� �ִܰ���̸� dist �� ����ְ� queue �� push�Ѵ�.
				if(time+1<dist[broken][nx][ny])
				{
					dist[broken][nx][ny]=time+1;
					q.push({nx,ny,broken,time+1});
				 } 
			} 
		}
	}
	
	return -1;
	
	// (n,m) �� �������� ���ϰ� queue�� ������������ ����� ���� �����Ƿ� -1�̴�. 
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
