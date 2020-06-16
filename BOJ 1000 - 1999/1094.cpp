// BOJ - 1094 막대기

#include<ios>
main(){int n,s=1;scanf("%d",&n);while(n>1){if(n%2)s++;n/=2;}printf("%d",s);}