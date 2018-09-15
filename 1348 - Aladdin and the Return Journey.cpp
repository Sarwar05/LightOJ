#include<bits/stdc++.h>
using namespace std;
#define mx 30004
int table[mx][16];
int par[mx];
int position[mx][2];
vector<int> adj[mx];
int arr[mx*2],Time,xxx[mx],tree[mx*8],lev[mx];
void refresh(int n)/// clear prev input
{
    memset(table,-1,sizeof table);
    memset(tree,0,sizeof tree);
    for(int i=1; i<=n; i++) adj[i].clear();
}
void init_lca(int n)/// initialize sparse table
{
    for(int i=1; i<=n; i++) table[i][0] = par[i];
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(table[i][j-1]!=-1)
                table[i][j] = table[ table[i][j-1] ][j-1];
        }
    }
}
int query_lca(int p, int q)/// return lca node
{
    if(lev[p]>lev[q])
        swap(p,q);
    int log = 15;
    for(int i=log; i>=0; i--){
        if(lev[q]-(1<<i)>=lev[p])
            q = table[q][i];
    }
    if(p==q) return q;
    for(int i=log; i>=0; i--){
        if(table[p][i]!=-1 && table[p][i]!=table[q][i]){
            p = table[p][i];
            q = table[q][i];
        }
    }
    return par[p];
}
void init_tree(int u, int p, int l)/// get start,end,level,parent
{
    position[u][0] = ++Time;
    arr[Time] = xxx[u];
    lev[u] = l;
    par[u] = p;
    for(int i=0; i<adj[u].size();i++){
        int v = adj[u][i];
        if(v==p) continue;
        init_tree(v,u,l+1);
    }
    position[u][1] = ++Time;
    arr[Time] = -xxx[u];
}
void init_seg_tree(int pos, int b, int e)/// build seg tree
{
    if(b>e) return;
    if(b==e){
        tree[pos] = arr[b];
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    init_seg_tree(l,b,m);
    init_seg_tree(r,m+1,e);
    tree[pos] = tree[l]  + tree[r];
}
void update_seg_tree(int pos, int b, int e, int i, int j, int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = val;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update_seg_tree(l,b,m,i,j,val);
    update_seg_tree(r,m+1,e,i,j,val);
    tree[pos] = tree[l]  + tree[r];
}
int query_seg_tree(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return (query_seg_tree(l,b,m,i,j) + query_seg_tree(r,m+1,e,i,j));
}
int main()
{
    int tc,cs=1,n,a,b,typ,q;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        refresh(n);
        for(int i=1; i<=n; i++) scanf("%d",&xxx[i]);
        for(int i=1; i<n; i++){
            scanf("%d%d",&a,&b);
            ++a,++b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        Time = 0;
        init_tree(1,-1,0);
        init_seg_tree(1,1,n*2);
        init_lca(n);

        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d",&typ);
            if(typ==0){
                scanf("%d%d",&a,&b);
                ++a,++b;
                int lca = query_lca(a,b);
                int ans = query_seg_tree(1,1,2*n,position[lca][0],position[a][0]);
                ans += query_seg_tree(1,1,2*n,position[lca][0],position[b][0]);
                ans-=xxx[lca];
                printf("%d\n",ans);
            }
            else{
                scanf("%d%d",&a,&b);
                ++a;
                xxx[a] = b;
                update_seg_tree(1,1,2*n,position[a][0],position[a][0],b);
                update_seg_tree(1,1,2*n,position[a][1],position[a][1],-b);
            }
        }
    }
    return 0;
}
