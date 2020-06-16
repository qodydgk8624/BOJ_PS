// BOJ - 11729 하노이 탑 이동 순서

#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int from, int to, int mid)
{
    if(n == 1) cout << from << ' ' << to << '\n';
    else
    {
        hanoi(n-1, from, mid, to);
        cout << from << ' ' << to << '\n';
        hanoi(n-1, mid, to, from);
    }
    
}
int main()
{
    int n; cin >> n;
    cout << (int) pow(2, n) - 1 << '\n';
    hanoi(n, 1, 3, 2);
}