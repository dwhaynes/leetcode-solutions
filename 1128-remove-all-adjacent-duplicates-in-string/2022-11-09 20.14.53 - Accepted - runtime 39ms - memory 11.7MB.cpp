class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> S;
        int Slen = 0;
        for(auto ch: s){
            if(!S.empty() && ch == S.back()){
                S.pop_back();
            }else{
                S.push_back(ch);
            }
        }
        return string(S.begin(),S.end());
    }
};