# 15945 Make Smiliar (2018 UCPC)

_,g=input,print;_();L=sorted([*map(int,_().split())])
p,q,l=min,max,len(L)
if L==l*[0] or(p(L)<0 and q(L)>0):g(0)
elif q(L)>0:
    L=[x for x in L if x!=0]
    g(p(p(L),q(L)-p(L)))
else:
    L=[x for x in L if x!=p(L)]
    g(p(q(L),q(L)-p(L)))
