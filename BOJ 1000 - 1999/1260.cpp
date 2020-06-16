// BOJ - 1260 DFS와 BFS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 1000 + 1

using namespace std;

vector<int> graph[MAXN];

int v_dfs[MAXN] = {0, }; // VISITED - DFS
int v_bfs[MAXN] = {0, }; // VISITED - BFS

void dfs(int v)
{
    v_dfs[v] = 1;
    cout << v << ' ';
    for(int i = 0; i < graph[v].size(); i++)
    {
        int s = graph[v][i];
        if(!v_dfs[s])
        {
            dfs(s);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    v_bfs[v] = 1;
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        cout << t << ' ';
        for(int i = 0; i < graph[t].size(); i++)
        {
            int s = graph[t][i];
            if(!v_bfs[s])
            {
                v_bfs[s] = 1;
                q.push(s);
            }
        }
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m, v; cin >> n >> m >> v;
    for(int i = 0; i < m; i++)
    {
        int s, d; cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    for(int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());


    dfs(v); // DFS
    cout << '\n';

    bfs(v); //BFS
    
}