# BOJ 10809 알파벳 찾기

s = input()
d = dict()
p = 0
for i in s:
    if i in d:
        pass
    else:
        d[i] = p
    p += 1

K = "abcdefghijklmnopqrstuvwxyz"
for i in K:
    if i in d:
        print("%d " % d[i], end="")
    else:
        print("-1 ", end="")
