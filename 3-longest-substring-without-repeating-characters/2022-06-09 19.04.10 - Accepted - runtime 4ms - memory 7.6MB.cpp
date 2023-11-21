class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, res = 0;
        vector<int> chars(128);
        while(right < s.size()){
            char r = s[right];
            chars[r]++;
            while(chars[r] > 1){
                char l = s[left];
                chars[l]--;
                left++;
            }
            res = max(res,right-left+1);
            right++;
        }
        return res;
    }
};