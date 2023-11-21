class Solution {
public:
    int minAddToMakeValid(string s) {
        int acc = 0;
        int total = 0;
        for(auto ch: s){
            if(ch == '('){
                if(acc < 0){
                    total-=acc;
                    acc = 0;
                }
                acc++;
            }
            else acc--;
        }
        total+= (acc > 0 ? acc : -acc);
        return total;
    }
};