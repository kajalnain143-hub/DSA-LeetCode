class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_map<char,int>mp;
     int LongestLen = 0;
     int maxLen =0;
     int left = 0;
     for(int right = 0;right<s.size();right++){
        while(mp.find(s[right])!=mp.end()){
            mp.erase(s[left]);
            left++;
            LongestLen--;
        }
        if(mp.find(s[right])==mp.end()){
            LongestLen++;
            
        }
        
         maxLen = max(maxLen,LongestLen);
            mp[s[right]]++;
      
     }
     return maxLen;   
    }
};