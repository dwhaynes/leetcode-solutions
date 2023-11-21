class Solution {
public:
    int strStr(string haystack, string needle) {
        int lh = haystack.size();
        int ln = needle.size();
        for(int i = 0; i < lh; i++){
            int j = 0;
            int k = i;
            while(i < lh && j < ln && haystack[i] == needle[j]){
                i++;
                j++;
            }
            if(j == ln) return k;
            i = k;
        }
        return -1;
    }
};