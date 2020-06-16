// BOJ - 10989 수 정렬하기 3
// Counting Sort

#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, t; cin >> n;

    int count[10001] = {0, };
    for(int i = 0; i < n; count[t]++,i++) cin >> t;

    for(int i = 0; i < 10001; i++)
        for(int j = 0; j < count[i]; j++)
            cout << i << '\n';
}