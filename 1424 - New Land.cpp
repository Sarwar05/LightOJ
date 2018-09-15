#include<bits/stdc++.h>
using namespace std;
#define mx 2002
int arr[mx],table[mx][12];
char str[mx];
void build(int n)
{
    for(int i=1; i<=n; i++) table[i][0] = i;
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i + (1<<j) -1 <=n; i++ ){
            if( arr[table[i][j-1]] <  arr[table[ i+(1<<(j-1)) ][j-1]]){
                table[i][j] = table[i][j-1];
            }
            else{
                table[i][j] = table[ i+(1<<(j-1)) ][j-1];
            }
        }
    }
}
int query(int b, int e)
{
    int l = (e-b+1);
    int k = log2(l);
    if( arr[table[b][k]] <  arr[table[ b+l-(1<<k)][k]]){
        return table[b][k];
    }
    else{
        return table[ b+l-(1<<k)][k];
    }
}
int solve(int b, int e, int m)
{
    if(b>e) return 0;
    if(b==e) return arr[b];
    else{
        int idx = query(b,e);
        int h = arr[idx];
        int r1 = (e-b+1)*h;
        int r2 = solve(b,idx-1,m);
        int r3 = solve(idx+1,e,m);
        return max(r1,max(r2,r3));
    }
}
int histogram(int m)
{
    build(m);
    return solve(1,m,m);
}
int main()
{
    int tc,n,m,cs=1,a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&m);
        memset(arr,0,sizeof arr);
        int ans = 0;
        for(int i=1; i<=n; i++){
            scanf("%s",str);
            for(int j=0; j<m; j++){
                a = str[j]-'0';
                a = (a==0) ? 1 : 0;
                if(a==0) arr[j+1] = 0;
                else arr[j+1] += a;
            }
            ans = max(ans,histogram(m));
        }
        printf("Case %d: %d\n",cs++, ans);
    }
    return 0;
}