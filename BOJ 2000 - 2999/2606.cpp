// BOJ - 2606 바이러스

#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100 + 1

using namespace std;

vector<int> graph[MAXN];
int visited[MAXN] = {0, };

int bfs(int v)
{
    int ret = 0;

    queue<int> q;
    q.push(v); visited[v] = 1;

    while(!q.empty())
    {
        int t = q.front(); q.pop();
        for(int i = 0; i < graph[t].size(); i++)
        {
            int s = graph[t][i];
            if(!visited[s])
            {
                ret++;
                visited[s] = 1;
                q.push(s);
            }
        }
    }

    return ret;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s, d; cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    cout << bfs(1);
}