// BOJ - 3052

#include <stdio.h>

int main()
{
	int duplicate_num[42]={0};
	for(int i=1; i<=10; i++)
	{
		int k;
		scanf("%d",&k);
		duplicate_num[k%42]++;
	}
	int answer=0;
	for(int i=0; i<42; i++)
		if(duplicate_num[i])
			answer++;
	printf("%d",answer);
}
