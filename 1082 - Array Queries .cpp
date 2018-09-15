#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int tree[4*100005];
void build(int at, int begin,int end)
{
    if(begin == end){
        tree[at] = ara[begin];
        return;
    }
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    build(left,begin,mid);
    build(right,mid+1,end);
    tree[at] = min(tree[left] , tree[right]);
}
int query(int at,int begin,int end,int i, int j)
{
    if(i>end || j<begin) return INT_MAX;
    if(begin>=i && end<=j) return tree[at];
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    int p1 = query(left,begin,mid,i,j);
    int p2 = query(right,mid+1,end,i,j);
    return min(p1,p2);
}

int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n,q,i,j;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)
            scanf("%d",&ara[i+1]);
        build(1,1,n);
        printf("Case %d:\n",t);
        while(q--){
            scanf("%d%d",&i,&j);
            printf("%d\n",query(1,1,n,i,j));
        }
    }
    return 0;
}
