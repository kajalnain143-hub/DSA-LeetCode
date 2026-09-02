class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct =nums[0];
        int currmax = nums[0];
        int currmin = nums[0];
        for(int i=1;i<nums.size();i++){
             int oldMax = currmax;
             int oldMin = currmin;
           currmax = max({nums[i], oldMax * nums[i], oldMin * nums[i]});

currmin = min({nums[i], oldMax * nums[i], oldMin * nums[i]});
           maxProduct = max(maxProduct,currmax);
        }
        
        return maxProduct;
    }
};