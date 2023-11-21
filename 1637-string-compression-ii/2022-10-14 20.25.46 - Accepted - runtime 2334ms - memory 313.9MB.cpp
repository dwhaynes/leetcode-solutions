class Solution {
    unordered_map<int,int> memo;
    set<int> add = {1,9,99};
    int dp(string& s, int idx, char lastChar, int lastCharCount, int k){
        if(k < 0) return INT_MAX/2;
        
        if(idx == s.size()) return 0;
        
        int key = idx * 101 * 27 * 101 + (lastChar - 'a') * 101 * 101 + lastCharCount * 101 + k;
        
        if(memo.count(key)) return memo[key];
        
        int keepChar;
        int deleteChar = dp(s,idx+1,lastChar,lastCharCount,k-1);
        if (s[idx] == lastChar){
            keepChar = dp(s,idx+1,lastChar,lastCharCount+1,k) + add.count(lastCharCount);
        } else {
            keepChar = dp(s,idx+1,s[idx],1,k)+1;
        }
        int res = min(keepChar,deleteChar);
        memo[key] = res;
        return res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        return dp(s,0,'a'+26,0,k);
    }
};