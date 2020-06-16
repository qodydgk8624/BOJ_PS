// BOJ - 1920 수 찾기

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    int arr[n] = {0, };
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int m; cin >> m;
    while(m--)
    {
        int search; cin >> search;
        auto ptr = lower_bound(arr, arr + n, search);
        if(*ptr == search) cout << "1\n";
        else cout << "0\n";
    }
}