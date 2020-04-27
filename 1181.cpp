// BOJ - 1181 단어 정렬

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct word {
    string s;
    bool operator<(const word b)
    {
        int alen = s.length();
        int blen = b.s.length();
        if(alen != blen) return alen < blen;
        return s < b.s;
    }
    bool operator>(const word b)
    {
        int alen = s.length();
        int blen = b.s.length();
        if(alen != blen) return alen > blen;
        return s > b.s;
    }
};

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    word w[n];
    for(int i = 0; i < n; i++)
        cin >> w[i].s;

    sort(w, w + n);

    for(int i = 0; i < n; i++)
        if(w[i - 1].s != w[i].s)
            cout << w[i].s << '\n';
}
