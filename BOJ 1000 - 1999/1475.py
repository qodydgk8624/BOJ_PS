# BOJ - 1475

d,ans=[0]*10,0

for i in list(input()):
    i = int(i)
    d[i]+=1
    if i==6 or i==9:
        ans=(ans,(d[6]+d[9]+1)//2)[(d[6]+d[9]+1)//2>ans]
    else:
        ans=(ans,d[i])[d[i]>ans]
    

print(ans)
