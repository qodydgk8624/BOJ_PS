// BOJ - 2981 검문

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    int n; cin >> n;
    int arr[n] = {0, };
    for(int i = 0 ; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int g = arr[1] - arr[0];
    for(int i = 2; i < n; i++)
        g = gcd(g, arr[i] - arr[i - 1]);

    vector<int> q; q.push_back(g);

    for(int i = 2; i * i <= g; i++)
        if(g % i == 0)
        {
            q.push_back(i); q.push_back(g / i);
        }

    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end()); // 중복숫자 제거

    for(int i = 0; i < q.size(); i++)
        cout << q[i] << ' ';
    
}