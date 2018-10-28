#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000006
#define mod 1000000007
int fact[mx];
ll bigMod(ll b, ll p)
{
	if(p==0) return 1;
	ll x = bigMod(b,p/2);
	x = (x*x)%mod;
	if(p%2==1) x = (x*b)%mod;
	return x;
}
int arr[1003],sum[1003];
ll factAB(int a, int b)
{
	ll ret = fact[b];
	ret*=bigMod(fact[a-1], mod-2);
	return ret%mod;;
}
int main()
{
	fact[0]=1;
	for(ll i=1; i<=1000000; i++) fact[i] = (fact[i-1]*i)%mod;
	int n,tc,cs=1;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		sum[0] = 0;
		arr[0] = 0;
		for(int i=1; i<=n; i++){
			scanf("%d",&arr[i]);
			sum[i]=arr[i] + sum[i-1];
		}
		ll ans = 1;
		for(int i=1; i<=n; i++){
			int a = sum[i-1]+1;
			int b = sum[i]-1;
			ans*=factAB(a,b);
			ans%=mod;
			ans*=bigMod(fact[arr[i]-1], mod-2);
			ans%=mod;
		}
		printf("Case %d: %lld\n",cs++,ans);
	}
}
