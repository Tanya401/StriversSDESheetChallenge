#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<m;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}