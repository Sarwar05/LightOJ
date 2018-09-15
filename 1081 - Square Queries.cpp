#include<bits/stdc++.h>
using namespace std;
#define mx 502
int tree[mx][mx*4];
int arr[mx][mx];
 
void build(int id, int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[id][pos] = arr[id][b];
        return;
    }
    int m = (b+e)/2;
    int l = pos*2+1;
    int r = l+1;
    build(id,l,b,m);
    build(id,r,m+1,e);
    tree[id][pos] = max(tree[id][l],tree[id][r]);
}
void build_util(int n, int m)
{
    for(int i=1; i<=n; i++){
        build(i,1,1,m);
    }
}
int query(int id, int pos, int b, int e,int i, int j)
{
    if(b>e||b>j||e<i) return 0;
    if(b>=i && e<=j) return tree[id][pos];
    int m = (b+e)/2;
    int l = pos*2+1;
    int r = l+1;
    return max(query(id,l,b,m,i,j),query(id,r,m+1,e,i,j));
}
void query_util(int r1,int r2, int c1, int c2,int m)
{
    int ans = 0;
    for(int i=r1; i<=r2; i++){
        ans = max(ans,query(i,1,1,m,c1,c2));
    }
    printf("%d\n",ans);
}
int main()
{
    int tc,cs=1,n,a,b,s,q;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d",&arr[i][j]);
            }
        }
        printf("Case %d:\n",cs++);
        build_util(n,n);
        while(q--){
            scanf("%d%d%d",&a,&b,&s);
            query_util(a,a+s-1,b,b+s-1,n);
        }
    }
    return 0;
}