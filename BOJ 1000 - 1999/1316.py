# BOJ 1316 그룹 단어 체커

n, res = int(input()), 0
for _ in range(n):
    s, prev = input(), ""
    d, b = dict(), True
    for i in s:
        if prev == i:
            continue
        elif not i in d:
            d[i] = 1
        else:
            b = False
        prev = i
    if b: res += 1
print(res)
