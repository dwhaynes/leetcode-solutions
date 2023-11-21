class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        digits[n-1]+=1;
        for(int i = n-1; i >= 0; i--){
            digits[i]+=carry;
            carry = digits[i]/10;
            digits[i]%=10;
        }
        if (carry == 0) return digits;
        vector<int> temp = {carry};
        for(auto val: digits) temp.push_back(val);
        return temp;
    }
};