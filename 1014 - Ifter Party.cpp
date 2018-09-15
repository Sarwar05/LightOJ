#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    int tc;
    ll p,l,b;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%lld%lld",&p,&l);
        p-=l;
        ll x = sqrt(p);
        vector<ll> v;
        for(ll i=1; i<=x; i++){
            if(p%i == 0){
                b = p/i;
                if( i>l)
                    v.push_back(i);
                if(b!=i && b>l)
                    v.push_back(b);
            }
        }
        printf("Case %d:",t);
        if(p==0 && l==0)
            v.push_back(1);
        ll sz = v.size();
        if(sz==0)
            printf(" impossible\n");
        else{
            sort(v.begin(),v.end());
            for(ll i=0; i<sz; i++)
                printf(" %lld",v[i]);
            printf("\n");
        }
    }
    return 0;
}