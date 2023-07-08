void find(int x,int y,int m,int n,vector<vector<int>>&fill,int newColor,int oldcolor){
    if(x<0 || y<0 || x>=m || y>=n) return;
    
    if(fill[x][y]==newColor) return;

    if (fill[x][y] == oldcolor) {
      fill[x][y] = newColor;
      find(x + 1, y, m, n, fill, newColor, oldcolor);
      find(x - 1, y, m, n, fill, newColor, oldcolor);
      find(x, y - 1, m, n, fill, newColor, oldcolor);
      find(x, y + 1, m, n, fill, newColor, oldcolor);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
     int m = image.size();
     int n = image[0].size();

     int oldcolor = image[x][y];

     vector<vector<int>> fill = image;

     find(x,y,m,n,fill,newColor,oldcolor);
     
     return fill;
}