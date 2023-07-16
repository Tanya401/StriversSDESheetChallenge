int find(vector<int>&row,int mid){
    int low=0,high=row.size()-1;
    while(low<=high){
        int newmid=(low+high)/2;
        //>mid
        if(row[newmid] <= mid) low=newmid+1;
        else high=newmid-1;
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low=1,high=1e9;
    int n=matrix.size();
    int m=matrix[0].size();
    while(low<=high){
        int mid = (low+high)/2;
        int cnt=0; //<=mid
        for(int i=0;i<n;i++){
            cnt+=find(matrix[i],mid);
        }
        if(cnt<= (n*m)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}