/*
LeetCode: 567
Title: Permutation in String

Topic:
- Sliding Window (Fixed)

Approach:
- Maintain frequency of s1.
- Maintain frequency of current window.
- Compare both frequency arrays/maps.
- Slide using outgoing and ingoing characters.

Time Complexity: O(n)
Space Complexity: O(1)

Key Learning:
Fixed Sliding Window = Outgoing + Ingoing.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
    return false;
        int left =0;
        int right = s1.size()-1;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(char ch : s1){
            mp1[ch]++;
        }
        for(int i=left;i<=right;i++){
            mp2[s2[i]]++;
           }
        while(right<s2.size()){
           if(mp1==mp2){
            return true;
           }
 if(right == s2.size() - 1)
        break;
            right++;
           mp2[s2[right]]++;
           mp2[s2[left]]--;
        
          if(mp2[s2[left]] == 0){
    mp2.erase(s2[left]);
}
              left++;
        }
         if(mp1==mp2){
            return true;
           }
        return false;
    }
};