// BOJ - 1676 팩토리얼 0의 개수

#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    cout << n/5 + n/25 + n/125;
}