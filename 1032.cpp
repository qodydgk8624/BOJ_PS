// BOJ - 1032 명령 프롬로트

#include <iostream>
#include <string.h>
#include <string>
using namespace std;
char a[51][51];
string k;
int n,res=0;
bool c;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < strlen(a[0]); j++)
    {
        c = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i][j] != a[i + 1][j])
            {
                c = 1;
                break;
            }
            res = i;
        }
        if (c == 1)
            k += '?';
        else
            k += a[res][j];
    }
    cout << k;
}