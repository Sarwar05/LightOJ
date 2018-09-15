#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int table[mx][17],weight[mx];
int main()
{
    int tc,cs=1,n,node,val,q;
    scanf("%d",&tc);
    while(tc--){
        memset(table,-1,sizeof table);
        scanf("%d%d",&n,&q);
        weight[0] = 1;
        for(int i=1; i<n; i++){
            scanf("%d%d",&table[i][0],&weight[i]);
        }
        for(int j=1; j<=16; j++){
            for(int i=0; i<n; i++){
                if(table[i][j-1]!=-1){
                    table[i][j] = table[ table[i][j-1] ][j-1];
                }
            }
        }
        printf("Case %d:\n",cs++);
        while(q--){
            scanf("%d%d",&node,&val);
            for(int i=16; i>=0; i--){
                if(table[node][i]!=-1 && weight[ table[node][i] ]>=val){
                    node = table[node][i];
                }
            }
            printf("%d\n",node);
        }
    }
    return 0;
}
