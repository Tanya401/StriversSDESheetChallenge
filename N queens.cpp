void add(vector<vector<int>> &board,vector<vector<int>> &ans,int n)

{
    vector<int> temp;
    for(int i=0; i<n; i++)
{

        for(int j=0; j<n; j++)

      {

            temp.push_back(board[i][j]);

        }

    }

    ans.push_back(temp);

}
bool issafe(int row,int col,vector<vector<int>>&board,int n){
    int duprow = row;
    int dupcol = col;
    while(row>=0 && col>=0){
        if(board[row][col]==1) return false;
        row--;
        col--;
    }
    col = dupcol;
    row = duprow;
    while(col>=0){
        if(board[row][col]==1) return false;
        col--;
    }
    col = dupcol;
    row = duprow;
    while(row<n && col>=0){
        if(board[row][col]==1) return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n){
   if(col == n){
       add(board,ans,n);
       return;
   }

    for(int row=0;row<n;row++){
        if(issafe(row,col,board,n)){
            board[row][col] = 1;
            solve(col+1,board,ans,n);
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(0,board,ans,n);
    return ans;
}