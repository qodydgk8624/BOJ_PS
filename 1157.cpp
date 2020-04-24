// BOJ - 1157 단어 공부

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    char chrarr[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    int val[27] = {0, };

    string s; cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
        val[s[i] - 'A']++;
    }

    int max = -1, res = -1;
    for(int i = 0; i < 27; i++)
    {
        if(max < val[i])
        {
            max = val[i];
            res = i;
        }
        else if(max == val[i])
            res = 26;
    }

    cout << chrarr[res];

    
}