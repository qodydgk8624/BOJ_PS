// BOJ - 1427 소트인사이드

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s; cin >> s;
    auto ss = s.size();
    int a[ss];
    for(int i = 0; i < ss; i++) a[i] = s[i] - '0';
    sort(a, a + ss);
    for(int i = ss - 1; i >= 0; i--) cout << a[i];
}