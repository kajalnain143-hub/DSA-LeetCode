class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      int count =0;
      int prefixsum =0;
      mp[0] = 1;
      for(int i=0;i<nums.size();i++){
         prefixsum+=nums[i];
         int need = prefixsum-k;
         if(mp.find(need)!=mp.end()){
            count += mp[need];
         }
        
         mp[prefixsum]++;
       
      }
      return count;
    }
};