class Solution {
public:
    string originalDigits(string s) {
        uint count[128];
        memset(count,0,sizeof(count));
        for(char c: s) count[c]++;
        
        int out[10];
        
        out[0] = count['z'];
        out[2] = count['w'];
        out[4] = count['u'];
        out[6] = count['x'];
        out[8] = count['g'];
        out[3] = count['h'] - out[8];
        out[5] = count['f'] - out[4];
        out[7] = count['s'] - out[6];
        out[9] = count['i'] - out[5] - out[6] - out[8];
        out[1] = count['n'] - out[7] - 2*out[9];
        
        stringstream ss;
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < out[i]; j++)
                ss << i;
        return ss.str();
    }
};