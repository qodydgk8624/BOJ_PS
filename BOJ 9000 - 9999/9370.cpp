// BOJ - 9370 미확인 도착지

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
#define INF 987654321
#define MAXN 2000 + 1

using namespace std;

struct edge
{
    ll v;
    ll cost;
    bool operator<(const edge& e)const{
		return cost < e.cost;
	}
	bool operator>(const edge& e)const{
		return cost > e.cost;
	}
};

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

vector<ll> dijkstra(vector<edge>* G, int start)
{
    vector<ll> dist(MAXN, INF);
    priority_queue<edge> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty())
    {
        edge t = pq.top(); pq.pop();
        for(int i = 0; i < G[t.v].size(); i++)
        {
            int nei = G[t.v][i].v;
            ll cost = G[t.v][i].cost + t.cost;
            if(dist[nei] > cost)
            {
                dist[nei] = cost;
                pq.push({nei, cost});
            }
        }
    }

    return dist;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TestCase; cin >> TestCase;
    while(TestCase--)
    {
        // 문제의 입력과 동일하게 하였습니다.
        int n, m, t; cin >> n >> m >> t;
        int s, g, h; cin >> s >> g >> h;

        vector<edge> G[MAXN];

        for(int i = 1; i <= m; i++)
        {
            int a, b, d; cin >> a >> b >> d;
            G[a].push_back({b, d});
            G[b].push_back({a, d});
        }

        vector<ll> candidates;
        for(int i = 1; i <= t; i++)
        {
            int x; cin >> x;
            candidates.push_back(x);
        }
        sort(candidates.begin(), candidates.end());

        // 1. s -> g -> h -> x
        // 2. s -> h -> g -> x

        /*
        판단 기준: s -> g -> h -> x 이 최단거리가 되려면, 그 비용이 's -> x의 비용' 와 똑같다고 할 수 있다.
        또한, 미리 81번째 줄에서 candidates를 오름차순으로 정렬했으므로, 추가적으로 vector를 만들지 않고도 해결 할 수 있다.
        */

        vector<ll> dist_s = dijkstra(G, s);
        vector<ll> dist_g = dijkstra(G, g);
        vector<ll> dist_h = dijkstra(G, h);

        for(int i = 0; i < candidates.size(); i++)
        {
            ll x = candidates[i];
            if(dist_s[g] + dist_g[h] + dist_h[x] == dist_s[x]) cout << x << ' ';
            else if(dist_s[h] + dist_h[g] + dist_g[x] == dist_s[x]) cout << x << ' ';
        }
        cout << '\n';
    }
}