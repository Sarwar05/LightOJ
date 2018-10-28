#include<bits/stdc++.h>
using namespace std;
#define mx 110
double gauss(vector<vector<double> > &A)
{
    int n = A.size();
    for(int i=0; i<n; i++){
        ///search maximum in this column under pivot
        double mxval = abs(A[i][i]);
        int mxid = i;
        for(int j=i+1; j<n; j++){
            if(abs(A[j][i]) > mxval){
                mxval = abs(A[j][i]);
                mxid = j;
            }
        }
        /// swap mx row with current row
        for(int j=i; j<n+1; j++){
            swap(A[mxid][j], A[i][j]);
        }
        ///make lower triangle 0 | forward elimination
        for(int j = i+1; j<n; j++){
            double c = -A[j][i]/A[i][i];
            for(int k = i; k<n+1; k++){
                if(i==j){
                    A[j][k] = 0;
                }
                else{
                    A[j][k] += c*A[i][k];
                }
            }
        }
    }
    vector<double> x(n);
    /// backward substitution
    for(int i=n-1; i>=0; i--){
        x[i] = A[i][n]/A[i][i];
        for(int j = i-1; j>=0; j--){
            A[j][n] -= A[j][i]*x[i];
        }
        //cout<<i<<" "<<x[i]<<endl;
    }
    return x[0];
}
int go[mx];
int main()
{
    int tc,cs=1,m,a,b;
    scanf("%d",&tc);
    while(tc--){

        int n = 100;
        vector<double> line(n+1, 0);
        vector< vector<double> > A(n,line);
        for(int i=0; i<n; i++){
            A[i][n] = 1;
            A[i][i] = 1;
        }
        A[n-1][n] = 0;

        for(int i=0; i<mx; i++) go[i] = i;
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&a,&b);
            go[a-1] = b-1;
        }

        for(int i=0; i<99; i++){
            for(int j=1; j<=6; j++){
                int nxt = go[i+j];
                if(nxt>99)
                    A[i][i] -= 1.0/6.0;
                else{
                    A[i][nxt] -= 1.0/6.0;
                }
            }
        }

        printf("Case %d: %.8f\n",cs++,gauss(A));
    }
}
/**
2

14
4 42
9 30
16 8
14 77
32 12
37 58
47 26
48 73
62 19
70 89
71 67
80 98
87 24
96 76

0
*/
