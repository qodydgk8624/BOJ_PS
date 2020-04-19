// BOJ - 2446 별 찍기 - 9

#include <iostream>

using namespace std;

void p_char(int n, char k)
{
	for(int i=0; i<n; i++) cout << k;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		p_char(i, ' ');
		p_char(2 * (n - i) - 1, '*');
		p_char(1, '\n');
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		p_char(i, ' ');
		p_char(2 * (n - i) - 1, '*');
		p_char(1, '\n');
	}
} 
