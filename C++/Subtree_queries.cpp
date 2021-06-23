#define SZ 200005
ll n, m;
ll timer=-1;
ll start[SZ];
ll endd[SZ];
ll value[SZ];
vll a;
vector<ll> adj[SZ];

struct node{
    //req variable
    ll sum;
    //default value
    node()
    {
        sum=0;
    }
};


//s.init(n);
//s.put(a); //a is a vector of initial values
//s.build();
//s.query(); 0 based L,R included;
//for update
//s.a[ind]=newval;
//s.update(ind);

class segte {
public:
    ll n{};
    vector<node> tree;
    vector<ll> a;
    node neutral;

    void init(ll N) {
        n = N;
        tree.resize(4 * n + 1);
        //default values
        a.assign(n, 0);
    }

    void put(vector<ll> &val) {
        a = val;
    }

    //merge function
    void merge(node &curr, node &left, node &right) {
        curr.sum = left.sum + right.sum;
    }

    //for leaf
    void single(node &curr, ll idx) {
        curr.sum = a[idx];
    }

    void build(ll index, ll ss, ll se) {
        if (ss == se) {
            single(tree[index], ss);
            return;
        }
        ll mid = (ss + se) / 2;
        build(2 * index, ss, mid);
        build(2 * index + 1, mid + 1, se);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }

    void build() {
        build(1, 0, n - 1);
    }

    node query(ll index, ll ss, ll se, ll qs, ll qe) {
        if (qs > se || qe < ss) return neutral;
        if (qs <= ss && qe >= se) return tree[index];
        ll mid = (ss + se) / 2;
        node left = query(2 * index, ss, mid, qs, qe);
        node right = query(2 * index + 1, mid + 1, se, qs, qe);
        node mer;
        merge(mer, left, right);
        return mer;
    }

    node query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(ll index, ll idx, ll ss, ll se) {
        if (idx < ss || idx > se)
            return;
        if (ss == se) {
            single(tree[index], ss);
            return;
        }
        ll mid = (ss + se) / 2;
        update(2 * index, idx, ss, mid);
        update(2 * index + 1, idx, mid + 1, se);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }

    void update(ll idx) {
        update(1, idx, 0, n - 1);
    }
};


void dfs(ll u, ll p) {
    start[u] = ++timer;
    a[timer]=value[u];
    for(ll v: adj[u]){
        if(v!=p) {
            dfs(v, u);
        }
    }
    endd[u] = timer;
}
//0 base index;
//If want to update an entire subtree use lazy propagation
//update a node by s.a[start[node]]=val;s.update(start[node]];
//query a subtree by s.query(start[node],end[node])'