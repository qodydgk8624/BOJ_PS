// BOJ - 10996 º° Âï±â - 21

#include <iostream>

using namespace std;

void p_char(int n, char k)
{
	for(int i=0; i<n; i++) cout << k;
}
void p_star(int l_num, int len)
{
	char chr[2] = {'*', ' '};
	int start = l_num % 2;
	
	for(int i = 1; i <= len; i++, start = 1 - start)
		cout << chr[start];
		
	cout << "\n";
}
int main()
{
	int n;
	cin >> n;
	if(n == 1) {
		cout << "*";
		return 0;
	}
	for(int i = 0; i < 2 * n; i++)
		p_star(i, n);
} 
