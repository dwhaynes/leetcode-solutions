class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n,'a');
        k-=n;
        for(int pos = n-1; pos >= 0 && k > 0; pos--){
            int add = min(k,25);
            result[pos]+= add;
            k-=add;
        }
        return result;
    }
};