#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int , int>
#define fast ios_base::sync_with_stdio(0)
#define mod 1000000007
#define mx 1002
int BIT[mx][mx], mat[mx][mx];
void update(int x, int y)
{
    mat[x][y] = 1;
    for( x; x<mx; x+=(x&-x)){
        for(int j = y; j<mx; j+=(j&-j))
            BIT[x][j]++;
    }
}
int query(int x, int y)
{
    int ans = 0;
    for( ; x; x-=(x&-x)){
        for(int j = y; j ; j-=(j&-j))
            ans+=BIT[x][j];
    }
    return ans;
}
int query(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
}
int main()
{
    int tc, cs=1;
    scanf("%d", &tc);
    int q, typ, x1, y1, x2, y2, x, y;
    while(tc--){
        printf("Case %d:\n", cs++);
        memset(BIT, 0, sizeof BIT);
        memset(mat, 0, sizeof mat);
        scanf("%d", &q);
        while(q--){
        scanf("%d", &typ);
        if(typ==0){
            scanf("%d%d",&x,&y);
            x++;y++;
            if(mat[x][y]==0)
                update(x,y);
        }
        else{
            scanf("%d%d%d%d", &x1,&y1, &x2, &y2);
            x1++; x2++; y1++; y2++;
            printf("%d\n", query(x1, y1, x2, y2));
        }
        }
    }
}
