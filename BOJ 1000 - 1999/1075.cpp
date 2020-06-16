// BOJ - 1075 나누기

#include<ios>
main(){long long int N,F;scanf("%lld%lld",&N,&F);printf("%02d",F-(N/100*100-1)%F-1);}