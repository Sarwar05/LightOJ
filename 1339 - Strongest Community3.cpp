#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int arr[mx], occur1[mx], cnt[mx], tree[mx*4], v[mx];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos] = cnt[b];
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos] = max(tree[l], tree[r]);
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return max(query(l,b,m,i,j), query(r,m+1,e,i,j));
}
int main()
{
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
        build(1,1,c);
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
                ans = max(ans, query(1,1,c,arr[l],arr[r]));
            }
            printf("%d\n", ans);
        }
    }
}
