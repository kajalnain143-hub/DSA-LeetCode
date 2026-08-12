class Solution {
public:
    struct Compare {
    bool operator()(const pair<int,string>& a,
                    const pair<int,string>& b) {

        if(a.first != b.first) {
            return a.first > b.first;
        }

        return a.second < b.second;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        vector<string>ans;
        priority_queue<pair<int,string>,vector<pair<int,string>>, Compare> pq;
        for(string word : words){
            mp[word]++;
        }
        for(auto x : mp){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
          ans.push_back(pq.top().second);
          pq.pop();  
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};