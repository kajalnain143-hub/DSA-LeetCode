class Solution {
public:
    int Area(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> &visited,int area){
        if(i<0 || i>=grid.size() ||j<0 || j>=grid[0].size()){
            return 0;
        }
        if(grid[i][j] == 0 || visited[i][j])
    return 0;
        
        visited[i][j] = true;
        int up = Area(grid,i-1,j,visited,area);
        int down = Area(grid,i+1,j,visited,area);
        int left = Area(grid,i,j-1,visited,area);
        int right = Area(grid,i,j+1,visited,area);
        return 1 +up+down+ left+ right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int maxArea = 0;
       
      vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(), false));
      for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            int area=0;
            if(grid[i][j] == 1 && !visited[i][j]){
              int currentarea = Area(grid,i,j,visited,area);
                maxArea = max(maxArea,currentarea);
            }
            
        }
      }
      return maxArea;
    }
};