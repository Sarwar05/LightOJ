#include<bits/stdc++.h>
using namespace std;
#define mx 30005
int arr[mx];
struct node
{
    int val;
    int ind;
}tree[mx*4],zero;
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos].val = arr[b];
        tree[pos].ind = b;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l + 1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos].val = min(tree[l].val, tree[r].val);
    tree[pos].ind = (tree[l].val == tree[pos].val) ? tree[l].ind : tree[r].ind;
}
node query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return zero;
    if(b>=i && e<=j) return tree[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l + 1;
    node p1 = query(l,b,m,i,j);
    node p2 = query(r,m+1,e,i,j);
    if(p1.val == 0) return p2;
    if(p2.val == 0) return p1;
    if(p1.val<p2.val)
        return p1;
    else
        return p2;
}
int solve(int b, int e,int n)
{
    if(b>e) return 0;
    if(b==e){
        return arr[b];
    }
    node x = query(1,1,n,b,e);
    int r1 = x.val * (e-b+1);
    int r2 = solve(b,x.ind-1,n);
    int r3 = solve(x.ind+1,e,n);
    return max(r1, max(r2,r3));
}
int main()
{
    int n,tc,cs=1;
    scanf("%d", &tc);
    zero.ind = 0;
    zero.val = 0;
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        build(1,1,n);
        printf("Case %d: %d\n",cs++,solve(1,n,n));
    }
    return 0;
}