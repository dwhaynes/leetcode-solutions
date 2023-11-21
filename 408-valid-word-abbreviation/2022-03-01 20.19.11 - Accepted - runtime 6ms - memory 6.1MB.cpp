class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int j = 0;
        int num = 0;
        for(int i = 0; i < abbr.size(); ++i){
            if(isalpha(abbr[i])){
                j+=num;
                num = 0;
                if(j < word.size() && word[j] == abbr[i]) j++;
                else return false;
            }else{
                if(abbr[i] == '0' && num == 0) return false;
                num*=10;
                num+=int(abbr[i]-'0');
            }
        }
        return j + num == word.size();
    }
};