class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int left=0;
       int right = k;
       int sum =0;
       for(int i=0;i<k;i++){
         sum+=nums[i];
       
       }
        
         double maxavg = (double)sum/k;
         
        for(int i=k;i<nums.size();i++){
           
            sum +=  nums[i] - nums[left];
             left++;
           maxavg = max(maxavg,(double)sum/k);
        }
        return maxavg;
    }
    
};