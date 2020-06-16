// BOJ - 1966 프린터 큐

#include <iostream>
#include <queue>

using namespace std;

struct p {
    int idx, val;
};
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int t; cin >> t;
    while(t--)
    {
        int n, m, ans(0); cin >> n >> m;
        queue<p> q; priority_queue<int> pq;
        for(int i = 0; i < n; i++)
        {
            int _; cin >> _;
            q.push({i, _}); pq.push(_);
        }
        while(1)
        {
            int idx = q.front().idx;
            int val = q.front().val; q.pop();
            if(val == pq.top())
            {
                pq.pop(); ans++;
                if(idx == m)
                {
                    cout << ans << '\n'; break;
                }
            }
            else q.push({idx, val});
        }
    }
}