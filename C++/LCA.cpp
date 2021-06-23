//for Binary lifting part only have a look at: https://codeforces.com/contest/739/submission/106015652
//This implementation only works for 1 based
//!!!! Make sure to use 1 base indexing
const ll N=1e6+10;
const ll LG= 20;
ll n;
ll tim=0;
ll parent[LG][N];
ll tin[N], tout[N], level[N];
vector<ll> g[N];

void dfs(ll k, ll par, ll lvl)
{
    tin[k]=++tim;
    parent[0][k]=par;
    level[k]=lvl;
    for(auto it:g[k])
    {
        if(it==par)
            continue;
        dfs(it, k, lvl+1);
    }
    tout[k]=tim;
}

void precompute()
{
    for(ll i=1;i<LG;i++)
        for(ll j=1;j<=n;j++)
            if(parent[i-1][j])
                parent[i][j]=parent[i-1][parent[i-1][j]];
}

ll LCA(ll u, ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll diff=level[u]-level[v];
    for(ll i=LG-1;i>=0;i--)
    {
        if((1<<i) & diff)
        {
            u=parent[i][u];
        }
    }
    if(u==v)
        return u;
    for(ll i=LG-1;i>=0;i--)
    {
        if(parent[i][u] && parent[i][u]!=parent[i][v])
        {
            u=parent[i][u];
            v=parent[i][v];
        }
    }
    return parent[0][u];
}

ll dist(ll u, ll v)
{
    return level[u] + level[v] - 2*level[LCA(u, v)];
}


ll kthancestor(ll v,ll k)
{
    for(ll i=0;i<LG;i++)
    {
        if(k & (1<<i))
        {
            v=parent[i][v];

        }
    }
    return v;
}