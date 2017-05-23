/**
Key: Implementation
*/

#include<bits/stdc++.h>
using namespace std;
int ara[35][35];
int main()
{
    int tc,persons,objects,wishes,solutions;
    int len,value,a;
    scanf("%d",&tc);
    char s[5];
    for(int t=1; t<=tc; t++){
        scanf("%d%d%d%*c",&persons,&objects,&wishes);
        memset(ara,0,sizeof(ara));
        for(int i=0; i<persons; i++){
            for(int j=1; j<=wishes; j++){
                scanf("%s",s);getchar();
                len = strlen(s);
                if(len == 3) value = ( (s[1]-'0')*10 + (s[2]-'0') );
                else value = s[1]-'0';
                if(s[0]=='+'){
                    if(ara[i][value] == -1) ara[i][value] = 5;
                    else ara[i][value] = 1;
                }
                else{
                    if(ara[i][value] == 1) ara[i][value] = 5;
                    else ara[i][value] = -1;
                }

            }
        }
        int sol[objects+1];
        for(int i=1; i<=objects; i++) sol[i] = -1;
        scanf("%d",&solutions);

        for(int i=1; i<=solutions; i++){
            scanf("%d",&a);
            sol[a] = 1;
        }
        int happy[persons];for(int i=0; i<persons; i++) happy[i] = 0;
        for(int i=1; i<=objects; i++){
            for(int j=0; j<persons; j++){
                if(ara[j][i] == sol[i])
                    happy[j]++;
                else if(ara[j][i] == 5)
                    happy[j]++;
            }
        }
        int count = 0;
        for(int i=0; i<persons; i++) if(happy[i]>0) count++;
        if(count == persons)
            printf("Case %d: Yes\n",t);
        else
            printf("Case %d: No\n",t);
    }
    return 0;
}

