class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        string word = "";  
        for(char ch:s){
          if(ch==' '){
            words.push_back(word);
            word = "";
          }
          else{
            word += ch;
          }
        }
        words.push_back(word);
        if(pattern.size() != words.size())
    return false;
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
      for(int i = 0; i < pattern.size(); i++) {

    char ch = pattern[i];
    string word = words[i];

    if(mp1.count(ch) && mp1[ch] != word)
        return false;

    if(mp2.count(word) && mp2[word] != ch)
        return false;

    mp1[ch] = word;
    mp2[word] = ch;
}
        return true;
    }
};