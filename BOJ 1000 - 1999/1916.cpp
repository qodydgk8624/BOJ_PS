// BOJ - 1916

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1000

using namespace std;

const int INF = 987654321;

struct edge
{
	int v,cost;
	bool operator<(const edge& e)const{
		return cost<e.cost;
	}
	bool operator>(const edge& e)const{
		return cost>e.cost;
	}
};

int N,M,S,E;
vector<edge> G[MAXN+1];
int dist[MAXN+1];

int min(int a,int b)
{
	return a<b?a:b;
}

int dijkstra()
{
	priority_queue<edge,vector<edge>,greater<edge> > pq;
	dist[S]=0;
	pq.push({S,0});
	while(!pq.empty())
	{
		edge t = pq.top(); pq.pop();
		for(int i=0; i < G[t.v].size(); i++)
		{
			if(dist[t.v]+G[t.v][i].cost < dist[G[t.v][i].v])
			{
				dist[G[t.v][i].v]=dist[t.v]+G[t.v][i].cost;
				pq.push({G[t.v][i].v,dist[G[t.v][i].v]});
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	// 거리정보 INF로 초기화 
	for(int i=0; i<=MAXN; i++) dist[i]=INF;
	// 버스 정보 기입 
	for(int i=0; i<M; i++)
	{
		int _1,_2,_3;
		cin >> _1 >> _2 >> _3;
		G[_1].push_back({_2,_3});
	}
	cin >> S >> E;
	dijkstra();
	// dist[E] = S->E 최단경로의 길이 
	cout << dist[E];
}

