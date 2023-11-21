class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        if(num1.size() != num2.size()){
            int len = num1.size() - num2.size();
            if(len > 0) num2+=std::string(len,'0');
            else num1+=std::string(-len,'0');
        }
        int carry = 0;
        stringstream ans;
        for(int i = 0; i < num1.size(); i++){
            int digit = carry;
            digit+=num1[i]-'0';
            digit+=num2[i]-'0';
            carry = digit/10;
            ans << (digit%10);
        }
        if(carry) ans << '1';
        string out = ans.str();
        reverse(out.begin(),out.end());
        return out;
    }
};