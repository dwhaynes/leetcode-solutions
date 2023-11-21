class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char,char> flipped;
        flipped['9']='6';
        flipped['6']='9';
        flipped['8']='8';
        flipped['1']='1';
        flipped['0']='0';
        int l = 0, r = num.size()-1;
        while(l <= r){
            if(flipped.find(num[l]) == flipped.end()) return false;
            if(flipped[num[l]] != num[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};