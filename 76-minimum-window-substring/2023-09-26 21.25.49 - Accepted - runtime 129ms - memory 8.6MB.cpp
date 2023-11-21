class Solution {
    bool isMatch(unordered_map<char,int>& hs, unordered_map<char,int>& ht){
        for(auto [k,v]: ht){
            if(hs[k] < v) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        unordered_map<char,int> ht, hs;
        for(int i = 0; i < t.size(); i++){
            ht[t[i]]++;
            hs[s[i]]++;
        }

        if(isMatch(hs,ht)) return s.substr(0,t.size());

        int l = 0, minLen = INT_MAX, bestL, bestR;

        for(int r = t.size(); r < s.size(); r++){
            hs[s[r]]++;
            while(isMatch(hs,ht)){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    bestL = l;
                    bestR = r;
                }
                hs[s[l++]]--;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(bestL,bestR-bestL+1);
    }
};