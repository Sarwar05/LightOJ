#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int dim = 2;// dimensom
ll mod;
struct Matrix
{
    ll val[dim+1][dim+1];
};
void init(Matrix& ob)
{
    ob.val[0][0] = 0; ob.val[0][1] = 1;
    ob.val[1][0] = 1; ob.val[1][1] = 1;
}
Matrix multiply(const Matrix& a, const Matrix& b)
{
    Matrix ret;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ret.val[i][j] = 0;
            for(int k=0; k<dim; k++){
                ret.val[i][j] = (ret.val[i][j] + (a.val[i][k]*b.val[k][j])%mod)%mod;
            }
        }
    }
    return ret;
}
Matrix identity()
{
    Matrix ret;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            ret.val[i][j] = (i==j);
        }
    }
    return ret;
}
//Matrix bigMod(Matrix &base, ll power)
//{
//    Matrix now = identity();
//    while(power>0){
//        if(power%2==1){
//            now = multiply(base, now);
//        }
//        base = multiply(base, base);
//        power/=2;
//    }
//    return now;
//}
Matrix bigMod(Matrix base, ll power)
{
    if(power==0) return identity();
    Matrix x = bigMod(base, power/2);
    x = multiply(x,x);
    if(power%2==1) x = multiply(x,base);
    return x;
}
int main()
{
    Matrix mat;
    int tc,cs=1,n,a,b,m;
    scanf("%d",&tc);
    while(tc--){
        init(mat);
        scanf("%d%d%d%d",&a,&b,&n,&m);
        mod = 1;
        for(int i=1; i<=m; i++){
            mod*=10;
        }
        mat = bigMod(mat, n);
//        cout<<mat.val[0][0]<<" "<<mat.val[0][1]<<endl;
//        cout<<mat.val[1][0]<<" "<<mat.val[1][1]<<endl;
        int ans = ((mat.val[0][0]*a)%mod + (mat.val[0][1]*b)%mod)%mod;
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
