// BOJ - 1874 스택 수열

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m(0); cin >> n; string ans;
    stack<int> st; st.push(0);
    while(n--)
    {
        int t; cin >> t;
        if(m < t)
        {
            for(int i = m + 1; i <= t; i++)
            {
                st.push(i); ans += "+\n";
            }
        }
        else if(st.top() != t)
        {
            cout << "NO";
            exit(0);
        }
        ans += "-\n"; st.pop();
        m = max(m, t);
    }

    cout << ans;
}