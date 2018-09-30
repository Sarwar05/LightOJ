#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct Info
{
    int val;
    int pos;
    bool operator<(const Info& ob) const
    {
        if(val==ob.val) return pos<ob.pos;
        else return val>ob.val;
    }
}arr[mx];
int in[mx], tree[mx*4], lis[mx];
void update(int pos, int b, int e, int ij, int val)
{
    if(b>e || b>ij || e<ij) return;
    if(b>=ij  && e<=ij){
        tree[pos] = val;
        return;
    }
    int l = pos*2;
    int r = l+1;
    int m = (b+e)/2;
    update(l,b,m,ij,val);
    update(r,m+1,e,ij,val);
    tree[pos]= max(tree[l], tree[r]);
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>j || e<i || b>e) return 0;
    if(b>=i  && e<=j)return tree[pos];
    int l = pos*2;
    int r = l+1;
    int m = (b+e)/2;
    return max(query(l,b,m,i,j), query(r,m+1,e,i,j));
}
int main()
{
    int tc,cs=1,n,q,m;
    scanf("%d",&tc);
    while(tc--){
        memset(tree, 0, sizeof tree);
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++){
            scanf("%d",&in[i]);
            arr[i].pos = i;
            arr[i].val = in[i];
        }
        sort(arr+1, arr+n+1);
        int max_lis = 0;
        for(int i=1; i<=n; i++){
            int put = 1 + query(1,1,n,arr[i].pos+1, n);
            lis[arr[i].pos] = put;
            update(1,1,n,arr[i].pos, put);
            max_lis = max(max_lis, put);
        }
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d",&m);
            if(m>max_lis) printf("Impossible\n");
            else{
                int prev = -1e9;
                for(int id = 1; id<=n && m;id++){
                    if(lis[id] >= m && in[id]>prev){
                        prev = in[id];
                        printf("%d", in[id]);
                        m--;
                        if(m>0) printf(" ");
                        else printf("\n");
                    }
                }
            }
        }
    }
}
