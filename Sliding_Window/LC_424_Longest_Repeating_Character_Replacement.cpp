/*
LeetCode: 424
Title: Longest Repeating Character Replacement

Topic:
- Sliding Window (Variable)

Approach:
- Maintain character frequencies.
- Track maximum frequency.
- Shrink when required replacements > k.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
Required Replacements = Window Size - Max Frequency.
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int maxLen=0;
        int maxFreq =0;
        unordered_map<char,int>mp;
        while(right<s.size()){
           mp[s[right]]++;
           maxFreq = max(maxFreq,mp[s[right]]);
           int windowSize = right - left + 1;
           while(windowSize - maxFreq >k){
            mp[s[left]]--;
             left++;
             windowSize = right - left + 1; 
           }
         
            maxLen = max(windowSize,maxLen);
            right++;
        }
        return maxLen;
    }
};