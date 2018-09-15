#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll arr[mx], cum[mx];
typedef pair<int, int >pi;
map<pi, int>mp;
long long f( int A[], int n ) { // n = size of A
    long long sum = 0;
    for( int i = 0; i < n; i++ ){
        for( int j = i + 1; j < n; j++ ){
            mp[make_pair(i,j)]++;
            sum += A[i] - A[j];
        }
    }
    return sum;
}
int main()
{
//    int ar[] = {3,6,8,9,2};
//    f(ar,5);
//    map<int, pi> m;
//    auto it = mp.begin();
//    while(it!=mp.end()){
//        pi p = it->first;
//        cout<<p.first<<" - "<<p.second<<" times: "<<it->second<<endl;
//        it++;
//    }
    int tc,n,q, cs=1,c,x,v;
    ll a;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d", &n, &q);
        for(int i=0; i<n; i++){
            scanf("%lld", &arr[i]);
        }
        cum[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--){
            cum[i] = cum[i+1] + arr[i];
        }
        ll sum = 0;
        for(int i=0; i<n-1; i++){
            sum = sum + ((arr[i]*(n-i-1)) - (cum[i+1]));
        }
        printf("Case %d:\n", cs++);
        while(q--){
            scanf("%d",&c);
            if(c==1){
                printf("%lld\n", sum);
            }
            else{
                scanf("%d%d", &x, &v);
                ll val = arr[x];
                arr[x] = v;
                val = val-v;
                sum = sum + (val*(x)) - (val*(n-x-1));
            }
        }
    }

    return 0;
}
