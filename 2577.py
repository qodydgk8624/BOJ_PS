A=int(input())
B=int(input())
C=int(input())
res=str(A*B*C)
a = [0] * 10
for i in range(len(res)):
    a[int(res[i])] += 1
for i in range(10):
    print(a[i])
