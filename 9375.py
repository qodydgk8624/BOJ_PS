# BOJ 9375 패션왕 신해빈

testcase = int(input())

for i in range(testcase):

    n = int(input())
    d = dict()
    for _ in range(n):
        name, type = input().split()
        if type in d:
            d[type] += 1
        else:
            d[type] = 1

    res = 1
    for v in d.values():
        res *= (v + 1)

    res -= 1

    print(res)
    
