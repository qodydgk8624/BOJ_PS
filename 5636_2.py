# BOJ - 5636_2

import math

sieve = [True] * 100002


def bs():

    sieve[0] = sieve[1] = False # basic composite

    sqrtn = int(math.sqrt(100002))
    
    for i in range(2,sqrtn+1):

        if sieve[i]:

            for j in range(i+i,100002,i):

                sieve[j] = False

bs()

while True:

    nstr = input()

    n = int(nstr)

    if n == 0:

        break

    nlen = len(nstr)

    d = [0] * (nlen+1)

    for i in range(nlen):

        for j in range(i,nlen):

            dnstr = nstr[i:j+1]
            
            dn = int(nstr[i:j+1])

            if dn <= 100000:
                
                if sieve[dn]:

                    d[i] = dn

    res = 0
    
    for i in range(nlen):

        cmp = d[i]
        
        if res < cmp:

            res = cmp

    print(res)
