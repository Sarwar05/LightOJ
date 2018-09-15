#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define mod 1000000007
int arr[mx],tree[mx*4],ar[mx];
void update(int pos, int b ,int e, int i, int j, int val)
{
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] = (tree[pos]+val)%mod;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,val);
    update(r,m+1,e,i,j,val);
    tree[pos] = (tree[l] + tree[r])%mod;
}
int query(int pos, int b ,int e, int i, int j)
{
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    int r1 = query(l,b,m,i,j);
    int r2 = query(r,m+1,e,i,j);
    return (r1 + r2)%mod;
}
int main()
{
    int tc,cs=1,n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&ar[i]);
            arr[i+1] = ar[i];
        }
        sort(ar, ar+n);
        map<int, int> mp;
        int val = 0;
        for(int i=0; i<n; i++){
            if(mp.find(ar[i])==mp.end())
                mp[ar[i]] = ++val;
        }
        for(int i=1; i<=n; i++)
            arr[i] = mp[arr[i]];
        memset(tree,0,sizeof tree);
        int ans = 0;
        for(int i=1; i<=n; i++){
            int add = query(1,1,n,1,arr[i]-1);
            ans = (ans+add+1)%mod;
            update(1,1,n,arr[i],arr[i],add+1);
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
