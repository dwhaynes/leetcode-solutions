class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            auto temp = strs[i];
            sort(temp.begin(),temp.end());
            map[temp].push_back(strs[i]);
        }
        for(auto [k,v]:map) ans.push_back(v);
        return ans;
    }
};