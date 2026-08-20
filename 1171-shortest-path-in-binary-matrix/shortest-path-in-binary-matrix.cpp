class Solution {
public:
   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
       queue<pair<pair<int,int>, int>> q;
        grid[0][0] = 1;
        q.push({{0,0},1});
       
         while(!q.empty())
        {
            // Current cell
            auto current = q.front();
            q.pop();

            int i = current.first.first;
            int j = current.first.second;
            int distance = current.second;
int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};
            for(int k = 0; k < 8; k++){
            int ni = i + dr[k];
           int nj = j + dc[k];
           if(ni >= 0 && ni < n && nj >= 0 && nj <n )
{
    if(grid[ni][nj]==0){
        grid[ni][nj]=1;
        q.push({{ni,nj},distance+1});
    }
}
}
 if(i == n-1 && j == n-1)
{
    return distance;
}
        }
       
        return -1;
    }
};