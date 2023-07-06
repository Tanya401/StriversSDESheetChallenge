#include <bits/stdc++.h> 
vector<int> merge(vector<int> a,vector<int> b){
    vector<int> temp;
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(b[j]);
            j++;
        }
    }
    while(i<n) temp.push_back(a[i++]);
    while(j<m) temp.push_back(b[j++]);

    return temp;
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    //algo -> take two at a time and keep on merging

   vector<int> temp;
    for(int i=0;i<k;i++){
     temp = merge(temp,kArrays[i]);
    }
    return temp;
}
