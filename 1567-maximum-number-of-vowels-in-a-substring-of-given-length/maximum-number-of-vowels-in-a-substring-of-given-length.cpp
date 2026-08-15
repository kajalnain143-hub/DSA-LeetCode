class Solution {
public:
    int maxVowels(string s, int k) {
     int left = 0;
     int maxvowel = 0;
     int vowel =0;
     for(int i=0;i<k;i++){
        if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ){
            vowel++;
        }
       maxvowel = max(maxvowel,vowel);
     } 
     for(int i=k;i<s.size();i++){
        
       if(s[left]=='a' || s[left]=='e' ||s[left]=='i' ||s[left]=='o' ||s[left]=='u' ){
            vowel--;
           
        }
          left++;
        if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ){
            vowel++;
        }
        maxvowel = max(maxvowel,vowel);
     } 
     return maxvowel; 
    }
};