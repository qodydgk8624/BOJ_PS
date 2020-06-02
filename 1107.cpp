// BOJ - 1107 리모컨

#include <iostream>
#include <cmath>

using namespace std;

int channel[10]={0};

int check(int temp)
{
    int len = 0;

    if(temp == 0)
    {
        if(channel[0])
            return 0;
        else
            return 1;
    }

    while(temp > 0)
    {
        if(channel[temp%10])
            return 0;

        len++;
        temp /= 10;
    }

    return len;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    for(int i=0; i<M; i++)
    {
        int num;
        cin >> num;
        channel[num] = 1;
    }

    int result = abs(N-100);

    for(int i=0; i<=1000000; i++)
    {
        int len = check(i);
        if(len != 0)
            result = min(result,len+abs(N-i));
    }

    cout << result << '\n';

    return 0;
}
 