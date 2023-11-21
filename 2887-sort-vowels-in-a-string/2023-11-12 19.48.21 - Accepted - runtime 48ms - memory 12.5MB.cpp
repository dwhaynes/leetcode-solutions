class Solution {
public:
    string sortVowels(string s) {
        string vowels = "AEIOUaeiou";
        vector<char> q;
        for(auto ch: s){
            if(vowels.find(ch) != string::npos) q.push_back(ch);
        }
        sort(q.begin(),q.end());
        int idx = 0;
        for(auto& ch: s){
            if(vowels.find(ch) != string::npos){
                ch = q[idx++];
            }
        }

        return s;
    }
};