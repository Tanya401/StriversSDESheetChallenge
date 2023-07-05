#include <bits/stdc++.h> 
bool palindrome(string &res,int i,int j){
    while(i<=j){
        if(res[i]!=res[j]) return false;
        i++;
        j--;
    }
    return true;
}
void find(int ind,int n,vector<string>&temp,vector<vector<string>>&ans,string&s){
     if(ind>=n){
         ans.push_back(temp);
         return;
     }
   for(int i=ind;i<n;i++){
       if(palindrome(s,ind,i)==true){
        temp.push_back(s.substr(ind,i-ind+1));
           find(i+1,n,temp,ans,s);
           temp.pop_back();
       }
   }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> temp;
    find(0,s.size(),temp,ans,s);
    return ans;
}