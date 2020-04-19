// BOJ - 2588 °ö¼À 

#include <iostream>
#define ll long long int

using namespace std;


int main()
{
	// Input 2 Numbers
	ll num1, num2;
	cin >> num1 >> num2;
	
	ll res = num1 * num2;
	
	for(; num2 != 0; num2 /= 10)
		cout << num1 * (num2 % 10) << "\n";
		
	cout << res << "\n";
}
