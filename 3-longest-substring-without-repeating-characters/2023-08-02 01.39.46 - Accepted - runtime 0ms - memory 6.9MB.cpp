class Solution {
    int counts[256];
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int maxlen = 1;
        int l = 0, r = 0;
        while(r < s.size()){
            counts[s[r]]++;
            while(counts[s[r]] > 1){
                counts[s[l]]--;
                l++;
            }
            if(maxlen < r-l+1) maxlen = r-l+1;
            r++;
        }
        return maxlen;
    }
};