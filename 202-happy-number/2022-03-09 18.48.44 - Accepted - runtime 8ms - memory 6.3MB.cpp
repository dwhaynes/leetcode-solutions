class Solution {
    set<int> seen;
public:
    bool isHappy(int n) {
        int to_n, from_n = n;
        while(from_n != 1){
            if(seen.find(from_n) != seen.end()) return false;
            seen.insert(from_n);
            to_n = 0;
            while(from_n){
                int digit = from_n % 10;
                to_n += digit*digit;
                from_n/=10;
            }
            from_n = to_n;
        }
        return true;
    }
};