#include<iostream>
using namespace std;
long long int ara[10001][6]={0};
int m = 10000007;
void generate()
{
    for(int i=0; i<6; i++)
        ara[i][i] = 1;
    for(int i=6; i<10001; i++){
        for(int j=i-1; j>=i-6; j--){
            for(int k=0; k<6; k++)
                ara[i][k] = (ara[i][k]+ara[j][k])%m;
        }
    }
}
int main()
{
    generate();
 
    int a[6];int n;
    int tc;cin>>tc;
    for(int t=1; t<=tc; t++){
        cout<<"Case "<<t<<": ";
        cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>n;
        int ans = 0;
        for(int j=0; j<6; j++)
            ans = (ans +((a[j]%m)*ara[n][j])%m )%m;
        cout<<ans<<endl;
    }
 
    return 0;
}
 