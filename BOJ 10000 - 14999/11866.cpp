// BOJ - 11866 요세푸스 문제 0

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    queue<int> q; string ans;

    for(int i = 1; i <= n; i++) q.push(i);

    ans += "<";
    while(!q.empty())
    {
        for(int i = 1; i < k; i++) 
        {
            q.push(q.front());
            q.pop();
        }
        ans += to_string(q.front()); q.pop();
        if(!q.empty()) ans += ", ";
    }
    ans += ">";

    cout << ans;
}