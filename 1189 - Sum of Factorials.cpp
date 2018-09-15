#include<cstdio>
#include<vector>
int main()
{
    long long int s[21];
    s[0] = 1;
    for(int i=1; i<=20; i++) s[i] = s[i-1]*i;
    int tc; scanf("%d",&tc);
    long long int num;
    for(int t=1; t<=tc; t++){
        scanf("%lld",&num);
        int len = 0;
        std::vector <int > v;int c = -1;
        for(int i=20; i>=0 && num>0; i--){
            if(s[i]<=num){
                num -=s[i];
                v.push_back(i);
                c++;
            }
        }
        printf("Case %d: ",t);
        if(num>0) printf("impossible\n");
        else{
            for(int i=c; i>0; i--)
                printf("%d!+",v[i]);
            printf("%d!\n",v[0]);
        }
    }
    return 0;
}
