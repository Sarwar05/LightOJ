#include<bits/stdc++.h>
using namespace std;
long long fives(long long  n)
{
    long long p = 5, ret = 0;
    while(n/p>0){
        ret+=(n/p);
        p*=5;
    }
    return ret;
}
long long twos(long long  n)
{
    long long p = 2, ret = 0;
    while(n/p>0){
        ret+=(n/p);
        p*=2;
    }
    return ret;
}
int main()
{
    int tc; long long n,r,p,q;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%lld%lld%lld%lld",&n,&r,&p,&q);
        long long cf = fives(n)-(fives(n-r)+fives(r));
        long long ct = twos(n)-(twos(n-r)+twos(r));
        long long pf=0, tem = p, pt=0;
        while( p>0 && p%5==0){
            pf++;
            p/=5;
        }
        pf *=q;
        p = tem;
        while( p>0 && p%2==0){
            pt++;
            p/=2;
        }
        pt *=q;
        long long tot_f = (cf+pf), tot_t = (ct+pt);
        long long ans = min(tot_f, tot_t);
        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}
