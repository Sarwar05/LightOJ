#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vi vector<ll>
vi com, v;
void combination(int ind=0,ll sum=0)
{
    if(ind == v.size()){
        return;
    }
    else{
        for(int i=ind; i<v.size(); i++){
            sum+=v[i];
            com.push_back(sum);
            combination(i+1,sum);
            sum-=v[i];
        }
    }
}
int main()
{
    ll n,w,tc,a;
    scanf("%lld",&tc);
    for(ll cs=1; cs<=tc; cs++){
        scanf("%lld%lld",&n,&w);

        v.clear(); com.clear();
        com.push_back(0);
        for(int i=1; i<=n/2; i++){
            scanf("%lld",&a);
            v.push_back(a);
        }
        combination();
        vi com1 = com;
        v.clear(); com.clear();
        com.push_back(0);
        for(int i=n/2 + 1; i<=n; i++){
            scanf("%lld",&a);
            v.push_back(a);
        }
        combination();
        vi com2 = com;
        sort(com1.begin(), com1.end());
        ll ans = 0;

        for(int i=0; i<com2.size(); i++){

            ll need = w-com2[i];
            if(need<0) continue;
            else{
                int c = lower_bound(com1.begin(), com1.end(), need+1) - com1.begin();
                ans+=c;
            }
        }
        printf("Case %lld: %lld\n", cs, ans);
    }

    return 0;
}
