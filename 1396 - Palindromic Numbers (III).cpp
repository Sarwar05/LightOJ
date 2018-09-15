#include<bits/stdc++.h>
using namespace std;
char str[100005];
int len,i,j,x,carry,mid;
bool all9()
{
    for(i=0; i<len; i++)
        if(str[i]!='9')
            return false;
    return true;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=1; t<=tc; t++){
        scanf("%s",str);
        len = strlen(str);
        printf("Case %d: ",t);
        if(all9()){
            printf("1");
            for(int l=1; l<len; l++)
                printf("0");
            printf("1\n");
        }
        else{
            mid = len/2;
            bool leftSmaller = false;
            i = mid-1;
            j = (len%2) ? mid+1 : mid;
            // ignore middle same digits
            while(i>=0 && str[i]==str[j])
                i--,j++;
            // boundary crossed or left is smaller, then you need to add 1 in middle
            if(i<0 || str[i]<str[j])
                leftSmaller = true;
            // copy mirror of left to right
            while(i>=0){
                str[j] = str[i];
                i--,j++;
            }
            // handle the case of incrementing middle digit
            if(leftSmaller == true){
                carry = 1;
                i = mid-1;
                // if odd digits, then increment the middle and store th carry
                if(len%2==1){
                    x = str[mid]-'0';
                    x+=carry;
                    carry = x/10;
                    x = x%10;
                    str[mid] = x+'0';
                    j = mid+1;
                }
                else
                     j = mid;
                while(i>=0){
                    x = str[i]-'0';
                    x+=carry;
                    carry = x/10;
                    x = x%10;
                    str[i] = x+'0';
                    str[j++] = str[i--];
                }
            }
            printf("%s\n",str);
        }
    }
}
/*
http://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
*/