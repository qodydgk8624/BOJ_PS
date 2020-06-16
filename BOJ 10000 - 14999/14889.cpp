// BOJ - 14889 스타트와 링크

/* 아이디어
백트래킹 문제, 만약, N=6 [3, 3] 으로 나누어 생각해야 한다.
즉, N=K, [K/2, K/2] 으로 나누어 생각해야 한다.
바꾸어 말하자면, 1 ~ N까지 사전순으로 K/2개를 뽑는다.
나머지 K/2개는 자동으로 결정되기 때문에 합을 비교할 때 쓰면 된다.

*/
#include <iostream>
#define MAXN 20 + 1

using namespace std;

int n; int map[MAXN][MAXN] = {0, };
int visited[MAXN] = {0, };
int ans = 0x7FFFFFFF;

int abs(int n)
{
    return n < 0 ? -n : n;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void updateSum()
{
    int asum = 0, bsum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(visited[i] & visited[j])
                asum += (map[i][j] + map[j][i]);
            if(!visited[i] & !visited[j])
                bsum += (map[i][j] + map[j][i]);
        }
    }

    ans = min(ans, abs(asum - bsum));
}

void dfs(int cnt)
{
    if(cnt == n / 2) updateSum();

    int idx = 1;
    for(int i = 1; i <= n; i++)
        if(visited[i])
            idx = i;
    
    for(int i = idx + 1; i <= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            dfs(cnt + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];

    dfs(0);

    cout << ans;
}
