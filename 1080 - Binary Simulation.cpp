#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int ara[mx];
struct info
{
    int value;
    int prop;
}tree[4*mx];
void build(int at, int begin,int end)
{
    if(begin == end){
        tree[at].value = ara[begin];
        tree[at].prop = 0;
        return;
    }
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    build(left,begin,mid);
    build(right,mid+1,end);
    tree[at].value = tree[left].value + tree[right].value;
    tree[at].prop = 0;
}
int query(int at,int begin,int end,int i)
{
    if(begin>=i && end<=i){
        int x = tree[at].value;/// modify
        if(tree[at].prop %2 ==1)
            x = (x == 0) ? 1:0;
        return x;
    }
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    int p1;
    if(i<=mid)
        p1 = query(left,begin,mid,i);
    else
        p1 = query(right,mid+1,end,i);
    if(tree[at].prop %2 ==1)
        p1 = (p1 == 0) ? 1:0;
    return p1;
}
void update(int at, int begin,int end,int i,int j)
{
    if(j<begin || i>end) return;// index is out of range
    if(begin>=i && end<=j){// total overlap
        tree[at].prop++;
        return;
    }
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    update(left,begin,mid,i,j);
    update(right,mid+1,end,i,j);
}
int main()
{
    int tc,q,i,j;
    scanf("%d",&tc);getchar();
    char c;
    for(int t=1; t<=tc; t++){
        int n=0;
        while(c = getchar()){
            if(c == '0')
                ara[++n] = 0;
            else if(c == '1')
                ara[++n] = 1;
            else
                break;
        }
        build(1,1,n);
        printf("Case %d:\n",t);
        scanf("%d",&q);getchar();
        while(q--){
            c = getchar();
            if(c == 'I'){
                scanf("%d%d",&i,&j);
                update(1,1,n,i,j);
            }
            else{
                scanf("%d",&i);
                printf("%d\n",query(1,1,n,i));
            }
            getchar();
        }
    }
    return 0;
}
