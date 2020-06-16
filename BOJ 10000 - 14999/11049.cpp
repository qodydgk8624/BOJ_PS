// BOJ - 11049 행렬 곱셈 순서

#include <iostream>
#define MAXN 500 + 1
#define INF 0x7FFFFFFF

using namespace std;

struct mat {
    int r, c;
};

int n; mat matrix[MAXN];
int dp[MAXN][MAXN] = {0, };

int min(int a, int b)
{
    return a < b ? a : b;
}

int calc(int x, int y)
{
    if(x == y) return 0;

    if(dp[x][y] != -1) return dp[x][y];

    int ret = INF;

    for(int i = x; i < y; i++)
        ret = min(ret, calc(x, i) + matrix[x].r * matrix[i].c * matrix[y].c + calc(i + 1, y));

    return dp[x][y] = ret;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = -1;

    for(int i = 1; i <= n; i++)
    {
        int r, c; cin >> r >> c;
        matrix[i] = {r, c};
    }

    cout << calc(1, n);
}
