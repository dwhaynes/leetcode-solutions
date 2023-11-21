class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string,vector<string>> groups;
        for(auto str: strings){
            string pattern = "";
            for(int i = 1; i < str.size();i++){
                int diff = str[i]-str[i-1];
                if(diff < 0) diff+=26;
                pattern+=to_string(diff)+',';
            }
            groups[pattern].push_back(str);
        }
        vector<vector<string>> out;
        for(auto [key,value]: groups){
            out.push_back(value);
        }
        return out;
    }
};