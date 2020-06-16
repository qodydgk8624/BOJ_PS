// BOJ - 7569 토마토(3차원)

#include <iostream>
#include <queue>
#define MAXN 100 + 1
#define MAXM 100 + 1
#define MAXH 100 + 1

using namespace std;

int n, m, h, ans = 0;

// -1 -> 토마토 없음, 0 -> 익지 않은 토마토, 1 -> 익은 토마토

struct p {
    int z, x, y, day;
};

int map[MAXH][MAXN][MAXM] = {0, };

int dz[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};

int max(int a, int b)
{
    return a > b ? a : b;
}

bool isRange(int z, int x, int y)
{
    return (1 <= z) && (z <= h) && (1 <= x) && (x <= n) && (1 <= y) && (y <= m);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    queue<p> q;

    cin >> m >> n >> h;
    for(int z = 1; z <= h; z++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                cin >> map[z][i][j];
                if(map[z][i][j] == 1) q.push({z, i, j, 0});
            }

    while(!q.empty())
    {
        p t = q.front(); q.pop();

        ans = max(ans, t.day);

        for(int i = 0; i < 6; i++)
        {
            int nz = t.z + dz[i];
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(isRange(nz, nx, ny) && map[nz][nx][ny] == 0)
            {
                map[nz][nx][ny] = 1;
                q.push({nz, nx, ny, t.day + 1});
            }
        }
    }

    int flag = 0;
    for(int z = 1; z <= h; z++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(map[z][i][j] == 0)
                    flag = 1;

    if(flag) cout << -1;
    else cout << ans;
}