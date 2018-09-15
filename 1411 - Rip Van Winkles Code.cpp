#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    ll sum = 0;
    int a = 0;
    ll pa = 0;
    int b = 0;
    ll pb = 0;
    bool c = false;
    int x = 0;
};
Node tree[250002*4];
void propagate(int pos, int b, int e, int i, int j)
{
    int l = pos*2;
    int r = l+1;
    int m = (b+e)/2;
    if(tree[pos].c){
        tree[pos].sum = (e-b+1)*1LL*tree[pos].x;
        if(b!=e){
            tree[l].c = true;
            tree[l].x = tree[r].x = tree[pos].x;
            tree[l].a = tree[l].b = tree[l].pa = tree[l].pb = 0;
            tree[r].c = true;
            tree[r].a = tree[r].b = tree[r].pa = tree[r].pb = 0;
        }
        tree[pos].c = false;
    }
    if(tree[pos].a){
        ll k = e-b+1;
        ll xxx = (k*(k+1))/2;
        tree[pos].sum += (k*tree[pos].pa + tree[pos].a*xxx);
        if(b!=e){
            tree[l].a+=tree[pos].a;
            tree[l].pa+=tree[pos].pa;
            ll calc = (m+1-b);
            calc = tree[pos].pa + calc*tree[pos].a;
            tree[r].a+=tree[pos].a;
            tree[r].pa+=calc;
        }
        tree[pos].a =  tree[pos].pa = 0;
    }
    if(tree[pos].b){
        ll k = e-b+1;
        ll xxx = (k*(k+1))/2;
        tree[pos].sum += (k*tree[pos].pb + tree[pos].b*xxx);
        if(b!=e){
            tree[r].b+=tree[pos].b;
            tree[r].pb+=tree[pos].pb;
            ll calc = (e-m);
            calc = tree[pos].pb + calc*tree[pos].b;
            tree[l].b+=tree[pos].b;
            tree[l].pb+=calc;
        }
        tree[pos].b =  tree[pos].pb = 0;
    }
}
void updateA(int pos, int b, int e, int i, int j)
{
    int l = pos*2;
    int r = l+1;
    int m = (b+e)/2;
    propagate(pos,b,e,i,j);
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        ll k = e-b+1;
        ll xxx = (k*(k+1))/2;
        tree[pos].sum += ( xxx + k*(b-i));
        if(b!=e){
            tree[l].a++;
            tree[l].pa+=(b-i);
            tree[r].a++;
            tree[r].pa+=( m+1-i );
        }
        return;
    }
    updateA(l,b,m,i,j);
    updateA(r,m+1,e,i,j);
    tree[pos].sum = tree[l].sum + tree[r].sum;
}
void updateB(int pos, int b, int e, int i, int j)
{
    int l = pos*2;
    int r = l+1;
    int m = (b+e)/2;
    propagate(pos,b,e,i,j);
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        ll k = e-b+1;
        ll xxx = (k*(k+1))/2;
        tree[pos].sum+=( xxx + k*(j-e));
        if(b!=e){
            tree[r].b++;
            tree[r].pb+=(j-e);
            tree[l].b++;
            tree[l].pb+=( j-m );
        }
        return;
    }
    updateB(l,b,m,i,j);
    updateB(r,m+1,e,i,j);
    tree[pos].sum = tree[l].sum + tree[r].sum;
}
void updateC(int pos, int b, int e, int i, int j, int x)
{
    int l = pos*2;
    int r = l+1;
    int m = (b+e)/2;
    propagate(pos,b,e,i,j);
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        ll k = e-b+1;
        tree[pos].sum = x*k;
        if(b!=e){
            tree[l].c = true;
            tree[l].x = x;
            tree[l].a = tree[l].b = tree[l].pa = tree[l].pb = 0;
            tree[r].c = true;
            tree[r].x = x;
            tree[r].a = tree[r].b = tree[r].pa = tree[r].pb = 0;
        }
        return;
    }
    updateC(l,b,m,i,j,x);
    updateC(r,m+1,e,i,j,x);
    tree[pos].sum = tree[l].sum + tree[r].sum;
}
ll query(int pos, int b, int e, int i, int j)
{
    int l = pos*2;
    int r = l+1;
    int m = (b+e)/2;
    propagate(pos,b,e,i,j);
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos].sum;
    }
    return (query(l,b,m,i,j) + query(r,m+1,e,i,j));
}
int main()
{
    int tc,cs=1,n,a,b,c,x;
    char ch;
    scanf("%d",&tc);
    while(tc--){
        printf("Case %d:\n",cs++);
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            getchar();
            scanf("%c",&ch);
            if(ch=='A'){
                scanf("%d%d",&a,&b);
                updateA(1,1,250000,a,b);
            }
            else if(ch == 'B'){
                scanf("%d%d",&a,&b);
                updateB(1,1,250000,a,b);
            }
            else if(ch=='S'){
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(1,1,250000,a,b));
            }
            else{
                scanf("%d%d%d",&a,&b,&x);
                updateC(1,1,250000,a,b,x);
            }
        }
        if(tc>0){
            for(int i=1; i<(250002*4); i++)
                tree[i] = tree[0];
        }
    }
}

