class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numBytes = 0;
        
        int mask1 = 1 << 7;
        int mask2 = 1 << 6;
        
        for(int i = 0; i < data.size(); i++){
            if(numBytes == 0){
                int mask = 1 << 7;
                while((mask & data[i]) != 0){
                    numBytes++;
                    mask >>= 1;
                }
                
                if(numBytes == 0) continue;
                
                if(numBytes > 4 || numBytes == 1) return false;
            } else {
                if(!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) return false;
            }
            numBytes--;
        }
        return numBytes == 0;
    }
};