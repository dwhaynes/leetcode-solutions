class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int nChars = INT_MAX;
        for(auto str: strs){
            nChars = min(nChars,(int) str.size());
        }
        string prefix = "";
        for(int i = 0; i < nChars; i++){
            char testval = strs[0][i];
            for(auto str: strs){
                if(str[i] != testval) return prefix;
            }
            prefix += testval;
        }
        return prefix;
    }
};