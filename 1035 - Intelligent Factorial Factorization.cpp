#include<bits/stdc++.h>
using namespace std;
const int sz = 102;
int ara[sz][sz] = {0};
void generate()
{
    for(int i=2; i<sz; i++){
        int a = i;
        while(a!= 0 && a%2==0 ){
            a/=2;
            ara[i][2]++;
        }
        for(int j=3; j<sz; j+=2){
            while(a!= 0 && a%j==0 ){
            a/=j;
            ara[i][j]++;
            }
        }
    }
}
int main()
{
    generate();
    //freopen("out.txt","w",stdout);
    int tc,n;scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%d",&n);
        vector<int> a,b;
        for(int j=2; j<=n; j++){
            int counter = 0;
            for(int k=2; k<=n; k++){
                counter+=ara[k][j];
            }
            if(counter >0){
                a.push_back(j);
                b.push_back(counter);
            }
        }
        int len = a.size();
        printf("Case %d: %d = ",t,n);
        for(int i=0; i<len; i++){
            printf("%d (%d)",a[i],b[i]);
            if(i == len-1)
                printf("\n");
            else
                printf(" * ");
        }
 
    }
 
    return 0;
}