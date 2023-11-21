class Solution {
public:
    int numberOfSteps(int num) {
        int ct = 0;
        while(num){
            ct++;
            if(num %2 == 0) num/=2;
            else num--;
        }
        return ct;
    }
};