class Solution {
public:
    int uniqueLetterString(string s) {
        int total = 0;
        
        for(char c = 'A'; c <= 'Z';c++){
            int right = 0;
            while(right < s.size() && s[right]!=c) right++;
            
            int left = 0;
            int pos = right;
            
            while(pos < s.size()){
                do{
                    right++;
                }while(right < s.size() && s[right] != c);
                
                int leftDist = pos-left+1;
                int rightDist = right-pos;
            
                total+=leftDist*rightDist;
                left = pos+1;
                pos = right;
            }
        }
        return total;
    }
};