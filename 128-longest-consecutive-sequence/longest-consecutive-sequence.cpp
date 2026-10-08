class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        unordered_set<int>st;
        // Put everything in set
        for(int num : nums){
            st.insert(num);
        }
       int maxlen = 0;
       for(int num:st){
        if(!st.count(num-1)){
            int current = num;
            int len  = 1;
            while(st.count(current+1)){
                current++;
                len++;
            }
            maxlen = max(maxlen,len);
        }
       }
        return maxlen;
    }
};