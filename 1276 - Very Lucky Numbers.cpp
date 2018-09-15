#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll lim = 1000000000000LL;
set<ll> st, ini;
vector<ll> num;
void dfs(ll n)
{
    ll xxx = n*10 + 4;
    if(xxx<=lim){
        st.insert(xxx);
        dfs(xxx);
    }
    xxx = n*10 + 7;
    if(xxx<=lim){
        st.insert(xxx);
        dfs(xxx);
    }
}
int main()
{
    dfs(0);
    ini = st;
    set<ll> ::iterator it = ini.begin();
    while(it!=ini.end()){
        ll x = *it;
        set<ll> vv;
        int cnt = 0;
        for(set<ll> ::iterator it2 = st.begin(); it2!=st.end(); it2++){
            ll res = *it2;
            ll p = (lim/res);
            p = (log(p)/log(x));
            if(p==0) break;
            for(ll i=1; i<=p; i++){
                res*=x;
                vv.insert(res);
            }
            cnt = 1;
        }
        if(cnt==0)
            break;
        for(set<ll> ::iterator it2 = vv.begin(); it2!=vv.end(); it2++){
            st.insert(*it2);
        }
        it++;
    }
    for(set<ll> ::iterator it2 = st.begin(); it2!=st.end(); it2++){
        num.push_back(*it2);
    }
    int tc,cs=1,ans;
    ll a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%lld%lld",&a,&b);
        int x = lower_bound(num.begin(), num.end(), a) - num.begin();
        int y = upper_bound(num.begin(), num.end(), b) - num.begin() - 1;
        printf("Case %d: %d\n", cs++, y-x+1);
    }
}
