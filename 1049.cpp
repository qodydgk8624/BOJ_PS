// BOJ - 1049

#include <iostream>

using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int n,m,pack=987654321,per=987654321;
	cin >> n >> m;
	for(int i=1; i<=m; i++)
	{
		int _1,_2;
		cin >> _1 >> _2;
		pack=min(pack,_1);
		per=min(per,_2);
	}
	int ans=987654321;
	if(n<6) ans=min(pack,per*n);
	else ans=min(pack*(n/6)+per*(n%6),min(per*n,pack*(n/6+1)));
	cout << ans;
}
