// 17120 - Infinity 2

#include <bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
    int i = 0;
    string s;

    while(getline(cin, s)) {
        transform(ALL(s), s.begin(), ::tolower);
        if (i == 0 && s[0] == '/' && !(s.size() > 1 && s[1] == '/')) {
            cout << "NO" << '\n';
            i++;
            continue;
        }
        bool flag = false;
        if (s.find(":cat:") != string::npos) {
              cout << "YES\n";
              flag = true;
               break;
            }

        if (flag == false)
            cout << "NO\n";
        i++;

    }
    return 0;
}
