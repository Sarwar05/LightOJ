#include<bits/stdc++.h>
using namespace std;
#define mx 1429434
struct node
{
    int val=0;
    int cnt=0;
}tree[mx*4];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        if(b%2==0)return;
        tree[pos].val = b;
        tree[pos].cnt = 1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos].cnt = tree[l].cnt + tree[r].cnt;
}
int query(int pos, int b, int e,int kth)
{
    if(b==e)return tree[pos].val;
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(kth<=tree[l].cnt)
        return query(l,b,m,kth);
    else
        return query(r,m+1,e,kth-tree[l].cnt);
}
void update(int pos, int b, int e, int kth)
{
    if(b==e){
        tree[pos].cnt = 0;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(kth<=tree[l].cnt)
        update(l,b,m,kth);
    else
        update(r,m+1,e,kth-tree[l].cnt);
    tree[pos].cnt = tree[l].cnt + tree[r].cnt;
}
void solve()
{
    build(1,1,mx-1);
    for(int i=2; i<=100000; i++){
        int x = query(1,1,mx-1,i);
        int ms = 0;
        for(int j = x; (j-ms)<=tree[1].cnt ; j+=x){
            update(1,1,mx-1,j-ms);
            ms++;
        }
    }
}
int main()
{
    solve();
    int tc,cs=1,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        printf("Case %d: %d\n",cs++,query(1,1,mx-1,n));
    }
    return 0;
}
 