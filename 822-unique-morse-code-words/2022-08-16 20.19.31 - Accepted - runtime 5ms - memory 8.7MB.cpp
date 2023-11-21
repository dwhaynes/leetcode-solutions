class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> uniq;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto word: words){
            string s;
            for(auto ch: word){
                s+=morse[ch-'a'];
            }
            uniq.insert(s);
        }
        return uniq.size();
    }
};