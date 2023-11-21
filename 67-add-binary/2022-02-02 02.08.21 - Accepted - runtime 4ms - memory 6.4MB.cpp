class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string result = "";
        int na = a.size();
        int nb = b.size();
        if (na < nb){
            string fill(nb-na,'0');
            a+=fill;
        }
        if (nb < na){
            string fill(na-nb,'0');
            b+=fill;
        }
        int sz = a.size();
        
        int carry = 0;
        for(int i = 0; i < sz; i++){
            int digit= a[i]-'0';
            digit+= b[i]-'0';
            digit+=carry;
            carry = digit/2;
            digit%=2;
            result+=(digit + '0');
        }
        if (carry) result+='1';
        reverse(result.begin(),result.end());
        return result;
    }
};