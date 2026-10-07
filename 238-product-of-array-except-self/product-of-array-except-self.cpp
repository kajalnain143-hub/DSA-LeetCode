class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int>left_multiply(nums.size());
      left_multiply[0] = 1;
      for(int i=1;i<nums.size();i++){
         left_multiply[i] = left_multiply[i-1]*nums[i-1];
      } 
      vector<int>multiply(nums.size());
      int right_pro = 1;
      for(int i = nums.size()-1;i>=0;i--){
       multiply[i] = left_multiply[i]*right_pro;
       right_pro *= nums[i];
      }
      return multiply;
    }
};