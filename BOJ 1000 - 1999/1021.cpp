// BOJ - 1021 회전하는 큐

#include <iostream>
#include <deque>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    
    deque<int> dq; int ans = 0;
    for(int i = 1; i <= n; i++) dq.push_back(i);

    for(int i = 1; i <= m; i++)
    {
        int val; cin >> val; int idx;
        for(int j = 0; j < dq.size(); j++)
            if(dq[j] == val)
            {
                idx = j; break;
            }

        // 2번
        if(idx <= dq.size() - idx)
        {
            ans += idx;
            for(int k = 1; k <= idx; k++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } // 3번
        else
        {
            ans += dq.size() - idx;
            for(int k = 1; k <= dq.size() - idx; k++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();

    }

    cout << ans;
}