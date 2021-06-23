
vector<pair<ll,ll>>v[200001];
ll dist[200001];
ll n,m;
void dijkstra(ll source)
{
    for(ll i=0;i<n;i++)
        dist[i]=INF;
    dist[source]=0;
    set<pair<ll,ll>>s;
    s.insert({0,source});
    while(!s.empty())
    {
        ll vert=s.begin()->second;
        s.erase(s.begin());
        for(auto c:v[vert])
        {
            if(dist[c.first]>dist[vert]+c.second)
            {
                if(s.count({dist[c.first],c.first}))
                    s.erase({dist[c.first],c.first});
                dist[c.first]=dist[vert]+c.second;
                s.insert({dist[c.first],c.first});
            }
        }
    }
}

