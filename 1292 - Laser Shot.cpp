#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mx 702
#define ll long long
int x[mx], y[mx];
int main()
{
    int tc,cs=1,n,ans;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d%d",&x[i], &y[i]);
        }
        ans = 0;
        for(int  i=0; i<n; i++){
            vector<ll> v;
            for(int j=0; j<n; j++){
                if(i==j )continue;
                double a = y[j]-y[i];
                double b = x[j]-x[i];
                v.push_back((ll)((a/b)*10000000000LL));
            }
            if(v.size()==0){
                ans = 1;
                continue;
            }
            int cnt=1;
            sort(v.begin(),v.end());
            for(int i=1; i<v.size(); i++){
                if(v[i]==v[i-1]){
                    cnt++;
                }
                else{
                    ans=max(ans,cnt+1);
                    cnt=1;
                }
            }
            ans=max(ans,cnt+1);
        }
        printf("Case %d: %d\n", cs++,ans);
    }
    return 0;
}
