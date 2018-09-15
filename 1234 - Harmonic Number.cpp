#include<bits/stdc++.h>
using namespace std;
long double ara[100001];
int main()
{
 	ara[0] = 0.0;
 	long double prev = 0.0;
	 for(int i=1; i<=100000000; i++){
 		prev = prev + (1.0/(double)i);
 		if(i%1000 == 0)
            ara[i/1000] = prev;
	 }
	 int tc; long int n;
	 cin>>tc;
	 for(int t=1; t<=tc; t++){
	 	cin>>n;
	 	long double ans = ara[n/1000];
	 	int x = (n/1000)*1000;
	 	for(int  i= x+1 ; i<=n; i++){
	 		ans+=(1.0/(double)i);
		 }
		 printf("Case %d: ",t);
		 cout<<fixed<<setprecision(10)<<ans<<endl;
	 }
 	return 0;
}

