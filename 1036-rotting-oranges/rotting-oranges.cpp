class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int minutes = 0;
        int fresh = 0;

        queue<pair<int,int>> q;

        // Initial rotten oranges + fresh count
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == 2) {
                    q.push({i,j});
                }

                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                auto [r,c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < grid.size() &&
                       nc >= 0 && nc < grid[0].size() &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            if(!q.empty())
                minutes++;
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};