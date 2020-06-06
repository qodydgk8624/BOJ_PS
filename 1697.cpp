// BOJ - 1697 숨바꼭질

#include <iostream>
#include <queue>
#define MAXCOORD 100000

struct p {
    int x, day;
};

using namespace std;

int n, k, ans = 0; int visited[MAXCOORD + 1] = {0, };

void bfs()
{
    queue<p> q;
    q.push({n, 0}); visited[n] = 1;
    while(1) // while(!q.empty()) 해도 좋긴 한데 어차피 빠져나간다.
    {
        p t = q.front(); q.pop();

        if(t.x == k)
        {
            ans = t.day;
            return;
        }

        if((t.x << 1) <= MAXCOORD && !visited[t.x << 1])
        {
            visited[t.x << 1] = 1;
            q.push({t.x << 1, t.day + 1});
        }
        if(t.x - 1 >= 0 && !visited[t.x - 1])
        {
            visited[t.x - 1] = 1;
            q.push({t.x - 1, t.day + 1});
        }
        if(t.x + 1 <= MAXCOORD && !visited[t.x + 1])
        {
            visited[t.x + 1] = 1;
            q.push({t.x + 1, t.day + 1});
        }
    }
}

int main()
{
    cin >> n >> k;
    bfs();
    cout << ans;
}