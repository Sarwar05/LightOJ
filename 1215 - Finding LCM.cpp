#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mx 1000005
int arr[mx] ={0};
vector<ll > prime;
void sieve();
int main()
{
    sieve();
    int tc,i, power; scanf("%d",&tc);
    ll a,b,c,l,x, ans,p,q,r;
    for(int cs=1; cs<=tc; cs++){
        ans = 1;
        scanf("%lld%lld%lld", &a, &b,&l);
        map<ll, int> lh, rh,c;
        /**** factorization starts****/
        i=0, x = a;
        while(prime[i]*prime[i]<=x){
            if(x%prime[i]==0){
                power = 0;
                while(x%prime[i]==0){
                    power++;
                    x/=prime[i];
                }
                lh[ prime[i] ] = max(lh[ prime[i] ], power);
            }
            i++;
        }
        if(x>1)
            lh[x] = max(lh[x], 1);
        i=0, x = b;
        while(prime[i]*prime[i]<=x){
            if(x%prime[i]==0){
                power = 0;
                while(x%prime[i]==0){
                    power++;
                    x/=prime[i];
                }
                lh[ prime[i] ] = max(lh[ prime[i] ], power);
            }
            i++;
        }
        if(x>1)
            lh[x] = max(lh[x], 1);
        i=0, x = l;
        while(prime[i]*prime[i]<=x){
            if(x%prime[i]==0){
                power = 0;
                while(x%prime[i]==0){
                    power++;
                    x/=prime[i];
                }
                rh[ prime[i] ] = max(rh[ prime[i] ], power);
            }
            i++;
        }
        if(x>1)
            rh[x] = max(rh[x], 1);
        /**** factorization okay ****/
        /**** calculation starts ****/
        map<ll , int> ::iterator it = lh.begin();
        bool flag = true;
        while(it!= lh.end()){
            r = it->first;
            if(rh.find(r) == rh.end()){
                flag = false;
                break;
            }
            else{
                p = it->second, q = rh[r];
                if(p<q){
                    ans = ans * pow(r, q);
                    rh[r] = -1;
                }
                else if(p>q){
                    flag = false;
                    break;
                }
                else{
                    rh[r] = -1;
                }
            }
            it++;
        }
        if(flag){
            //cout<<"res "<<ans<<endl;
            map<ll , int> ::iterator it2 = rh.begin();
            while(it2 != rh.end()){
                if(it2->second != -1){
                    //cout<<"for "<<it2->first<<" rais to  "<<it2->second<<endl;
                    ans = ans * pow(it2->first, it2->second);
                }
                it2++;
            }
        }
        /**** calculation okay ****/
        printf("Case %d: ", cs);
        if(!flag) printf("impossible\n");
        else printf("%lld\n", ans);
    }
    return 0;
}
void sieve()
{
    prime.push_back(2);
    arr[0] = arr[1] = 1;
    for(ll i=4; i<mx; i+=2 ) arr[i] = 1;
    for(ll i=3; i<mx; i+=2){
        if(arr[i]==0){
            prime.push_back(i);
            for(ll j= i*i; j<mx; j+= i+i)
                arr[j] = 1;
        }
    }
}

