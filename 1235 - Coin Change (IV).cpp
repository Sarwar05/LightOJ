#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> comb1, comb2;
ll arr[20];
bool ans;
ll m,n;
void combine1(int pos, ll sum)
{
    comb1.push_back(sum);
    if(pos==(n/2)) return;
    combine1(pos+1,sum);
    combine1(pos+1,sum+arr[pos]);
    combine1(pos+1,sum+2*arr[pos]);
}
void combine2(int pos, ll sum)
{
    comb2.push_back(sum);
    if(pos==n) return;
    combine2(pos+1,sum);
    combine2(pos+1,sum+arr[pos]);
    combine2(pos+1,sum+2*arr[pos]);
}
int main()
{
    ll tc;
    scanf("%lld", &tc);
    ll cs=1;
    while(tc--){
        scanf("%lld%lld", &n, &m);
        for(int i=0; i<n; i++){
            scanf("%lld",&arr[i]);
        }
        ans = false;
        comb1.clear();
        comb2.clear();
        combine1(0,0);
        combine2(n/2,0);
        sort(comb1.begin(),comb1.end());
        for(int i=0; i<comb2.size() && !ans; i++){
            ll need = m - comb2[i];
            if(binary_search(comb1.begin(), comb1.end(), need)){
                ans = true;
                break;
            }
        }
        if(ans){
            printf("Case %lld: Yes\n", cs++);
        }
        else{
            printf("Case %lld: No\n", cs++);
        }
    }
    return 0;
}
