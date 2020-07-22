// BOJ - 1956 운동

#include <iostream>
#define INF 987654321

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int v, e; cin >> v >> e;

    int d[v + 1][v + 1] = {0, };
    for(int i = 1; i <= v; i++)
        for(int j = 1; j <= v; j++)
            d[i][j] = INF;

    for(int i = 0; i < e; i++)
    {
        int from, to, val;
        cin >> from >> to >> val;
        d[from][to] = val;
    }

    for(int k = 1; k <= v; k++)
        for(int i = 1; i <= v; i++)
            for(int j = 1; j <= v; j++)
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    int ans = INF;
    for(int i = 1; i <= v; i++)
        ans = min(ans, d[i][i]);

    if(ans == INF) cout << -1;
    else cout << ans;
}