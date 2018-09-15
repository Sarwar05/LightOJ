#include <bits/stdc++.h>
using namespace std;
int arr[202];
int main()
{
	int tc,cs=1,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		n*=2;
		for(int i=1; i<=n; i++){
			scanf("%d",&arr[i]);
		}
		int xxx = 0;
		for(int i=2; i<=n; i+=2){
			int x = (arr[i]-arr[i-1]-1);
			xxx^=x;
		}
		printf("Case %d: %s\n",cs++,(xxx)?"Alice":"Bob");
	}
	return 0;
}
