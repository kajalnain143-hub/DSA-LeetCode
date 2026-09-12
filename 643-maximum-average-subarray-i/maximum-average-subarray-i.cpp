class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int left=0;
      int right=k-1;
      double sum =0;
      double maxAvg = INT_MIN;
      for(int i=0;i<=right;i++){
        sum+=nums[i];
      }
      maxAvg = max(maxAvg,sum/k);
      for(int right =k;right<nums.size();right++){
        sum -= nums[left];
        left++;
        sum += nums[right];
        maxAvg = max(maxAvg,sum/k);
      } 
      return maxAvg; 
    }
};