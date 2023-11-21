class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> combs, prefix = {""};
        for(char dig: digits){
            int digit = dig - '0';
            for(auto ch : keys[digit]){
                for(auto str: prefix){
                    combs.push_back(str+ch);
                }
            }
            prefix = combs;
            combs = {};
        }
        auto it = find(prefix.begin(),prefix.end(),"");
        if(it != prefix.end()) prefix.erase(it);
        sort(prefix.begin(),prefix.end());
        return prefix;
    }
};