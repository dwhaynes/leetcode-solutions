class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> counts;
        for(auto word: words){
            string out = "";
            for(auto ch: word){
                out += table[(ch-'a')];
            }
            counts.insert(out);
        }
        return counts.size();
    }
};