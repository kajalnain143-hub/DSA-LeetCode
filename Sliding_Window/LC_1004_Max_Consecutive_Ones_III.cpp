/*
LeetCode: 1004
Title: Max Consecutive Ones III

Topic:
- Sliding Window (Variable)

Approach:
- Maintain zero count.
- Expand while zeroCount <= k.
- Shrink when zeroCount > k.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
Window invalid when zeroCount > k.
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen =0;
        int zerocount = 0;
        int left=0;
        int right = 0;
        int len =0;
        while(right<nums.size()){
           if(nums[right]==0){
            zerocount++;
           }
           
            while(zerocount>k){
                if(nums[left]==0){
                    zerocount--;
                }
               left++;
            }
                len = right - left +1;
               maxlen = max(maxlen,len);
                right++;
           
        }
        return maxlen;
    }
};