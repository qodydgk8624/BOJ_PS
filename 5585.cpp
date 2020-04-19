// BOJ - 5585

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int coin[6]={500,100,50,10,5,1};
	n=1000-n;
	int res=0;
	for(int i=0; i<6; i++)
	{
		res += (n/coin[i]);
		n%=coin[i];
	}
	cout << res;
}
