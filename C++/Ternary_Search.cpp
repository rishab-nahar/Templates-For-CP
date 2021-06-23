//* Find the smallest i in [a,b] that maximizes f(i), assuming that f(a) < f(i) <= f(b)$.
//* To reverse which of the sides allows non-strict inequalities, change the < marked with (A) to <=, and reverse the loop at (B).
//* To minimize f, change it to >, also at (B).

ll ternSearch(ll a, ll b) {
    assert(a <= b);
    while (b - a >= 5) {
        ll mid = (a + b) / 2;
        if (f(mid) < f(mid+1)) a = mid; // (A)
        else b = mid+1;
    }
    for(ll i=a+1;i<(b+1),i++) if (f(a) < f(i)) a = i; // (B)
    return a;
}