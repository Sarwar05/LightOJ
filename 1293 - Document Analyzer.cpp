#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int tc;
    cin>>tc;
    for(int cs=1; cs<=tc; cs++){
        string str,tem;
        unordered_map<string, int> mp;
        int val = 0;
        vector<string> input;
        while(getline(cin,str)){
            if(str=="END") break;
            for(int i=str.size()-1; i>=0; i--){
                if(islower(str[i]));
                else str[i] = ' ';
            }
            istringstream iss(str);
            while(iss>>tem){
                input.push_back(tem);
                if(mp.find(tem)==mp.end()){
                    mp[tem] = ++val;
                }
            }
        }
        cout<<"Case "<<cs<<": ";
        int len = input.size();
        vector<int> arr(len);
        for(int i=0; i<len; i++){
            arr[i] = (mp[ input[i] ]);
        }
        unordered_map<int, int> mp2;
        int a=-1,b=-1;
        int i,j;
        for(i=0; i<arr.size(); i++){
            mp2[ arr[i] ]++;
            if(mp2.size()==val){
                len = i+1;
                a = 1;
                b = len;
                j = i+1;
                i = 0;
                break;
            }
        }
        while(true){
            if(j>=arr.size() && mp2.size()<val) break;
            if(mp2.size()==val){
                mp2[ arr[i] ]--;
                if(mp2[ arr[i] ]==0){
                    mp2.erase(arr[i]);
                }
                i++;
            }
            else{
                mp2[ arr[j] ]++;
                j++;
            }
            if(mp2.size()==val){
                int temp = j-i;
                if(temp<len){
                    len = temp;
                    a = i+1;
                    b = j;
                }
            }
        }
        cout<<a<<" "<<b<<endl;
    }
}
