// BOJ - 5719

/*
 IDEA
 1. use Dijkstra and find shortest path
 2. the shortest path can be duplicated, then i'll use BFS to remove edges of shortest path(s).
 3. use Dijkstra and find answer
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <memory.h>

#define MAXV 500
#define INF 987654321

#define p pair<int,int> 

using namespace std;

int N,M;
int S,D;

vector<p> graph[MAXV];

vector<int> dijkstra(vector<p> sp_v[MAXV])
{
	vector<int> dist(N,INF);
	dist[S]=0;
	priority_queue<p> pq;
	
	pq.push({S,0});
	
	while(!pq.empty())
	{
		int from = pq.top().first;
		int cost = -pq.top().second;
		
		pq.pop();
		
		for(int i=0; i<graph[from].size(); i++)
		{
			int to = graph[from][i].first;
			int fromtocost = cost + graph[from][i].second;
			
			if(graph[from][i].second == -1)
				continue;
				
			if(dist[to] > fromtocost)
			{
				dist[to] = fromtocost;
				pq.push({to,-fromtocost});
				
				sp_v[to].clear();
				sp_v[to].push_back({from,-fromtocost});
			}
			else if(dist[to] == fromtocost)
				sp_v[to].push_back({from,-fromtocost});
			
		}
	}
	
	return dist;
}
int main()
{
	while(1)
	{
		cin >> N >> M;
		if(!N&!M) return 0; // N==0 && M==0
		cin >> S >> D;
		memset(graph,0,sizeof(graph));
		for(int i=0; i<M; i++)
		{
			int from,to,val;
			cin >> from >> to >> val;
			graph[from].push_back({to,val});
		}
		
		vector<p> sp_v[MAXV]; // Shortest Path Vertex
		
		dijkstra(sp_v);
		
		queue<int> q;
		
		q.push(D);
		
		while(!q.empty())
		{
			int from = q.front();
			
			q.pop();
			
			for(int i=0; i<sp_v[from].size(); i++)
			{
				int to = sp_v[from][i].first;
				
				for(int j=0; j<graph[to].size(); j++)
					if(graph[to][j].first == from)
						graph[to][j].second = -1;

				q.push(to);
			}
		}
		
		vector<int> ans = dijkstra(sp_v);
		
		if(ans[D] == INF)
			cout << -1 << '\n';
		else
			cout << ans[D] << '\n';
			
	}
}
