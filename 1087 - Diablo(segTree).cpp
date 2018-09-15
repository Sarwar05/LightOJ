#include<bits/stdc++.h>
using namespace std;
#define mx2 150005
int arr[mx2];
struct node
{
    int val;
    int cnt;
}tree[mx2*4];
void build(int pos, int b, int e)
{
    if(b>e) return;
    if(b==e){
        if(arr[b]==-1){
            tree[pos].cnt= 0;
            return;
        }
        //cout<<"put: "<<arr[b]<<" at "<<pos<<endl;
        tree[pos].val = arr[b];
        tree[pos].cnt = 1;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    build(l,b,m);
    build(r,m+1,e);
    tree[pos].cnt = tree[l].cnt  + tree[r].cnt;
}
void update(int pos, int b, int e, int i, int j, int add)
{
    //cout<<pos<<" query: "<<b<<" "<<e<<" "<<add<<endl;
    if(b>e || b>j || e<i) return;
    if(b>=i && e<=j){
        //cout<<"ij: "<<i<<" "<<j<<endl;
        tree[pos].val = add;
        tree[pos].cnt = 1;
        //cout<<"ret: "<<tree[pos].val<<" "<<tree[pos].cnt<<endl;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,j,add);
    update(r,m+1,e,i,j,add);
    //cout<<pos<<" -> "<<tree[l].cnt<<" "<<tree[r].cnt<<endl;
    tree[pos].cnt = tree[l].cnt  + tree[r].cnt;
}
int query(int pos, int b, int e,int kth)
{
 
     if(b==e){
        //cout<<tree[pos].val<<" make zwro at: "<<pos<<endl;
        tree[pos].cnt = 0;
        return tree[pos].val;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    int ret;
    if(kth<=tree[l].cnt){
        ret = query(l,b,m,kth);
    }
    else{
        ret = query(r,m+1,e,kth-tree[l].cnt);
    }
    tree[pos].cnt = tree[l].cnt  + tree[r].cnt;
    return ret;
}
int main()
{
    int tc,n,q,a,cs=1;
    char ch;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&q);
        memset(arr,-1,sizeof arr);
        for(int i=1; i<=n; i++)
            scanf("%d",&arr[i]);
        build(1,1,150000);
        //cout<<"buildok"<<endl;
        printf("Case %d:\n",cs++);
        int id = n;
        while(q--){
            scanf("%*c%c",&ch);
            scanf("%d",&a);
            //cout<<"tree1: "<<tree[1].cnt<<endl;
            if(ch=='a'){
                ++id;
                update(1,1,150000,id,id,a);
            }
            else{
                if(tree[1].cnt<a) printf("none\n");
                else printf("%d\n",query(1,1,150000,a));
            }
        }
    }
    return 0;
}