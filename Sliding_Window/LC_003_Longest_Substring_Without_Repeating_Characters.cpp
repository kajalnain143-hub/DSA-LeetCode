/*
LeetCode: 3
Title: Longest Substring Without Repeating Characters

Topic:
- Sliding Window (Variable)

Approach:
- Maintain character frequency using HashMap.
- Expand the window.
- If duplicate appears, shrink until window becomes valid.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
Window invalid when any character frequency > 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int right =0;
        unordered_map<char,int>mp;
        int maxLen =0;
       while(right<s.size()){
        mp[s[right]]++;
         
        while(mp[s[right]]>1){
            mp[s[left]]--;
            left++;
        }
      int  len = right - left +1;
        maxLen= max(maxLen,len);
        right++;
       } 
       return maxLen;
    }
};