#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define mx 1002
#define mod 1000007
int dp[mx][mx];
char str1[mx], str2[mx];
int len1,len2;
int fun(int i, int j)
{
    if(i>=len1 || j>=len2) return 0;
    int& ret = dp[i][j];
    if(ret!=-1) return ret;
    if(str1[i]==str2[j]) ret = max(ret, 1 + fun(i+1, j+1));
    else{
        ret = max(ret, fun(i+1, j));
        ret = max(ret, fun(i, j+1));
    }
    return ret;
}
vector<int> pos1[27], pos2[27];
map< pair< pii, int>, ll > mp;
ll solve(int ii, int jj, int rem)
{
    if(rem==0) return 1LL;
    pair<pii, int> now = make_pair( make_pair(ii,jj), rem );
    if(mp.find(now)!=mp.end())  return mp[now];
    ll ret = 0;
    for(char ch = 'a'; ch<='z'; ch++){
        int id = ch-'a', i, j;
        i = lower_bound(pos1[id].begin(), pos1[id].end(), ii) - pos1[id].begin();
        j = lower_bound(pos2[id].begin(), pos2[id].end(), jj) - pos2[id].begin();
        for(i; i<pos1[id].size(); i++){
            int got = 0;
            int id1 = pos1[id][i];
            for(j; j<pos2[id].size(); j++){
                int id2 = pos2[id][j];
                if(dp[id1][id2]==rem){
                    got = 1;
                    ret+=solve(id1+1, id2+1, rem-1);
                    ret%=mod;
                }
                if(got==1) break;
            }
            if(got==1) break;
        }
    }
    mp[now] = ret;
    return ret;
}
int main()
{
    int tc,cs=1;
    scanf("%d%d",&tc);
    while(tc--){
        mp.clear();
        for(int i=0; i<27; i++){
            pos1[i].clear();
            pos2[i].clear();
        }

        scanf("%s",str1);
        len1 = strlen(str1);
        for(int i=0; i<len1; i++)
            pos1[ str1[i] - 'a' ].push_back(i);

        scanf("%s",str2);
        len2 = strlen(str2);
        for(int i=0; i<len2; i++)
            pos2[ str2[i] - 'a' ].push_back(i);

        memset(dp, -1, sizeof dp);
        int lcs = fun(0,0);

        ll ans = solve(0,0,lcs);

        printf("Case %d: %lld\n", cs++,ans);
    }
}
