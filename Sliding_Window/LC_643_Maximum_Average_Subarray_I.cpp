/*
LeetCode: 643
Title: Maximum Average Subarray I

Topic:
- Sliding Window (Fixed)

Approach:
- Calculate the sum of the first window of size k.
- Slide the window by removing the outgoing element
  and adding the incoming element.
- Track the maximum sum and return its average.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
Fixed Sliding Window = Outgoing + Ingoing
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int windowSum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};