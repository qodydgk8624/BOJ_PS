// BOJ - 11279 최대 힙

#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

priority_queue<ll> pq;

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
                cout << pq.top() << '\n';
                pq.pop();
            }
            
        }
        else pq.push(t);
    }
}