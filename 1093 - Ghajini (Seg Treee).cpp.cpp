#include <bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int mxtree[mx*4];
int mntree[mx*4];
inline int max(int a, int b){return a>b?a:b;}
inline int min(int a, int b){return a<b?a:b;}
void buildmx(int pos, int b, int e)
{
    if(b==e){
        mxtree[pos] = arr[b];
    }
    else{
        int l = pos*2;
        int r = l+1;
        int mid = (b+e)/2;
        buildmx(l,b,mid);
        buildmx(r, mid+1,e);
        mxtree[pos] = max(mxtree[l], mxtree[r]);
    }
}
int querymx(int pos, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return  INT_MIN;
    else if(b>=i && e<=j)
        return mxtree[pos];
    else{
        int l = pos*2;
        int r = l+1;
        int mid = (b+e)/2;
        int r1 = querymx(l,b,mid,i,j);
        int r2 = querymx(r,mid+1,e,i,j);
        return max(r1, r2);
    }
}
int querymn(int pos, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return  INT_MAX;
    else if(b>=i && e<=j)
        return mntree[pos];
    else{
        int l = pos*2;
        int r = l+1;
        int mid = (b+e)/2;
        int r1 = querymn(l,b,mid,i,j);
        int r2 = querymn(r,mid+1,e,i,j);
        return min(r1, r2);
    }
}
///
void buildmn(int pos, int b, int e)
{
    if(b==e){
        mntree[pos] = arr[b];
    }
    else{
        int l = pos*2;
        int r = l+1;
        int mid = (b+e)/2;
        buildmn(l,b,mid);
        buildmn(r,mid+1,e);
        mntree[pos] = min(mntree[l], mntree[r]);
    }
}
 
int main() {
    int n,k,tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n, &k);
        for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
        buildmn(1,1,n);
        buildmx(1,1,n);
        int ans = INT_MIN;
        for(int i=1, j=k; j<=n; i++, j++){
            ans = max(ans,querymx(1,1,n,i,j) - querymn(1,1,n,i,j));
        }
        printf("Case %d: %d\n", t,ans);
    }
    return 0;
}
/**
3
6 2
6 0 8 8 8 4
8 3
19 8 4 13 12 1 0 13
2 2
1 1
 */