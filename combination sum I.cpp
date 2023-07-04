void find(int ind,int n,vector<int>temp,vector<vector<int>> &ans,vector<int>&arr,int k){
    if(ind >= n){
      if(k==0){
          ans.push_back(temp);
      }
      return;
    }

    temp.push_back(arr[ind]);
    find(ind+1,n,temp,ans,arr,k-arr[ind]);
    temp.pop_back();
    find(ind+1,n,temp,ans,arr,k);
    return;
}



vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    if(arr.empty()) return ans;
    vector<int> temp;
    find(0,n,temp,ans,arr,k);
    return ans;
}