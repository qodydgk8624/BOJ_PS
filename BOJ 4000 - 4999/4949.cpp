// BOJ - 4949 균형잡힌 세상

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    char c; string s;
    int cancel = 0;
    while(1)
    {
        stack<char> st;
        getline(cin, s);
        if(s == ".") return 0;
        for(int i = 0; i < s.length(); i++)
        {
            c = s[i];
            if(c == '(' || c == '[')
                st.push(c);
            else if(c == ')')
            {
                if(!st.empty() && st.top() == '(') st.pop();
                else cancel = 1;
            }
            else if(c == ']')
            {
                if(!st.empty() && st.top() == '[') st.pop();
                else cancel = 1;
            }
            // if(c == '(' || c == '[' || c == ')' || c == ']')
            //     printf("\tchar: %c, cancel: %d, st.size(): %d\n", c, cancel, st.size());
        }

//        printf("\tcancel: %d, st.size(): %d\n", cancel, st.size());
        if(cancel == 1 || !st.empty()) cout << "no\n";
        else cout << "yes\n";

        cancel = 0;
    }
}