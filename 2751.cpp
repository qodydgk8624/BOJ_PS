// BOJ - 2751 수 정렬하기2

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    int d[n];
    for(int i = 0; i < n; i++)
        cin >> d[i];
    sort(d, d+n);
    for(int i = 0; i < n; i++)
        cout << d[i] << ' ';
        
}