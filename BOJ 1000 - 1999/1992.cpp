// BOJ - 1992 쿼드트리

#include <iostream>
#include <string>
#define MAXN 64 + 1

using namespace std;

int map[MAXN][MAXN] = {0, };

void div(int size, int x, int y)
{
    int r[2] = {0, };
    for(int i = x; i < x + size; i++)
        for(int j = y; j < y + size; j++)
            r[map[i][j]]++;

    for(int i = 0; i < 2; i++)
        if(r[i] == size * size)
        {
            cout << i; return;
        }

    size /= 2;

    cout << '(';
    div(size, x, y);
    div(size, x, y + size);
    div(size, x + size, y);
    div(size, x + size, y + size);
    cout << ')';

}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++)
            map[i][j + 1] = s[j] - '0';
    }

    div(n, 1, 1);
}