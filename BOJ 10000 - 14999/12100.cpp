// BOJ - 12100

#include <stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}

int n,maxv=0;
int ori[21][21];
int val[21][21];

int chk[5];
// 1 left , 2 right , 3 up , 4 down

void process(int dir)
{
	if(dir==1)
	{
		for(int i=1; i<=n; i++)
		{
			int _line[n+1]={0},idx=1;
			for(int j=1; j<=n; j++)
				if(val[i][j]!=0) _line[idx++]=val[i][j];
			for(int j=1; j<n; j++)
				if(_line[j]!=0 && _line[j]==_line[j+1])
					_line[j]*=2,_line[j+1]=0;
			idx=1;
			for(int j=1; j<=n; j++)
				if(_line[j]!=0) val[i][idx++]=_line[j];
			for(int j=idx; j<=n; j++)
				val[i][j]=0;
		}
	}
	else if(dir==2)
	{
		for(int i=1; i<=n; i++)
		{
			int _line[n+1]={0},idx=n;
			for(int j=n; j>=1; j--)
				if(val[i][j]!=0) _line[idx--]=val[i][j];
			for(int j=n; j>1; j--)
				if(_line[j]!=0 && _line[j]==_line[j-1])
					_line[j]*=2,_line[j-1]=0;
			idx=n;
			for(int j=n; j>=1; j--)
				if(_line[j]!=0) val[i][idx--]=_line[j];
			for(int j=idx; j>=1; j--)
				val[i][j]=0;
		}
	}
	else if(dir==3)
	{
		for(int i=1; i<=n; i++)
		{
			int _line[n+1]={0},idx=1;
			for(int j=1; j<=n; j++)
				if(val[j][i]!=0) _line[idx++]=val[j][i];
			for(int j=1; j<n; j++)
				if(_line[j]!=0 && _line[j]==_line[j+1])
					_line[j]*=2,_line[j+1]=0;
			idx=1;
			for(int j=1; j<=n; j++)
				if(_line[j]!=0) val[idx++][i]=_line[j];
			for(int j=idx; j<=n; j++)
				val[j][i]=0;
		}
	}
	else if(dir==4)
	{
		for(int i=1; i<=n; i++)
		{
			int _line[n+1]={0},idx=n;
			for(int j=n; j>=1; j--)
				if(val[j][i]!=0) _line[idx--]=val[j][i];
			for(int j=n; j>1; j--)
				if(_line[j]!=0 && _line[j]==_line[j-1])
					_line[j]*=2,_line[j-1]=0;
			idx=n;
			for(int j=n; j>=1; j--)
				if(_line[j]!=0) val[idx--][i]=_line[j];
			for(int j=idx; j>=1; j--)
				val[j][i]=0;
		}
	}
}

void dfs(int k)
{
	if(k==6)
	{
		// √ ±‚»≠ 
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				val[i][j]=ori[i][j];
				
		for(int i=1; i<=5; i++)
			process(chk[i]);
			
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				maxv=max(maxv,val[i][j]);
	}
	else
	{
		for(int i=1; i<=4; i++)
		{
			chk[k]=i;
			dfs(k+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		int q;
		scanf("%d",&q);
		printf("%d",q);
		return 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&ori[i][j]);
	/*for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				val[i][j]=ori[i][j];
	process(4);
	process(4);
	for(int i=1; i<=n; puts(""),i++)
		for(int j=1; j<=n; j++)
			printf("%d ",val[i][j]);*/
	dfs(1);
	printf("%d",maxv);
}
