#include<bits/stdc++.h>
using namespace std;
#define ll long long
int setBit(int N, int pos)
{
    return (N|(1<<pos));
}
bool isNotSet(int N, int pos)
{
    return !(N&(1<<pos));
}
ll dp[20][(1<<16)+2];
int k,n,base;
int arr[17];
char str[17];
int getMod(int md, int num)
{
    md = ((md*base) + num)%k;
    return md;
}
ll fun(int mask, int mod)
{
    if(mask==(1<<n)-1){
        return (mod==0) ? 1 : 0;
    }
    if(dp[mod][mask]!=-1) return dp[mod][mask];
    ll ret = 0;
    for(int i=0; i<n; i++){
        if(isNotSet(mask,i)){
            int md = getMod(mod, arr[i]);
            ret+=fun(setBit(mask,i),md);
        }
    }
    return dp[mod][mask] = ret;
}
int main()
{
    map<char, int> mp;
    int tc,cs=1;
    tc=0;
    for(char i='0'; i<='9'; i++) mp[i] = tc++;
    for(char i='A'; i<='F'; i++) mp[i] = tc++;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&base, &k);
        scanf("%s",str);
        n = strlen(str);
        for(int i=0; i<n; i++){
            arr[i] = mp[ str[i] ];
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n",cs++, fun(0,0));
    }
    return 0;
}
