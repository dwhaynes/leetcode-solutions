class Solution {
    bool isVowel(char c){
        return c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    string sortVowels(string s) {
        vector<char> q;
        for(auto ch: s){
            if(isVowel(ch)) q.push_back(ch);
        }
        sort(q.begin(),q.end());
        int idx = 0;
        for(auto& ch: s){
            if(isVowel(ch)){
                ch = q[idx++];
            }
        }

        return s;
    }
};