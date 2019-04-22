# BOJ - 5636

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

    n = input()

    lenn = len(n)+1

    if n == "0":

        break

    d = [0] * (lenn)
    
    for i in range(lenn):

        #print(d)
        
        for j in range(i,lenn):

            cmp = n[i:j+1]
            
            #print("-", cmp)

            if cmp == "":

                continue
            
            if int(cmp) > 100000:

                break

                print(int(cmp))
                
                if sieve[int(cmp)]:

                    d[i] = j-i+1

    max = 0

    for i in range(lenn):

        p = int(d[i])

        cmp = n[i:i+p+1]

        if cmp == "":

            break
        
        if max < int(cmp):

            max = int(cmp)

    print(d)
    
    print(max)
