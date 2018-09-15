#include<bits/stdc++.h>
using namespace std;
#define mx 50005
struct point
{
    int l;
    int r;
}p[mx];
int tree [mx*12],lazy[mx*12],query[mx],arr[mx*3];
void update(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos] = tree[pos] + (e-b+1)*lazy[pos];
        if(b!=e){
            lazy[l]+=lazy[pos];
            lazy[r]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = tree[pos] + (e-b+1);
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
int qquery(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos] = tree[pos] + (e-b+1)*lazy[pos];
        if(b!=e){
            lazy[l]+=lazy[pos];
            lazy[r]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int r1 = qquery(l,b,m,i,j);
    int r2 = qquery(r,m+1,e,i,j);
    return (r1+ r2);
}
int main()
{
    int tc,cs=1,n,q,a,b;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&q);
        map<int, int> mp;
        int val = 0,j=0;
        for(int i=1; i<=n; i++){
            scanf("%d%d",&a,&b);
            arr[j++]=a;
            arr[j++]=b;
            p[i].l = a;
            p[i].r = b;
        }
        for(int i=1; i<=q; i++){
            scanf("%d",&a);
            query[i] = a;
            arr[j++] = a;
        }
        sort(arr,arr+j);
        for(int i=0; i<j; i++){
            if(mp.find(arr[i])==mp.end())
                mp[ arr[i] ] = ++val;
        }
        int rang = val*4;
        for(int i=1; i<=rang; i++){
            lazy[i] = tree[i] = 0;
        }
        for(int i=1; i<=n; i++){
            update(1,1,val,mp[p[i].l],mp[p[i].r]);
        }
        printf("Case %d:\n",cs++);
        for(int i=1; i<=q; i++){
            a = mp[ query[i] ];
            printf("%d\n",qquery(1,1,val,a,a));
        }
    }
    return 0;
}