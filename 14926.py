# BOJ - 14926

n = int(input())

d = [[0]*(n+1) for i in range(n+1)]

d[1][n] = d[n][1]=1

c,p = 0,0

while c != n*(n-1)//2:
    
    for v in range(1,n+1):

        if d[p][v] or p==v:
            
            continue

        d[p][v]=d[v][p]=1

        p=v

        break

    print('a%d'%p,end=' ')

    c += 1

print('a1')
