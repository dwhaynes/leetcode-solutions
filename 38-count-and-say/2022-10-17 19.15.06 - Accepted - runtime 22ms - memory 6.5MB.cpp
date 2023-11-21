class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string input = countAndSay(n-1);
        string ans;
        char last = input[0];
        int count = 1;
        for(int i = 1; i < input.size(); i++){
            if(input[i] == last){
                count++;
            }else{
                ans += to_string(count);
                ans += last;
                last = input[i];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += last;
        return ans;
    }
};