// BOJ - 15651 N과 M (3)

#include <iostream>
#define MAXN 8 + 1

using namespace std;

int n, m;

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
        seq[cnt] = i;
        dfs(cnt + 1);
    }
}
int main()
{
    cin.tie(0); ios::sync_with_stdio;
    cin >> n >> m;

    dfs(0);
}