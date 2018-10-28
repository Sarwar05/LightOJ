#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc,cs=1,n,m,k;
	double p;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d%d%lf",&n,&m,&k,&p);
		printf("Case %d: %.8f\n", cs++, n*k*p);
	}
}