// BOJ - 9252 LCS 2

#include <iostream>
#include <string>
#include <utility>

#define mp make_pair


using namespace std;


string a,b;

int D[1002][1002]={0};

int max(int o,int o2)
{
	return o>o2?o:o2;
}
void f(int i,int j)
{
	if(!D[i][j]) return;
	if(a[i]==b[j])
	{
		f(i-1,j-1);
		putchar(a[i]);
	}
	else D[i-1][j]>D[i][j-1]?f(i-1,j):f(i,j-1);
}
int main()
{
	cin >> a >> b;
	a.insert(a.begin(),0);
	b.insert(b.begin(),0);
	for(int i=1; i<=a.size(); i++)
		for(int j=1; j<=b.size(); j++)
			D[i][j]=max(D[i-1][j],max(D[i][j-1],D[i-1][j-1]+(a[i]==b[j])));
			
	cout << D[a.size()-1][b.size()-1] << endl;
	
	f(a.size()-1,b.size()-1);
}