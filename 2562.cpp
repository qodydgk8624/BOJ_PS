// BOJ - 2562 최댓값

#include <iostream>
#include <algorithm>

using namespace std;

struct X {
    int idx, val;
    bool operator<(const X b)
    {
        return val < b.val;
    }
    bool operator>(const X b)
    {
        return val > b.val;
    }
};
int main()
{
    //int n; cin >> n;
    int n = 9;
    X arr[n];
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        arr[i].idx = i;
        arr[i].val = t;
    }
    sort(arr, arr + n);

    cout << arr[n - 1].val << "\n";
    cout << arr[n - 1].idx + 1 << "\n";

    return 0;
}