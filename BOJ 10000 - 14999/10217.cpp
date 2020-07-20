// BOJ - 10217 KCM Travel

/*
다른 최단경로 문제와 달리, 
고려해야 할 사항들은 비용(cost), 최단거리(delay) 2개이다.

동적 계획법 + 다익스트라 로 해결하였다.

D[i][j] = (시작지점 -> i) 까지 가는데 비용이 j이하인 최단 길이
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x7FFFFFFF
#define MAXN 100 + 1 // 최대 공항 수
#define MAXM 10000 + 1 // 최대 COST
#define MAXT 10000 + 1 // 최대 티켓 정보 수

using namespace std;

int D[MAXN][MAXT];

struct edge
{
    int v, cost, delay;
    bool operator<(const edge& e)const{
		return delay < e.delay;
	}
	bool operator>(const edge& e)const{
		return delay > e.delay;
	}
};

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int T; cin >> T;
    while(T--)
    {
        int N, M, K; cin >> N >> M >> K;

        vector<edge> G[MAXN];

        while(K--)
        {
            int u, v, c, d; cin >> u >> v >> c >> d;
            G[u].push_back({v, c, d});
        }

        priority_queue<edge, vector<edge>, greater<edge> > pq;
        pq.push({1, 0, 0});
        D[1][0] = 0;

        // Dp 배열을 INF으로 전부 초기화!
        for(int i = 0; i <= N; i++)
            for(int j = 0; j <= M; j++)
                D[i][j] = INF;

        while(!pq.empty())
        {
            edge t = pq.top(); pq.pop();
            if(D[t.v][t.cost] < t.delay) continue;
            for(int i = 0; i < G[t.v].size(); i++)
            {
                int nei = G[t.v][i].v;
                int cost = G[t.v][i].cost + t.cost;
                int delay = G[t.v][i].delay + t.delay;
                if(cost > M) continue;
                if(D[nei][cost] > delay)
                {
                    D[nei][cost] = delay;
                    pq.push({nei, cost, delay});
                }
            }
        }

        int ans = INF;
        for(int i = 1; i <= M; i++)
            ans = min(ans, D[N][i]);

        if(ans == INF) cout << "Poor KCM\n";
        else cout << ans << '\n';
    }
}
