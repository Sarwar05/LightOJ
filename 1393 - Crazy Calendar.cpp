#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,r,c,cs=1;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&r,&c);
        int arr[r][c];
        memset(arr,0,sizeof arr);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                scanf("%d",&arr[i][j]);
            }
        }
        int xxx=0;
        for(int i=r-1; i>=0; i-=2){
            for(int j=c-2; j>=0; j-=2){
                xxx^=arr[i][j];
            }
        }
        for(int i=r-2; i>=0; i-=2){
            for(int j=c-1; j>=0; j-=2){
                xxx^=arr[i][j];
            }
        }
        printf("Case %d: %s\n",cs++,(xxx)?"win":"lose");
    }
    return 0;
}
