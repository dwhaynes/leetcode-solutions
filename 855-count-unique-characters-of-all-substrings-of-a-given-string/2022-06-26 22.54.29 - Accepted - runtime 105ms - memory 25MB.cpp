class Solution {
public:
    int uniqueLetterString(string s) {
        int total = 0;
        auto indices = vector<vector<int>>(26,vector<int>(1,-1));
        for(int i = 0; i < s.size(); i++) indices[s[i]-'A'].push_back(i);
        for(int i = 0; i < 26; i++){
            indices[i].push_back(s.size());
            for(int j = 1; j < indices[i].size()-1; j++){
                int left = indices[i][j] - indices[i][j-1];
                int right = indices[i][j+1] - indices[i][j];
                total+=left*right;
            }
        }
        return total;
    }
};