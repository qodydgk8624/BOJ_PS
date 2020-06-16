# BOJ - 1620

import sys
n,find=map(int,input().split())
d=dict()
for i in range(1,n+1):
    t = sys.stdin.readline().strip()
    d[t],d[str(i)]=i,t
for i in range(1,find+1):
    t = str(sys.stdin.readline().strip())
    print(d[t])
