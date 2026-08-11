class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
       int left = 1;
       int right = 1;
       ans[0] = 1;
       for(int i=1;i<nums.size();i++){
        left *= nums[i-1];
        ans[i] = left;
       }
       for(int j=nums.size()-1;j>=0;j--){
        ans[j] = right*ans[j];
        right *= nums[j];
       }
       return ans;
    }
};