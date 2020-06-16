# BOJ - 7785

n = int(input())

log = set()

for i in range(n):

    strm = list(map(str,input().split()))

    if strm[1] == 'enter':
        log.add(strm[0])
    else:
        log.discard(strm[0])

for i in sorted(log,reverse=1):
    print(i)

        
