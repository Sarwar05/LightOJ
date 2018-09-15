#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define mx 5000003
int phi[mx];
ll score[mx]={0};
void phiInRange()
{

    for(int i=1; i<mx; i++) phi[i] = i, score[i] = 1;
    score[1]=0;
    for(int i=2; i<mx;  i++){
        if(phi[i]==i){
            for(int j = i; j<mx; j+=i)
                phi[j] -= phi[j]/i;
        }
        score[i] *=phi[i];
        score[i] *=phi[i];
        score[i]+=score[i-1];
    }
}
int main()
{
    //freopen("out.txt","w", stdout);
    phiInRange();
    int tc, a, b;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d%d",&a, &b);
        printf("Case %d: %llu\n", t, score[b]-score[a-1]);
    }
    return 0;
}
