const ll mxn=1e6 +5;
ll lar[mxn]={};
vll primes;
//lar[i] contains the largest primefactor of i
void precompute()
{
    forsi(2,mxn-2)
    {
        if(lar[i]==0)
        {
            primes.push_back(i);
            for(ll j=i;j<=mxn-2;j+=i)
                lar[j]=i;
        }
    }
}