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

        int l = 0, minLen = INT_MAX;
        string ans, temp = s.substr(0,t.size());

        for(int r = t.size(); r < s.size(); r++){
            temp+=s[r];
            hs[s[r]]++;
            while(isMatch(hs,ht)){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    ans = temp;
                }
                temp.erase(0,1);
                hs[s[l++]]--;
            }
        }
        return minLen == INT_MAX ? "" : ans;
    }
};