class Solution {
public:

    // Phase 1: island ko ID do aur uska area return karo
    int dfs(vector<vector<int>>& grid, int i, int j, int id) {

        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] != 1) {
            return 0;
        }

        // current cell ko island ID de do
        grid[i][j] = id;

        return 1
            + dfs(grid, i - 1, j, id)
            + dfs(grid, i + 1, j, id)
            + dfs(grid, i, j - 1, id)
            + dfs(grid, i, j + 1, id);
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        // island ID 2 se start
        int id = 2;

        // area[id] = us island ka area
        vector<int> area(n * n + 2, 0);

        // -------------------------
        // PHASE 1
        // -------------------------

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    area[id] = dfs(grid, i, j, id);

                    id++;
                }
            }
        }

        // -------------------------
        // PHASE 2
        // -------------------------

        int ans = 0;

        // Agar already all 1 hain,
        // Phase 2 mein 0 nahi milega.
        // Isliye existing island areas se answer update karo.
        for (int k = 2; k < id; k++) {
            ans = max(ans, area[k]);
        }

        // Har 0 ko ek baar flip karke dekho
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {

                    int current = 1; // ye 0 → 1 banega

                    set<int> ids;

                    // UP
                    if (i - 1 >= 0 && grid[i - 1][j] > 1)
                        ids.insert(grid[i - 1][j]);

                    // DOWN
                    if (i + 1 < n && grid[i + 1][j] > 1)
                        ids.insert(grid[i + 1][j]);

                    // LEFT
                    if (j - 1 >= 0 && grid[i][j - 1] > 1)
                        ids.insert(grid[i][j - 1]);

                    // RIGHT
                    if (j + 1 < n && grid[i][j + 1] > 1)
                        ids.insert(grid[i][j + 1]);

                    // unique islands ke areas add karo
                    for (int islandId : ids) {
                        current += area[islandId];
                    }

                    ans = max(ans, current);
                }
            }
        }

        return ans;
    }
};