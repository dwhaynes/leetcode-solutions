class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> map;
        set<char> mapped;
        int n = s.size();
        int m = t.size();
        if (n != m) return false;
        
        for(int i = 0; i < n; i++){
            if(map.find(s[i]) != map.end()){
                if(map[s[i]] != t[i]) return false;
            }else{
                if(mapped.find(t[i]) != mapped.end()) return false;
                mapped.insert(t[i]);
                map[s[i]]=t[i];
            }
        }
        return true;
    }
};