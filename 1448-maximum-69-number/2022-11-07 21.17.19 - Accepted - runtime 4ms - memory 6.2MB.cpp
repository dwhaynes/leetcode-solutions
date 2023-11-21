class Solution {
public:
    int maximum69Number (int num) {
        stack<int> digits;
        while(num){
            digits.push(num%10);
            num/=10;
        }
        int ans = 0;
        bool flag = false;
        while(!digits.empty()){
            if(digits.top() == 6 && !flag){
                digits.pop();
                ans*=10;
                ans+=9;
                flag = true;
            }else{
                ans*=10;
                ans+=digits.top();
                digits.pop();
            }
        }
        return ans;
    }
};