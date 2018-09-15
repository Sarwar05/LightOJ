#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int arr[mx];
struct Node
{
    int ans=0;
    int lval=0;
    int locc=0;
    int rval=0;
    int rocc=0;
}tree[mx*4];
Node Merge(Node n1, Node n2)
{
    Node ret;
    if(n1.lval==n2.rval && n1.lval!=0){
        ret.ans = n1.locc + n2.rocc;
        ret.lval = n1.lval;
        ret.locc = n1.locc + n2.rocc;
        ret.rval = n2.rval;
        ret.rocc = n1.locc + n2.rocc;
    }
    else if(n1.lval==n2.lval && n1.lval!=0){
        ret.ans = n1.locc + n2.locc;
        ret.lval = n1.lval;
        ret.locc = n1.locc + n2.locc;
        ret.rval = n2.rval;
        ret.rocc =  n2.rocc;
    }
    else if(n1.rval==n2.rval&& n1.rval!=0){
        ret.ans = n1.rocc + n2.rocc;
        ret.lval = n1.lval;
        ret.locc = n1.locc;
        ret.rval = n2.rval;
        ret.rocc = n1.rocc + n2.rocc;
    }
    else{
        ret.ans = max(n1.ans , n2.ans);
        if(n1.rval==n2.lval && n1.rval!=0) ret.ans = max(ret.ans, n1.rocc + n2.locc);
        ret.lval = n1.lval;
        ret.locc = n1.locc;
        ret.rval = n2.rval;
        ret.rocc = n2.rocc;
    }
    return ret;
}
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        tree[pos]. ans=1;
        tree[pos]. lval=arr[b];
        tree[pos]. locc=1;
        tree[pos]. rval=arr[b];
        tree[pos]. rocc=1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r, m+1,e);
    tree[pos] = Merge(tree[l], tree[r]);
}
Node query(int pos, int b, int e, int i, int j)
{
    if(b>e || b>j || e<i) return tree[0];
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    Node xx1 = query(l,b,m,i,j);
    Node xx2 = query(r, m+1,e,i,j);
    return Merge(xx1, xx2);
}
int main()
{
    int tc,cs=1,n,q,a,b,c;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&c,&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        for(int i=1; i<=4*n; i++)
            tree[i] = tree[0];
        build(1,1,n);
        printf("Case %d:\n", cs++);
        while(q--){
            scanf("%d%d",&a,&b);
            Node nn = query(1,1,n,a,b);
            printf("%d\n",nn.ans);
        }
    }
}
 