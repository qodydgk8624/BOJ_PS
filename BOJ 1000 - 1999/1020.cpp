// BOJ - 1020

#include <iostream>
#include <string>
#include <vector>
#define ll long long

using namespace std;

string _s; vector<int> num;
ll length,cmp=0,cur=0,ans=0;
// cmp = 처음 숫자들의 선분들의 총합 

int v[10]={6,2,5,5,4,5,6,3,7,5}; // 각각 숫자들의 선분들의 개수

void add() // 1 더하기 
{
	ans++;
/*	for(int i=length-1; i>=0; i--) printf("%d",num[i]);
	puts("");*/
	num[0]=(num[0]+1)%10;
	int pos=0;
	while(!num[pos])
	{
		++pos;
		if(pos==length) break;
		num[pos]=(num[pos]+1)%10;
	}
/*	for(int i=length-1; i>=0; i--) printf("%d",num[i]);
	puts("");*/
	
}

int tle()
{
	int one_cnt=0,eight_cnt=0;
	for(int i=0; i<length; i++)
	{
		if(num[i]==1) one_cnt++;
		if(num[i]==8) eight_cnt++;
	}
	if(one_cnt == length || eight_cnt == length)
	{
		ll res=1;
		for(int i=1; i<=length; i++) res*=10;
		printf("%lld",res);
		return 1;
	}
	else return 0;
}
ll calc()
{
	ll ret=0;
	for(int i=0; i<length; i++) ret+=v[num[i]];
	return ret;
}
int main()
{
	cin >> _s;
	length=_s.length();
	num.resize(length);
	for(int i=0; i<length;i++) num[length-i-1]=_s[i]-'0';
	if(tle()) return 0;
	cmp=calc();
	add();
	while(calc()!=cmp) add();
	printf("%lld",ans);
	
}
