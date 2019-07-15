#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int arr[mx], occur1[mx], cnt[mx], table[mx][17], v[mx], Log[mx];
void build(int n)
{
    for(int i=1; i<=n; i++)
        table[i][0] = cnt[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1; i+(1<<j)-1 <=n ;i++)
            table[i][j] = max( table[i][j-1],  table[i+(1<<(j-1))][j-1] );
}
int query(int i, int j)
{
    if(i>j) return 0;
    int k = Log[j-i+1];
    return max( table[i][k],table[j-(1<<k)+1][k] );
}
int main()
{
    Log[1] = 0;
    for(int i=2; i<mx; i++)
        Log[i] = Log[i/2]+1;
    int tc, cs=1;
    scanf("%d",&tc);
    while(tc--){
        int n, c, q;
        scanf("%d%d%d",&n,&c,&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&v[i]);
        int id = 0;
        for(int i=1; i<=n; i++){
            if(v[i]!=v[i-1]) id++;
            arr[i] = id;
        }
        memset(cnt, 0, sizeof cnt);
        for(int i=1; i<=n; i++){
            if(cnt[ arr[i] ] == 0)
                occur1[ arr[i] ] = i;
            cnt[ arr[i] ]++;
        }
        build(c);
        printf("Case %d:\n", cs++);
        while(q--){
            int l, ans, r;
            scanf("%d%d",&l,&r);
            if(arr[l]==arr[r]){
                ans = r-l+1;
            }
            else{
                int val = arr[l];
                int x = cnt[val] - (l-occur1[val]);
                l = occur1[val] + cnt[val];
                val = arr[r];
                int y = r - occur1[val] + 1;
                r = occur1[val]-1;
                ans = max(x,y);
                ans = max(ans, query(arr[l],arr[r]));
            }
            printf("%d\n", ans);
        }
    }
}
