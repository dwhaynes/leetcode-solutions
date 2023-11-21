class Solution {
    vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    void recurse(string prefix,string& digits, int pos){
        if(pos == digits.size()){
            res.push_back(prefix);
            return;
        }
        int digit = digits[pos] - '0';
        for(auto ch : keys[digit]){
            recurse(prefix+ch,digits,pos+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        recurse("",digits,0);
        return res;
    }
};