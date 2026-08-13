class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int count = 0;
      int sum = 0;
      unordered_map<int,int>mp;
      mp[0] = 1;
      for(int i=0;i<nums.size();i++){
        sum += nums[i];
        int need = sum - goal;
        if(mp.find(need)!=mp.end()){
            count += mp[need];
        }
        mp[sum]++;
      } 
      return count; 
    }
};