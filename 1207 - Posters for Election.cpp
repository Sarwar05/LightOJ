#include<bits/stdc++.h>
using namespace std;
#define mx 200005
int tree[mx*4],lazy[mx*4];
struct poster
{
    int l;
    int r;
}p[mx/2];
void update(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos] = (e-b+1);
        if(b!=e){
            lazy[l]++;
            lazy[r]++;
        }
        lazy[pos] = 0;
    }
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = (e-b+1);
        if(b!=e){
            lazy[l]++;
            lazy[r]++;
        }
        return;
    }
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    tree[pos] = tree[l] + tree[r];
}
int query(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos] = (e-b+1);
        if(b!=e){
            lazy[l]++;
            lazy[r]++;
        }
        lazy[pos] = 0;
    }
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int r1 = query(l,b,m,i,j);
    int r2 = query(r,m+1,e,i,j);
    return (r1 + r2);
}
int main()
{
    int tc,n,cs=1;
    scanf("%d",&tc);
    while(tc--){
        memset(tree, 0,sizeof tree);
        memset(lazy, 0,sizeof lazy);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d%d",&p[i].l, &p[i].r);
        }
        int ans = 0;
        for(int i=n; i>=1; i--){
            int tot = query(1,1,mx-1,p[i].l,p[i].r);
            if( (p[i].r - p[i].l + 1) > tot){
                ans++;
                update(1,1,mx-1,p[i].l, p[i].r);
            }
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}