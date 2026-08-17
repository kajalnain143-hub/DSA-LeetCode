class Solution {
public:
   void Island(vector<vector<char>>& grid,int i,int j,vector<vector<bool>> &visited){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() ){
        return;
    }
   
      if(grid[i][j] == '0' || visited[i][j])
    {
        return;
    }

    visited[i][j] = true;

    Island(grid, i, j-1, visited);
    Island(grid, i, j+1, visited);
    Island(grid, i-1, j, visited);
    Island(grid, i+1, j, visited);
}
    int numIslands(vector<vector<char>>& grid) {
       int row = grid.size();
       int col = grid[0].size();
       int count = 0;
       vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0;i<row;i++){
        for(int j=0;j<grid[0].size();j++){
           if(grid[i][j] == '1' && !visited[i][j]){
      
         count++;
         
    
      Island(grid,i,j,visited);
           }
        }
        }
      return count;
    }
};