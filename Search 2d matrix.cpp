bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
  int i = 0, j=n-1;
  while(i<m && j>=0){
      if(mat[i][j] == target) return true;
      else if(mat[i][j] > target) j--;
      else i++;
  }
  return false;
}