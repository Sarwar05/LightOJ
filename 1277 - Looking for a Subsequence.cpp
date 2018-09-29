#include<bits/stdc++.h>
using namespace std;
#define inf 1000000009
#define mx 100005
int arr[mx], L[mx], seq[mx];
int main()
{
    int tc,n,q,cs=1,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&q);
        seq[0] = -inf;
        for(int i=1; i<=n; i++){
            scanf("%d",&arr[i]);
            seq[i] = inf;
        }
        int len = 0;
        for(int i=n; i>=1; i--){
            int low = lower_bound(seq, seq+n+1, -arr[i]) - seq;
            seq[low] = -arr[i];
            L[i] = low;
            len = max(len, low);
        }
        printf("Case %d:\n", cs++);
        while(q--){
            scanf("%d",&a);
            if(a>len) printf("Impossible\n");
            else{
                int now = a, taken=0, prev = -inf;
                vector<int> ans;
                for(int i=1; i<=n && taken<a; i++){
                    if(L[i]>=now && arr[i]>prev){
                        ans.push_back(arr[i]);
                        now--;
                        taken++;
                        prev = arr[i];
                    }
                }
                printf("%d",ans[0]);
                for(int i=1; i<ans.size(); i++) printf(" %d",ans[i]);
                printf("\n");
            }
        }
    }
}
