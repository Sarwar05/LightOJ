#include<bits/stdc++.h>
using namespace std;
#define mx 102
int grid[mx][mx];
int FloydWarshal(int n)
{
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > grid[i][k] + grid[k][j])
                    grid[i][j] = grid[i][k] + grid[k][j];
            }
        }
    }
    for(int k=0; k<n; k++){
        if(grid[k][k]<0) return 1;
    }
    return 0;
}
int main()
{
    int tc,cs=1,n,r,a,b,i,e,p;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&n,&r,&p);
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                grid[j][k] = 10000000;
            }
            grid[j][j] = 0;
        }
        for(int j=1; j<=r; j++){
            scanf("%d%d%d%d",&a,&b,&i,&e);
            grid[a][b] = min(grid[a][b],e*p-i);
        }
        printf("Case %d: %s\n",cs++, FloydWarshal(n) ? "YES" : "NO");
    }
    return 0;
}
