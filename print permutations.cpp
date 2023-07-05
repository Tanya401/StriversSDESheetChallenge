#include <bits/stdc++.h> 
void find(string temp,vector<string>&ans,vector<int>&freq,string &s){
   if(temp.size()==freq.size()){
       ans.push_back(temp);
       return;
   }
    for(int i=0;i<freq.size();i++){
        if(freq[i]==0){
            temp += s[i];
            freq[i]=1;
            find(temp,ans,freq,s);
            freq[i]=0;
            temp.pop_back();
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    int n = s.size();
    vector<int> freq(n,0);
    string temp = "";
    find(temp,ans,freq,s);
    return ans;
}