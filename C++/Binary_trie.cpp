//left =0  | right=1 | cnt=number of numbers with this prefix
struct node {
    ll left = 0, right = 0;
    ll cnt = 0;
};

const ll maxbits=30;
const ll maxnodes=2e6+25;
node trie_ar[maxnodes];
ll ptr=2;
struct Binary_trie{

    void init() {
        for (int i = 0; i < ptr; i++) {
            trie_ar[i].left=0;
            trie_ar[i].right=0;
            trie_ar[i].cnt = 0;
        }
        ptr = 2;
    }

    void insert(ll x){
        ll curr=1;
        for(ll i =maxbits;i>=0;i--){
            if((x&(1LL<<i))==0){
                if(!trie_ar[curr].left){
                    trie_ar[curr].left=ptr++;
                }
                curr=trie_ar[curr].left;
            }else{
                if(!trie_ar[curr].right){
                    trie_ar[curr].right=ptr++;
                }
                curr=trie_ar[curr].right;
            }
            trie_ar[curr].cnt++;
        }
    }
    ll max_xor(ll x) {
        ll curr = 1;
        ll ans = 0;
        for (ll i = maxbits; i >= 0; i--) {
            if ((x & (1LL << i)) == 0) {
                if (trie_ar[trie_ar[curr].right].cnt > 0) {
                    curr = trie_ar[curr].right;
                    ans |= (1LL << i);
                } else {
                    curr = trie_ar[curr].left;
                }
            } else {
                if (trie_ar[trie_ar[curr].left].cnt > 0) {
                    curr = trie_ar[curr].left;
                    ans |= (1LL << i);
                } else {
                    curr = trie_ar[curr].right;
                }
            }
        }
        return ans;
    }
    //assumes x is there atleast one more time
    void remove(ll x){
        ll curr=1;
        for(ll i=maxbits;i>=0;i--){
            if((x&(1LL<<i))==0){
                curr=trie_ar[curr].left;
            }else{
                curr=trie_ar[curr].right;
            }
            trie_ar[curr].cnt--;
        }
    }
};