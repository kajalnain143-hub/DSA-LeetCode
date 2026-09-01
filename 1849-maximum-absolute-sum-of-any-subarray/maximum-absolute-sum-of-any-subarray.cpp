class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
      // Maximum subarray sum 
      int currsum = nums[0];
      int maxSum = nums[0];
      for(int i=1;i<nums.size();i++){
        currsum = max(nums[i],currsum+nums[i]);
        maxSum = max(maxSum,currsum);
      }  
    // Minimum subarray sum
     currsum = nums[0];
      int minSum = nums[0];
       for(int i=1;i<nums.size();i++){
        currsum = min(nums[i],currsum+nums[i]);
        minSum = min(minSum,currsum);
      } 
      return max(maxSum,abs(minSum)); 
    }
};