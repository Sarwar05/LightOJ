#include<bits/stdc++.h>
using namespace std;
bool LeapYear(long long year)
{
    if(year%4==0 && (year%100 !=0 || year%400 == 0) )
        return true;
    return false;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc;
    int day1,day2; long long year1,year2;
    long long tem1,tem2;
    string month1,month2;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        cin>>month1;
        scanf("%d%*c%lld",&day1,&year1);
        cin>>month2;
        scanf("%d%*c%lld",&day2,&year2);
        long long leap=0;
        if(year1 == year2){
            if(LeapYear(year1)){
                if((month1=="January"||month1=="February") && ((month2!="January"&&month2!="February")||(month2=="February"&&day2==29)))
                   leap = 1;
            }
            else
                leap = 0;
        }
        else{
            tem1 = (year1/4) - (year1/100) + (year1/400);
            tem2 = (year2/4) - (year2/100) + (year2/400);
            leap = tem2-tem1;
            //cout<<"leap: "<<leap<<endl;
            if(LeapYear(year1) && (month1 == "January" ||(month1=="February" && day1<=29)))
                leap++;
            if(LeapYear(year2) && ((month2=="January" ||(month2=="February" && day2<29))))
                leap--;
        }
        printf("Case %d: %lld\n",t,leap);
    }
    return 0;
}
