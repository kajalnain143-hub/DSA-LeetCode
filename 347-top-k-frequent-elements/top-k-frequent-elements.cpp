class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     vector<int>ans;
    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
     for(int num :nums ){
        mp[num]++;
     }
    for(auto num : mp){
        pq.push({num.second,num.first});
        if(pq.size()>k){
            pq.pop();
        }
    }
    for(int i=0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
    } 
    return ans;
    }
};