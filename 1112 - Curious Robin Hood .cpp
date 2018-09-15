#include<bits/stdc++.h>
using namespace std;
int ara[100005];
int tree[4*100005];
int x;
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
    tree[at] = tree[left] + tree[right];
}
int query(int at,int begin,int end,int i, int j)
{
    if(i>end || j<begin) return 0;
    if(begin>=i && end<=j) return tree[at];
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    int p1 = query(left,begin,mid,i,j);
    int p2 = query(right,mid+1,end,i,j);
    return p1+p2;
}
void update(int at, int begin,int end,int i, int value)
{
    if(i<begin || i>end) return;
    if(begin>=i && end<=i){
        x = tree[at];
        if(value == 0)
            tree[at] = 0;
        else
            tree[at] += value;
        return;
    }
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    update(left,begin,mid,i,value);
    update(right,mid+1,end,i,value);
    tree[at] = tree[left] + tree[right];
}

int main()
{
    int tc,n,q,c,i,j,v;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)
            scanf("%d",&ara[i+1]);
        build(1,1,n);
        printf("Case %d:\n",t);
        while(q--){
            scanf("%d",&c);
            if(c == 1){
                scanf("%d",&i);
                i++;
                update(1,1,n,i,0);
                printf("%d\n",x);
            }
            else if(c == 2){
                scanf("%d%d",&i,&v);
                i++;
                update(1,1,n,i,v);
            }
            else{
                scanf("%d%d",&i,&j);
                i++;j++;
                printf("%d\n",query(1,1,n,i,j));
            }
        }
    }
    return 0;
}
/*

1
5 6
3 2 1 4 5
1 4
2 3 4
3 0 3
1 2
3 0 4
1 1

*/
