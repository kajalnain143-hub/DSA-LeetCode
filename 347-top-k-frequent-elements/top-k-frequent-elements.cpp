class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
       }
     vector<pair<int,int>>freq;
     for(auto x: mp){
        freq.push_back(x);
     }
     sort(freq.begin(),freq.end(),[](auto a,auto b){
        return a.second>b.second;
     });
    for(int i=0;i<k;i++){
        ans.push_back(freq[i].first);
    }
    return ans;
    }
};