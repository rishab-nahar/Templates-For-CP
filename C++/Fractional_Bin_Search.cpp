//this is Minimise
ld search(ld l,ld r)
{
    while (abs(l-r)/max((ld)1.0,l)>eps){
        ld mid=(l+r)/2;
        if (check(mid))r=mid;
        else l=mid;
    }
    ld ans=l;
    return ans;
}