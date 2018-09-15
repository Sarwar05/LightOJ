#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int tree[mx*4],arr[mx],lazy[mx*4];
struct input
{
    int l;
    int r;
}in[mx];
void update(int pos, int b, int e, int i, int j)
{
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(lazy[pos]!=0){
        tree[pos] = tree[pos] + lazy[pos];
        if(b!=e){
            lazy[l]+=lazy[pos];
            lazy[r]+=lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = tree[pos] + 1;
        if(b!=e){
            lazy[l]+=1;
            lazy[r]+=1;
        }
        return;
    }
    update(l,b,m,i,j);
    update(r,m+1,e,i,j);
    tree[pos] = max(tree[l],tree[r]);
}
int main()
{
    int tc,n,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        int ind = 0;
        for(int i=0; i<n; i++){
            scanf("%d%d",&in[i].l, &in[i].r);
            arr[ind++] = in[i].l;
            arr[ind++] = in[i].r;
        }
        sort(arr,arr+ind);
        map<int, int> mp;
        int val = 0;
        for(int i=0; i<ind; i++){
            if(mp.find(arr[i])==mp.end()) mp[arr[i]] = ++val;
        }
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        for(int i=0; i<n; i++){
            update(1,1,2*n,mp[ in[i].l ], mp[ in[i].r ]);
        }
        printf("Case %d: %d\n",cs++, tree[1]);
    }
    return 0;
}