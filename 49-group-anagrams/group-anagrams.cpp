class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>finalans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string ch = strs[i];
            sort(ch.begin(),ch.end());
            mp[ch].push_back(strs[i]);
        }
        for(auto x : mp){
    finalans.push_back(x.second);
}
 return finalans;
    }
};