class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
      int low = 1;
      int high = *max_element(candies.begin(),candies.end());
      long long totalcandies =  accumulate(candies.begin(),candies.end(),0LL);
      if(k>totalcandies){
        return 0;
      }
      while(low<high){
        int mid = low + (high-low+1)/2;
         long long children = 0;
        for(int i=0;i<candies.size();i++){
            children += candies[i]/mid;
        }
        if(children<k){
            high= mid-1;
        }
        else{
           low = mid;
        }
      }
      return low; 
    }
};