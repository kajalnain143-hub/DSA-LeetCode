class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      unordered_map<int,int>mp;
      int totalsum =0;
      int sum=0;
      int maxlen = 0;
      mp[0] = -1;
      for(int i=0;i<nums.size();i++){
        totalsum += nums[i];
      }
      int neededsum = totalsum - x;
      for(int i=0;i<nums.size();i++){
         sum += nums[i];
        int need = sum - neededsum;
         if(mp.find(need)!=mp.end()){
            int len = i - mp[need];
            maxlen = max(maxlen,len);
         }
         if(mp.find(sum) == mp.end()) {
    mp[sum] = i;
}
      } 
     
       if(maxlen == 0 && neededsum != 0)
    return -1;

        return nums.size() - maxlen;
    }
};