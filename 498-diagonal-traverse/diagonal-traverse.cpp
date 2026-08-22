class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        int i = 0;
        int j = 0;
        int dir = 1;

        while(ans.size() < m * n) {

            ans.push_back(mat[i][j]);

            int ni, nj;

            if(dir == 1) {
                // Up-right
                ni = i - 1;
                nj = j + 1;
            }
            else {
                // Down-left
                ni = i + 1;
                nj = j - 1;
            }

            // Next position valid hai
            if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                i = ni;
                j = nj;
            }

            // Boundary aa gayi
            else {
                dir = 1 - dir;

                if(dir == 0) {
                    // Ab down-left jaana hai
                    if(j + 1 < n) {
                        j++;
                    }
                    else {
                        i++;
                    }
                }
                else {
                    // Ab up-right jaana hai
                    if(i + 1 < m) {
                        i++;
                    }
                    else {
                        j++;
                    }
                }
            }
        }

        return ans;
    }
};