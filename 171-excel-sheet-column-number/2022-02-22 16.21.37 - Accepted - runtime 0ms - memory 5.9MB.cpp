class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(auto c: columnTitle){
            result*=26;
            result+=(c-'A'+1);
        }
        return result;
    }
};