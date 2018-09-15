int main()
{
          int mx = 1000001;
        double ara[10001];double d;
        ara[0] = log10(1);ara[1] =log10(1);
        d = ara[1];
        for(int i=2; i<mx; i++){
            d = d + log10(i);
            if(i%100 == 0)
                ara[i/100] = d;
        }
        int n,base, ans;
        int tc;cin>>tc;
        for(int t=1; t<=tc; t++){
            cin>>n>>base;
            d = ara[n/100];
            int x = (n/100)*100;
            for(int i=x+1; i<=n; i++){
                d+=log10(i);
            }
            ans = (int)floor(d/log10(base))+1;
            if(n == 1)
                ans = 0;
            printf("Case %d: %d\n",t,ans);
        }
    return 0;
}