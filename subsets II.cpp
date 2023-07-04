#include <bits/stdc++.h> 
void find(int ind,int n,vector<int>&arr,vector<int>temp,set<vector<int>> &st){
    if(ind > n-1){
        st.insert(temp);
        return;
    }
    find(ind+1,n,arr,temp,st);

    temp.push_back(arr[ind]);

    find(ind+1,n,arr,temp,st);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;
    sort(arr.begin(),arr.end());
    vector<int> temp;
    find(0,n,arr,temp,st);
    vector<vector<int>> ans;
    for(auto &it:st){
        ans.push_back(it);
    }
    return ans;
}