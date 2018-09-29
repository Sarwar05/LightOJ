#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define inf 2000000009
int lis1[mx], lis2[mx], arr[mx], lis[mx];
int main()
{
    int n,tc,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        lis[0] = -inf;
        lis1[0] = lis2[n+1] = 0;
        for(int i=1; i<=n; i++){
            lis[i] = inf;
        }
        for(int i=1; i<=n; i++){
            int low = lower_bound(lis, lis+n+1, arr[i]) - lis;
            lis1[i] = max(low, lis1[i-1]);
            lis[low] = arr[i];
        }
        lis[0] = -inf;
        for(int i=1; i<=n; i++){
            lis[i] = inf;
        }
        for(int i=n; i>=1; i--){
            int low = lower_bound(lis, lis+n+1, arr[i]) - lis;
            lis2[i] = max(low, lis2[i+1]);
            lis[low] = arr[i];
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, -1 + 2*min(lis1[i], lis2[i]));
        }
        printf("Case %d: %d\n",cs++, ans);
    }
}
