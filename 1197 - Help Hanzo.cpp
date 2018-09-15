#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ara[65536] = {0};
vector<int> prime;
void sieve()
{
    for(int i=3; i<256; i+=2){
        if(ara[i]==0){
            for(int j=i*i; j<65536; j+=i){
                ara[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for(int i=3; i<65536; i+=2){
        if(ara[i]==0)
            prime.push_back(i);
    }
}
int segSieve(int a, int b)
{
    int ret = 0 ;
    if(a==2){
        ret++;
        a = 3;
    }
    else if(a<3 && b>3){
        ret++;
        a = 3;
    }
    else if(a<2) a = 3;
    else if(b==2){
         ret++;
    }
    if(b-a+1<=0) return ret;
    vector<int> seg(b-a+1, 0);
    int mx = sqrt(b);
    for(ll i=0; prime[i]<=mx; i++){
        int x = a/prime[i];
        if(x<2) x = 2;
        for(ll j=x; j*prime[i]<=b; j++){
            if(j*prime[i]>=a){
                seg.at(j*prime[i] - a) = 1;
            }
        }
    }
    for(int i=0; i<seg.size(); i++){
        if(seg[i]==0)
            ret++;
    }
    return ret;
}
int main()
{
    int a,b,tc;
    sieve();
    scanf("%d",&tc);
    for(int t=1; t<=tc ;t++){
        scanf("%d%d",&a,&b);
        printf("Case %d: %d\n",t, segSieve(a,b));
    }
    return 0;
}

