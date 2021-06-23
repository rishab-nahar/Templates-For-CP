tot = 200005 #max value of n in nCr
mod = 998244353 #mod value
fac = [1, 1]
finv = [1, 1]
inv = [0, 1]

for start in range(2, tot + 1):
    fac.append((fac[-1] * start) % mod)
    inv.append(mod - (inv[mod % start] * (mod // start) % mod))
    finv.append(finv[-1] * inv[-1] % mod)


def comb(n, r):
    if (r == 0 or r == n): return 1
    if n < r:
        return 0
    else:
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod


#p is a small prime
def ncr_small_mod_p(n,r):
    ans=1
    while(n>0):
        x=n%p
        y=r%p
        n//=p
        r//=p
        ans*=comb(x,y)
        ans%=p
    return ans

