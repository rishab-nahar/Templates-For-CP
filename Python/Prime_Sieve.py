#lrg[i] stores largest prime divisor of i
mxn=100005
lrg=[0]*mxn
primes=set()
for start in range(2,mxn-3):
    if (lrg[start]==0):
        primes.add(start)
        for j in range(start,mxn-3,start):
            lrg[j]=start