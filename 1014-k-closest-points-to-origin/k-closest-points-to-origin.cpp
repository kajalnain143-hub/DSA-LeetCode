class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     priority_queue<pair<int, vector<int>>> pq;
      vector<vector<int>>ans;
      for(auto num : points){
        pq.push({(num[0]*num[0])+(num[1]*num[1]),num});
        if(pq.size()>k){
            pq.pop();
        }
      } 
   while(!pq.empty()){
    ans.push_back(pq.top().second);
    pq.pop();
   }
   return ans;
    }
};