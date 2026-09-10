class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>&grid,vector<vector<int>>&visited){
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || visited[r][c]){
        return;
    }
    if(grid[r][c] == '0') return;
   visited[r][c] = 1;
      dfs(r+1,c,grid,visited);
      dfs(r-1,c,grid,visited);
      dfs(r,c-1,grid,visited);
      dfs(r,c+1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(), 0));
        int count =0;
     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1' && visited[i][j]==0){
                count++;
            dfs(i,j,grid,visited);
            }
        }
     }
     return count;
    }
};