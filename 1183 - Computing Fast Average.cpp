#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int tree[mx*4], lazy[mx*4];
void update(int pos, int b, int e, int i, int j, int val)
{
    if(b>e) return;
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left  + 1;
    if(lazy[pos]!= -1){
        tree[pos] = lazy[pos]*(e-b+1);
        if(b!=e){
            lazy[left] = lazy[pos];
            lazy[right] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(b>j || e<i) return;
    if(b>=i && e<=j){
        tree[pos] =  (e-b+1)*val;
        if(b!= e){
            lazy[left] = val;
            lazy[right] = val;
        }
        return;
    }
    update(left, b, mid, i, j, val);
    update(right, mid+1, e, i, j, val);
    tree[pos] = tree[left] + tree[right];
}
int query(int pos, int b, int e, int i, int j)
{
    if(b>e) return 0;
    int mid = (b+e)/2;
    int left = pos*2;
    int right = left  + 1;
    if(lazy[pos]!= -1){
        tree[pos] = lazy[pos]*(e-b+1);
        if(b!=e){
            lazy[left] = lazy[pos];
            lazy[right] = lazy[pos];
        }
        lazy[pos] = -1;
    }
    if(b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int q1 = query(left, b, mid, i, j);
    int q2 = query(right, mid+1, e, i, j);
    return q1 + q2;
}
int main()
{
    int tc,n,q,a,b,v, cs=1, c;
    scanf("%d", &tc);
    while(tc--){
        memset(tree, 0, sizeof tree);
        memset(lazy, -1, sizeof lazy);
        printf("Case %d:\n", cs++);
        scanf("%d%d", &n, &q);
        while(q--){
            scanf("%d", &c);
            if(c==1){
                scanf("%d%d%d", &a, &b, &v);
                update(1,1,n,a+1, b+1, v);
            }
            else{
                scanf("%d%d", &a, &b);
                int sum = query(1,1,n,a+1, b+1);
                int elem = b-a+1;
                int gc = __gcd(sum, elem);
                //cout<<"sum elem gc "<<sum<<" "<<elem<<" "<<gc<<endl;
                if(elem/gc == 1){
                    printf("%d\n", sum/gc);
                }
                else{
                    printf("%d/%d\n", sum/gc, elem/gc);
                }
            }
        }
    }
    return 0;
}
