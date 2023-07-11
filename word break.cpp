#include <bits/stdc++.h> 
void find(int ind,string res,string &s,unordered_map<string,int>&mp,
vector<string>&ans){
  if(ind == s.size()){
      ans.push_back(res);
      return;
  }
    string temp;
    for(int i=ind;i<s.size();i++){
       temp += s[i];
       if (mp.find(temp) != mp.end()) {
         if (res.length() == 0){
            find(i+1,res+temp,s,mp,ans);
         } else {
            find(i+1,res+"",s,mp,ans);
         }
       }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
   unordered_map<string,int> mp;
   for(auto it:dictionary) mp[it]++;
   vector<string> ans;
   string res;
   find(0,res,s,mp,ans);
   return ans;
}