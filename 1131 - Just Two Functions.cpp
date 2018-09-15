#include<bits/stdc++.h>
using namespace std;
#define dim 6
struct Matrix
{
    int val[dim][dim];
};
Matrix mp[32];
int mod;
int a1,b1,c1,a2,b2,c2;
int f0,f1,f2,g0,g1,g2;
void init(Matrix& ob)
{
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ob.val[i][j] = 0;
        }
    }
    ob.val[0][1] = ob.val[1][2] = ob.val[3][4] = ob.val[4][5] = 1;
    ob.val[2][2] = a1;  ob.val[2][1] = b1;  ob.val[2][3] = c1;
    ob.val[5][5] = a2;  ob.val[5][4] = b2;  ob.val[5][0] = c2;
}
Matrix multiply(const Matrix x,const Matrix y)
{
    Matrix xy;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            xy.val[i][j] = 0;
            for(int k=0; k<dim; k++){
                xy.val[i][j] = (xy.val[i][j] + (x.val[i][k] * y.val[k][j])%mod)%mod;
            }
        }
    }
    return xy;
}
void process()
{
    init(mp[0]);
    for(int i=1; i<=30; i++){
        mp[i] = multiply(mp[i-1], mp[i-1]);
    }
}
Matrix identity()
{
    Matrix ret;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++)
            ret.val[i][j] = (i==j);
    }
    return ret;
}
void solve()
{
    int n;
    scanf("%d",&n);
    Matrix res = identity();
    for(int i=30; i>=0; i--){
        if(n>=(1<<i)){
            n-=(1<<i);
            res = multiply(res, mp[i]);
        }
    }
    int ans1=0,ans2=0;
    ans1 = (ans1 + (res.val[0][0]*f0)%mod)%mod;
    ans1 = (ans1 + (res.val[0][1]*f1)%mod)%mod;
    ans1 = (ans1 + (res.val[0][2]*f2)%mod)%mod;
    ans1 = (ans1 + (res.val[0][3]*g0)%mod)%mod;
    ans1 = (ans1 + (res.val[0][4]*g1)%mod)%mod;
    ans1 = (ans1 + (res.val[0][5]*g2)%mod)%mod;

    ans2 = (ans2 + (res.val[3][0]*f0)%mod)%mod;
    ans2 = (ans2 + (res.val[3][1]*f1)%mod)%mod;
    ans2 = (ans2 + (res.val[3][2]*f2)%mod)%mod;
    ans2 = (ans2 + (res.val[3][3]*g0)%mod)%mod;
    ans2 = (ans2 + (res.val[3][4]*g1)%mod)%mod;
    ans2 = (ans2 + (res.val[3][5]*g2)%mod)%mod;
    printf("%d %d\n",ans1,ans2);
}
int main()
{
    int cs=1, tc,q;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d",&a1,&b1,&c1);
        scanf("%d%d%d",&a2,&b2,&c2);
        scanf("%d%d%d",&f0,&f1,&f2);
        scanf("%d%d%d",&g0,&g1,&g2);
        scanf("%d",&mod);
        process();
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--)solve();
    }
    return 0;
}
