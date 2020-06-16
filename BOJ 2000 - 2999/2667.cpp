// BOJ - 2667 단지번호붙이기

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 25 + 1

using namespace std;

int n; int map[MAXN][MAXN] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int isrange(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
int dfs(int x, int y)
{
    int ret = 1;
    
    if(!isrange(x, y)) return 0;

    map[x][y] = 0;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(map[nx][ny] == 1)
        {
            ret = ret + dfs(nx, ny);
        }
    }

    return ret;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c; cin >> c;
            map[i][j] = c - '0';
        }
    }

    vector<int> v; int ans = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(map[i][j])
            {
                ans++;
                int _ = dfs(i, j);
                v.push_back(_);
            }

    sort(v.begin(), v.end());

    cout << ans << '\n';
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';


}