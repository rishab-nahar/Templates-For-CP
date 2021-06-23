ll const mxn=200005;
vll order; //Stores the Topological Order
vll g[mxn];
ll degree[mxn];

bool toposort(ll n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{
    queue<ll> q;
    vector<ll> indeg(n + 1, 0);
    for(ll i = 1; i <= n; i++)
        for(auto &it:g[i])
            indeg[it]++;
    for(ll i = 1; i <= n; i++)
    {
        if(!indeg[i])
            q.push(i);
    }
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        order.push_back(u);
        for(auto &v:g[u])
        {
            indeg[v]--;
            if(!indeg[v])
                q.push(v);
        }
    }
    return (order.size() == n);
}