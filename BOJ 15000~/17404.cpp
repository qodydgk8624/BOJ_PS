// BOJ - 17404 RGB거리 2

#include <iostream>
#define MAXN 1000 + 1
#define INF 987654321

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;

    int d[MAXN][3] = {0, };
    int c[MAXN][3] = {0, };

    // d[i][j] = "i번쨰 집에서 j번째 color를 색칠했을 때, 1 ~ i번째 까지 집을 색칠하면서 들었던 비용"
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            cin >> c[i][j];

    /*
        1번째 집에서 올 수 있는 색깔은 Red(0), Green(1), Blue(2) 입니다.

        예를 들어, 1번째 집에서 Red(0)로 시작한다면, d[1(첫번째 집)][0(Red)]는 c[1][0] 입니다.
                  그렇지만, d[1][1(Green)]는 INF가 됩니다. 마찬가지로, d[1][2(Blue)]도 INF가 됩니다.

    */

    int ans = INF;

    for(int start = 0; start < 3; start++)
    {
        for(int clr = 0; clr < 3; clr++)
        {
            if(start == clr) d[1][clr] = c[1][clr];
            else d[1][clr] = INF;
        }

        for(int i = 2; i <= n; i++)
        {
            d[i][0] = min(d[i - 1][1], d[i - 1][2]) + c[i][0];
            d[i][1] = min(d[i - 1][0], d[i - 1][2]) + c[i][1];
            d[i][2] = min(d[i - 1][0], d[i - 1][1]) + c[i][2];
        }

        for(int i = 0; i < 3; i++)
            if(i != start)
                ans = min(ans, d[n][i]);
    }

    cout << ans;
}