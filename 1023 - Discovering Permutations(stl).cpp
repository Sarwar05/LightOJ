#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	int tn,n,k;
	scanf("%d",&tn);
	for(int t=1; t<=tn; t++){
		scanf("%d%d",&n,&k);
		string ara="";
		ara+= 'A';
		for(int i=1; i<n; i++) ara+=(ara[i-1]+1);
		printf("Case %d:\n",t);
		int count = 0;
		do{
			cout<<ara<<endl;
			count++;
			if(count == k) break;
		}while(next_permutation(ara.begin(),ara.end()));
	}
 	return 0;
}

