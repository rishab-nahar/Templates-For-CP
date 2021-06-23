
const ll N=2e5 +5;
ll RMQ[20][N]  , floorlog[N] , values_ar[N];

void precompute(ll n) // 1 based index(make values_ar array 1 base)
{
    for(ll i=0;(1<<i)<N;i++)
    {
        for(ll j=(1<<i);j<N && j<(1<<(i+1)); j++)
            floorlog[j]=i;
    }

    for(ll i=n;i>=1;i--)
    {
        RMQ[0][i]=values_ar[i];
        ll mxj=floorlog[n-i+1]; //2^j <= n-i+1
        ll pw=1;
        for(ll j=1;j<=mxj;j++)
        {
            RMQ[j][i]=min(RMQ[j-1][i], RMQ[j-1][i+pw]);
            pw<<=1LL;
        }
    }
}

ll getMin(ll L, ll R) //L include , R excluded  1 based(like values_ar array)
{
    ll k=floorlog[R-L+1]; //2^k <= R-L+1
    return min(RMQ[k][L], RMQ[k][R - (1<<k) +1]);
}