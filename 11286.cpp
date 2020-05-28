// BOJ - 11286 절댓값 힙

#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

struct strt
{
    ll num;
    ll orinum;

    bool operator<(const strt& t) const
    {
        if(num == t.num) return orinum > t.orinum;
        return num > t.num;
    }

    bool operator>(const strt& t) const
    {
        if(num == t.num) return orinum < t.orinum;
        return num < t.num;
    }
};

ll abs(ll n)
{
    return n < 0 ? -n : n;
}

priority_queue<strt> pq;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    ll n; cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        if(t == 0)
        {
            if(pq.size() == 0) cout << 0 << '\n';
            else
            {
                cout << pq.top().orinum << '\n';
                pq.pop();
            }
            
        }
        else pq.push({abs(t), t});
    }
}