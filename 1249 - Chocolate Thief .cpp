#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,n;
    scanf("%d",&tc);
    char name[25];int a,b,c,newVol;
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        char maxName[25] = "";int maxVol;
        char minName[25] = "";int minVol;
        scanf("%s",name);
        scanf("%d%d%d",&a,&b,&c);
        strcpy(maxName,name);strcpy(minName,name);
        maxVol = minVol = a*b*c;
        for(int i=2; i<=n; i++){
            scanf("%s",name);
            scanf("%d%d%d",&a,&b,&c);
            newVol = a*b*c;
            if(newVol>maxVol){
                strcpy(maxName,name);
                maxVol = newVol;
            }
            if(newVol<minVol){
                strcpy(minName,name);
                minVol = newVol;
            }
        }
        printf("Case %d: ",t);
        if(maxVol == minVol)
            printf("no thief");
        else
            printf("%s took chocolate from %s",maxName,minName);
        printf("\n");
    }
    return 0;
}
