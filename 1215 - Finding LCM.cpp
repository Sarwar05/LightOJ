#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> prime;
bitset<1000007>bs;
void sieve()
{
	bs[0] = bs[1] = 1;
	for(ll i=2; i<=1000000; i++){
		if(!bs[i]){
			prime.push_back(i);
			for(ll j = i*i; j<=1000000; j+=i)
				bs[j] = 1;
		}
	}
}
ll pow(ll b, ll p)
{
	if(p==0) return 1;
	ll x = pow(b,p/2);
	x*=x;
	if(p%2==1) x*=b;
	return x;
}
map<ll, int> get(ll a, ll b)
{
	map<ll, int> ret;
	int id = 0;
	ll pf = prime[id];
	while(pf*pf <= a){
		if(a%pf==0){
			int po = 0;
			while(a%pf==0){
				po++;
				a/=pf;
			}
			ret[pf] = max(ret[pf], po);
		}
		pf = prime[++id];
	}
	if(a>1) ret[a] = max(ret[a],1);
	if(b==0) return ret;
	id = 0;
	pf = prime[id];
	a = b;
	while(pf*pf <= a){
		if(a%pf==0){
			int po = 0;
			while(a%pf==0){
				po++;
				a/=pf;
			}
			ret[pf] = max(ret[pf], po);
		}
		pf = prime[++id];
	}
	if(a>1) ret[a] = max(ret[a],1);
	return ret;
}
int main()
{
	sieve();
    int tc, cs=1;
    scanf("%d",&tc);
    ll a,b,c,L;
    while(tc--){
    	scanf("%lld%lld%lld",&a,&b,&L);
    	printf("Case %d: ",cs++ );
    	map<ll, int> map1 = get(a,b);
    	map<ll, int> map2 = get(L,0);
    	map<ll, int> :: iterator it = map1.begin();
    	int ok = 1;
    	c = 1;
    	while(it!=map1.end()){
    		int pf = it->first;
    		int po1 = it->second;
    		int po2 = map2[pf];
    		if(po1>po2){
    			ok = 0;
    			break;
    		}
    		if(po1!=po2)c*=pow(pf,po2);
    		map2.erase(pf);
    		it++;
    	}
    	map<ll, int> :: iterator it2 = map2.begin();
    	while(it2!=map2.end() && ok){
    		c*=pow( it2->first,it2->second);
    		it2++;
    	}
    	if(ok==0) printf("impossible\n");
    	else printf("%lld\n",c);
    }
}
