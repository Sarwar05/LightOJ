#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
bool comp(int a,int b)
{
    int na = 0,nb = 0,x;
    x = sqrt(a);
    for(int i=1; i<=x; i++)
        if(a%i == 0)
            na+=2;
    if(x*x == a)
        na--;
    x = sqrt(b);
    for(int i=1; i<=x; i++)
        if(b%i == 0)
            nb+=2;
    if(x*x == b)
        nb--;
 
    if(na<nb)
        return true;
    else if(na == nb){
        if(a>b)
            return true;
        else
            return false;
    }
    else
        return false;
}
int main()
{
    vector<int> v;
    for(int i=1; i<=1000; i++)
        v.push_back(i);
    sort(v.begin(),v.end(),comp);
    int n,tc;cin>>tc;
    for(int t= 1; t<= tc; t++){
        cin>>n;
        cout<<"Case "<<t<<": "<<v[n-1]<<endl;
    }
 
    return 0;
}
 
