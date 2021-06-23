
struct BIT //1 base index , Search is a good function
{
    ll N;
    vector<ll> bit;

    void init(ll n)
    {
        N = n;
        bit.assign(n + 1, 0);
    }

    void update(ll idx, ll val)//increment a val at position
    {
        while(idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll pref(ll idx)
    {
        ll ans = 0;
        while(idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    ll rsum(ll l, ll r)
    {
        return pref(r) - pref(l - 1);
    }

    //returns first index such that pref[idx] >= val

    ll search(ll val)
    {
        ll curSum = 0, pos = 0;
        for(ll i = log2(N) + 1; i >= 0; i--)
        {
            if(pos + (1LL << i) < N && curSum + bit[pos + (1LL << i)] < val)
            {
                curSum += bit[pos + (1LL << i)];
                pos += (1LL << i);
            }
        }
        return pos + 1;
    }

    void updateMax(ll idx, ll val)
    {
        while(idx <= N)
        {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    ll prefMax(ll idx)
    {
        ll ans = -2e9;
        while(idx > 0)
        {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};
