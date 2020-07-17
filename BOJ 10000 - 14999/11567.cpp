// BOJ - 11567 타임머신

#include <iostream>
#include <vector>
#define ll long long
#define INF 0x7FFFFFFFFFFFFFFF
#define MAXN 500 + 1

using namespace std;

ll n, m; 

struct edge
{
    int v, cost;
};

vector<edge> G[MAXN];
vector<ll> dist(MAXN, INF);

ll BF(ll start) // Bellman-Ford Algorithm
{
    ll isCycle = 0;

    dist[start] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(edge& e: G[j])
            {
                if(dist[j] != INF && dist[e.v] > e.cost + dist[j])
                {
                    dist[e.v] = e.cost + dist[j];
                    if(i == n) isCycle = 1;
                }
            }
        }
    }

    return isCycle;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int from, to, val;
        cin >> from >> to >> val;
        G[from].push_back({to, val});
    }

    ll isCycle = BF(1);

    if(!isCycle)
    {
        for(int i = 2; i <= n; i++)
        {
            if(dist[i] == INF) cout << "-1\n";
            else cout << dist[i] << '\n';
        }
    }
    else cout << "-1\n";
}