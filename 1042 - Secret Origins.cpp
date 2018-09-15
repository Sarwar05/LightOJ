#include<bits/stdc++.h>
using namespace std;
int bin[32];
void getBin(int num)
{
    int i=30;
    while(num!= 0){
        bin[i--] = num%2;
        num/=2;
    }
}
void makeBig()
{
    int i = 30;
    while(bin[i]!= 1) i--;
    while(bin[i]!=0) i--;
    swap(bin[i], bin[i+1]);
    bool f = false;
    int j = 30;
    i++;
    while(i<j){
        while(bin[i]!=1 && i<=30)i++;
        while(bin[j]!= 0 && j>=0) j--;
        if(i<j)
        swap(bin[i], bin[j]);
        i++, j--;
    }
}
int toDec()
{
    int ret = 0;
    int po = 0;
    for(int i=30; i>=0; i--,po++){
        ret = ret + (bin[i]*(1<<po));
    }
    return ret;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc,n;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        memset(bin, 0, sizeof bin);
        getBin(n);
        //printf("bits are: ");for(int i=0; i<=30; i++) cout<<bin[i]<<" "; cout<<endl;
        makeBig();
        //printf("after cg: ");for(int i=0; i<=30; i++) cout<<bin[i]<<" "; cout<<endl;
        printf("Case %d: %d\n",t,toDec());



    }
}
