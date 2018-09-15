#include<bits/stdc++.h>
using namespace std;
#define mx 100005
struct info
{
    long long int sum;
    long long int prop;
}tree[4*mx];
void build(int at, int begin,int end)
{
    if(begin == end){

        tree[at].sum = 0;
        return;
    }
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    build(left,begin,mid);
    build(right,mid+1,end);
    tree[at].sum = tree[left].sum + tree[right].sum;
    tree[at].prop = 0;
}
long long int query(int at,int begin,int end,int i, int j,long long int carry = 0)
{
    if(i>end || j<begin) return 0;
    if(begin>=i && end<=j) return tree[at].sum + carry *(end-begin+1);
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    long long int p1 = query(left,begin,mid,i,j,carry+tree[at].prop);
    long long int p2 = query(right,mid+1,end,i,j,carry+tree[at].prop);
    return p1+p2;
}
void update(int at, int begin,int end,int i,int j, int value)
{
    if(j<begin || i>end) return;// index is out of range
    if(begin>=i && end<=j){// we found the index, so change it
        tree[at].sum += (end-begin+1)* value;
        tree[at].prop+=value;
        return;
    }
    int left = at*2;
    int right = at*2+1;
    int mid = (begin+end)/2;
    update(left,begin,mid,i,j,value);
    update(right,mid+1,end,i,j,value);
    tree[at].sum = tree[left].sum + tree[right].sum + (end-begin+1)*tree[at].prop;
}
int main()
{
    int tc,n,q,a,i,j,v;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        build(1,1,n);
        printf("Case %d:\n",t);
        scanf("%d",&q);
        while(q--){
            scanf("%d",&a);
            if(a == 1){
                scanf("%d%d",&i,&j);
                i++,j++;
                printf("%lld\n",query(1,1,n,i,j,0));
            }
            else{
                scanf("%d%d%d",&i,&j,&v);
                i++,j++;
                update(1,1,n,i,j,v);
            }
        }
    }

    return 0;
}



