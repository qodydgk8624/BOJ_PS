// BOJ - 9507 Generations of Tribbles

#include <iostream>
#define ll long long int

using namespace std;

ll D[68],n,T;
int main()
{
	D[0]=1,D[1]=1,D[2]=2,D[3]=4;
	for(int i=4; i<=67; i++)
		D[i]=D[i-1]+D[i-2]+D[i-3]+D[i-4];
	cin >> T;
	while(T--)
	{
		cin >> n;
		cout << D[n] << "\n";
	}
}