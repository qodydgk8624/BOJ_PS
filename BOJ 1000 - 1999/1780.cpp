// BOJ - 1780 종이의 개수

#include <iostream>
#define MAXN 2187 + 1

using namespace std;

int map[MAXN][MAXN] = {0, }; int ans[3] = {0, };

void div(int len, int x, int y)
{
    if(len == 1)
    {
        ans[map[x][y]]++; return;
    }

    int tmp_arr[3] = {0, };
    for(int i = x; i < x + len; i++)
        for(int j = y; j < y + len; j++)
            tmp_arr[map[i][j]]++;

    for(int i = 0; i < 3; i++)
        if(tmp_arr[i] == len * len)
        {
            ans[i]++; return;
        }

    len /= 3;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            int dx = x + i * len;
            int dy = y + j * len;
            div(len, dx, dy);
        }

}
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            int t; cin >> t;
            map[i][j] = t + 1;
        }

    div(n, 1, 1);

    for(int i = 0; i < 3; i++)
        cout << ans[i] << '\n';
}