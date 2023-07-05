bool validrow(int matrix[9][9],int row,int k){
    for(int j=0;j<9;j++){
        if(matrix[row][j]==k) return false;
    }
    return true;
}

bool validcol(int matrix[9][9],int col,int k){
    for(int i=0;i<9;i++){
        if(matrix[i][col]==k) return false;
    }
    return true;
}

bool validgrid(int matrix[9][9],int row,int col,int k){
    for(int i=0;i<9;i++){
    if (matrix[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
      return false;
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j] == 0){
                for(int k=1;k<=9;k++){
                    if(validrow(matrix,i,k) && validcol(matrix,j,k) && validgrid(matrix,i,j,k)){
                        matrix[i][j] = k;
                        if(isItSudoku(matrix)==true) return true;
                        else matrix[i][j] = 0;
                    }
                }
                 return false;
            }
        }
    }
    return true;
}
