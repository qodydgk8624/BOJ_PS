// BOJ - 2884 알람 시계

#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	b -= 45;
	if(b < 0)
	{
		b += 60;
		a -= 1;
	}
	if(a == -1)
		a = 23;
	printf("%d %d", a, b);
	
}
