class Solution {
    bool isVowel(char c){
        return c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    string sortVowels(string s) {
        vector<char> q;
        priority_queue<char, vector<char>, greater<char>> pq;
        for(auto ch: s){
            if(isVowel(ch)) pq.push(ch);
        }
        for(auto& ch: s){
            if(isVowel(ch)){
                ch = pq.top();
                pq.pop();
            }
        }

        return s;
    }
};