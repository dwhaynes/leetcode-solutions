class Solution {
    vector<int> count(string s){
        vector<int> ans(26,0);
        for(auto c:s) ans[c-'a']++;
        return ans;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        auto bmax = count("");
        for(auto b: words2){
            auto bCount = count(b);
            for(int i=0; i < 26;i++) bmax[i] = max(bmax[i],bCount[i]);
        }
        
        vector<string> ans;
        for(auto a:words1){
            bool flag = true;
            auto aCount = count(a);
            for(int i = 0; i < 26; i++) if(aCount[i] < bmax[i]){
                flag = false;
                break;
            }
            if(flag) ans.push_back(a);
        }
        return ans;
    }
};