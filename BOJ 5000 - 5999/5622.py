# BOJ 5622 다이얼

a = "22233344455566677778889999"

s, r = input(), 0

for i in s:
    _ = ord(i) - 65
    if _ == '0':
        r += 10
    elif _ == '1':
        r += 1
    else:
        r += int(a[_])
r += len(s)

print(r)
