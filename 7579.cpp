// BOJ - 7579 앱

#include <iostream>
#define MAXN 100 + 1
#define MAXC 10000 + 1
#define INF 0x7FFFFFFF

using namespace std;

int b[MAXN] = {0, }; // bytes
int c[MAXN] = {0, }; // cost
int dp[MAXN][MAXC] = {0, };

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    int ans = INF;

    dp[0][c[0]] = b[0];
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < MAXC; j++)
        {
            if(j - c[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + b[i]);

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            ans = (dp[i][j] >= m) ? min(ans, j) : ans;
        }
    }

    cout << ans;
}