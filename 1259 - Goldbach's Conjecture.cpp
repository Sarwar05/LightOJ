#include<bits/stdc++.h>
using namespace std;
#define mx 10000001
vector<int> prime;
bool arr[mx];
void sieve()
{
    for(int i=0; i<mx; i++) arr[i] = true;
    arr[0]=arr[1] = false;
    for(long long i=2; i<mx; i++){
        if(arr[i]==true){
            prime.push_back(i);
            for(long long j = i*i; j<mx; j+=i)
                arr[j] = false;
        }
    }
}
int main()
{
    sieve();
    int tc,n,a,b,ans;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%d",&n);
        int i=0;ans = 0;
        while(prime[i]<=n/2){
            if(arr[n-prime[i]]){
                ans++;
            }
            i++;
        }
        printf("Case %d: %d\n",cs, ans);
    }
    return 0;
}
