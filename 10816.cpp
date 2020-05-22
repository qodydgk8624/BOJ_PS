// BOJ - 10816 숫자 카드 2

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;

    int a[n] = {0, };
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int m; cin >> m;
    while(m--)
    {
        int t; cin >> t;
        auto lb = lower_bound(a, a + n, t);
        auto ub = upper_bound(a, a + n, t);
        cout << ub - lb << ' ';
    }
}