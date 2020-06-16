
import math

mod = 1000000007

def main():

    n = int(input())

    n //= 2
    same = dict()
    same_twice = dict()
    pp = 1
    p = 3
    c = 0
    for i in range(1,n):
        c = (p*4-pp+mod)%mod
        if c in same_twice:
            print("\t\t\t 두번 중복 => ", c)
        elif c in same:
            print("ALERT! 중복! => ",c)
            same_twice[c]=1
        else:
            same[c]=1
            #print(c)
        pp,p=p,c
    print(c)
    print("end")
    
if __name__ == "__main__":

    main()
