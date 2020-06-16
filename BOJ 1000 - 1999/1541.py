# BOJ - 1541

n=input()
for i in range(0,len(n)):
    if(n[i]=='-'):
        print(sum(map(int,n[:i].replace('+',' ').split()))-sum(map(int,n[i:].replace('+',' ').replace('-',' ').split())))
        break
if '-' not in n:
    print(sum(map(int,n.replace('+',' ').split()))) 


