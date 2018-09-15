#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define mx 1002
int x[mx],y[mx];
int main()
{
    int tc=1,cs=1,n,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        vector<pii> v;
        for(int i=0; i<n; i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                v.push_back({x[i]+x[j], y[i]+y[j]});
            }
        }
        sort(v.begin(),v.end());
        long long ans = 0,cnt=0;
        for(int i=1; i<v.size(); i++){
            if(v[i]==v[i-1]){
                cnt++;
            }
            else{
                cnt = (cnt*(cnt+1))/2;
                ans+=cnt;
                cnt=0;
            }
        }
        cnt = (cnt*(cnt+1))/2;
        ans+=cnt;
        printf("Case %d: %lld\n",cs++,ans);
    }
    return 0;
}
