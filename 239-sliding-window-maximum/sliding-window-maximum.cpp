class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int left=0;
      int right=k;
     vector<int>Maxvalue;
      deque<pair<int,int>>MaxQue;
     for(int right=0;right<nums.size();right++){
       while(!MaxQue.empty() && MaxQue.back().first<=nums[right]){
        MaxQue.pop_back();
       }
       MaxQue.push_back({nums[right],right});
    if(right-left+1>k){    
    left++;
     
    }
    
    if(MaxQue.front().second < left) {
    MaxQue.pop_front();
}
if(right - left + 1 == k) {
    Maxvalue.push_back(MaxQue.front().first);
}
     } 
 
     
     return Maxvalue;
    }
};