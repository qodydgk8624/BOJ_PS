// BOJ - 14681 사분면 고르기

#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	bool aP = (a > 0), bP = (b > 0);
	if(aP&bP) cout << "1";
	else if(!aP&bP) cout << "2";
	else if(!aP&!bP) cout << "3";
	else cout << "4";
}
