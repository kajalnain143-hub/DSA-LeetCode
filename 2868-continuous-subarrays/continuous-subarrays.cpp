class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
      long long total=0;
      deque<pair<int,int>>MaxQue;  
      deque<pair<int,int>>MinQue;
      int left=0;
      for(int right=0;right<nums.size();right++){
        while(!MaxQue.empty() && MaxQue.back().first<=nums[right]){
            MaxQue.pop_back();
        }
        MaxQue.push_back({nums[right],right});
        while(!MinQue.empty() && MinQue.back().first>=nums[right]){
            MinQue.pop_back();
        }
        MinQue.push_back({nums[right],right});

       
       
      while(MaxQue.front().first-MinQue.front().first>2){
            left++;
            if(MaxQue.front().second<left){
                MaxQue.pop_front();
            }
            if(MinQue.front().second<left){
                MinQue.pop_front();
            }
        }
         if(MaxQue.front().first-MinQue.front().first<=2){
           total += right - left + 1;
        }
    }

      return total;
    }
};