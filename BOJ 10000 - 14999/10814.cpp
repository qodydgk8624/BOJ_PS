// BOJ - 10814 나이순 정렬

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct user {
    int age; int priority;
    string s;
    bool operator<(const user b)
    {
        if(age != b.age) return age < b.age;
        return priority < b.priority;
    }
    bool operator>(const user b)
    {
        if(age != b.age) return age > b.age;
        return priority > b.priority;
    }
};
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int n; cin >> n;
    user u[n];
    for(int i = 0; i < n; i++)
    {
        cin >> u[i].age >> u[i].s;
        u[i].priority = i;
    }

    sort(u, u + n);

    for(int i = 0; i < n; i++)
        cout << u[i].age << ' ' << u[i].s << '\n';

}  