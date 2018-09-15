#include<bits/stdc++.h>
using namespace std;
#define mx 102
int arr[mx] = {0};
vector<int> p;
void sieve()
{
    p.push_back(2);
    for(int i=4; i<mx; i+=2) arr[i] = 1;
    for(int i=3; i<mx; i+=2){
        if(arr[i] == 0){
            p.push_back(i);
            for(int j=i*i; j<mx; j+= i+i)
                arr[j] = 1;
        }
    }
    p.push_back(101);
}
string multiply( string a, int b ) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }

    return a;
}
int power(int a, int p)
{
    if(p==0) return 1;
    int x = power(a, p/2);
    x = x*x;
    if(p%2==1) x = x*a;
    return x;
}
int main()
{
    sieve();
    int tc, n,a;
    scanf("%d",&tc);
    for(int cs=1; cs<=tc; cs++){
        scanf("%d",&n);
        map<int , int> mp;
        for(int j=1; j<=n; j++){
            scanf("%d",&a);
            int i=0;
            while(p[i]*p[i]<=a){
                if(a%p[i]==0){
                    int pow = 0;
                    while(a%p[i]==0){
                        pow++;
                        a/=p[i];
                    }
                    mp[p[i]] = max(mp[p[i]], pow);
                    //cout<<p[i]<<" to "<<mp[p[i]]<<endl;
                }
                i++;
            }
            if(a>1)
                mp[a] = max(mp[a], 1);
        }
        map<int, int>:: iterator it = mp.begin();
        string ans = "1";
        while(it != mp.end()){
            ans = multiply(ans, power(it->first, it->second));
            it++;
        }
        reverse(ans.begin(), ans.end());
        printf("Case %d: %s\n", cs, ans.c_str());
    }
    return 0;
}
