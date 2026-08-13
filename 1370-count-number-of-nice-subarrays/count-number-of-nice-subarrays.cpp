class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
       unordered_map<int,int>mp;
       int sum =0;
       mp[0] = 1;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            sum +=0;
        }
        else{
            sum +=1;
        }
        int need = sum - k;
        if(mp.find(need)!=mp.end()){
            count += mp[need];
        }
        mp[sum]++;
       } 
       return count;
    }
};