/*
LeetCode: 209
Title: Minimum Size Subarray Sum

Topic:
- Sliding Window (Variable)

Approach:
- Expand while sum < target.
- Shrink while sum >= target.
- Update minimum length during shrinking.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
Shrink when the window becomes valid.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right = 0;
        int sum =0;
    int minLen = INT_MAX;
        while(right<nums.size()){
             sum += nums[right];
         while(sum>=target){
             int currlen = right - left +1;
         minLen = min(currlen,minLen);
     
            sum -= nums[left];
            left++;
         }
        right++;
    }
    if(minLen==INT_MAX){
        return 0;
    }
      return minLen;
    }
};