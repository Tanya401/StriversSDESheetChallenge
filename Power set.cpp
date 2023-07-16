#include <bits/stdc++.h> 
void find(int ind,int n,vector<int>temp,vector<vector<int>>&ans,vector<int>&v){
    if(ind == n){
        ans.push_back(temp);
        return;
    }
   
   find(ind+1,n,temp,ans,v);
    temp.push_back(v[ind]);
    find(ind+1,n,temp,ans,v);
    temp.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n = v.size();
    vector<int> temp;
    vector<vector<int>> ans;
    find(0,n,temp,ans,v);
    return ans;
}