#include<bits/stdc++.h>
using namespace std;
#define dim 4
#define mod 10007
struct Matrix
{
    int val[dim][dim];
};
Matrix identity()
{
    Matrix ob;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ob.val[i][j] = (i==j);
        }
    }
    return ob;
}
Matrix init( int a, int b)
{
    Matrix ob = identity();
    for(int i=0; i<dim; i++) ob.val[i][i] = 0;
    ob.val[0][1] = ob.val[1][2] = ob.val[3][3] = ob.val[2][3] = 1;
    ob.val[2][0] = b;
    ob.val[2][2] = a;
    return ob;
}
Matrix multiply(Matrix& x, Matrix& y)
{
    Matrix ret;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ret.val[i][j] = 0;
            for(int k=0; k<dim; k++){
                ret.val[i][j] = (ret.val[i][j] + (x.val[i][k] * y.val[k][j])%mod)%mod;
            }
        }
    }
    return ret;
}
Matrix bigMod(Matrix base, int p)
{
    if(p==0) return identity();
    Matrix x = bigMod(base, p/2);
    x = multiply(x,x);
    if(p%2) x = multiply(x,base);
    return x;
}
int main()
{
    int tc,cs=1,n,a,b,c;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d%d",&n,&a,&b,&c);
        if(n<=2){
            printf("Case %d: %d\n",cs++,0);
            continue;
        }
        Matrix mat = bigMod(init(a,b), n-3);
        int f3 = (c)%mod;
        int f4 = (a*f3 + c)%mod;
        int f5 = (a*f4 + c)%mod;
        int ans = mat.val[0][0]*f3 + mat.val[0][1]*f4 + mat.val[0][2]*f5 + mat.val[0][3]*c;
        printf("Case %d: %d\n",cs++, ans%mod);
    }
    return 0;
}

