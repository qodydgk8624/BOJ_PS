// BOJ - 15650 N과 M (2)

#include <iostream>
#define MAXN 8 + 1

using namespace std;

int n, m;

int visited[MAXN] = {0, };
int seq[MAXN] = {0, };

void dfs(int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++)
            cout << seq[i] << ' ';
        cout << '\n'; return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            seq[cnt] = i;
            if(cnt > 0 && seq[cnt - 1] > seq[cnt])
            {
                visited[i] = 0;
                continue;
            }
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}
int main()
{
    cin.tie(0); ios::sync_with_stdio;
    cin >> n >> m;

    dfs(0);
}