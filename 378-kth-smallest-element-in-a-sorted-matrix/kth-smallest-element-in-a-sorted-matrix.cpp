class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      priority_queue<
    tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>
> pq;
       for(int i = 0; i < matrix.size(); i++) {
    pq.push({matrix[i][0], i, 0});
}
 // Find kth smallest
        for(int i = 0; i < k; i++) {

            auto [value, row, col] = pq.top();
            pq.pop();

            if(col + 1 < matrix[0].size()) {
                pq.push({
                    matrix[row][col + 1],
                    row,
                    col + 1
                });
            }

            if(i == k - 1) {
                return value;
            }
        }

        return -1;
    }
};
 
