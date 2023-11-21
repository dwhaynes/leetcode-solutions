class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        vector<vector<int>> hist;
        vector<int> last(3,0);
        for(int i = 0; i < garbage.size(); i++){
            int m = 0;
            int g = 0;
            int p = 0;
            for(auto c: garbage[i]){
                if (c == 'M') m++;
                else if (c == 'G') g++;
                else p++;
            }
            hist.push_back({m,g,p});
            if(m != 0) last[0] = i;
            if(g != 0) last[1] = i;
            if(p != 0) last[2] = i;
        }
        for(int i = 0; i < hist.size(); i++){
            for(int j = 0; j < 3; j++){
                time += hist[i][j];
                if(i < last[j]) time += travel[i];
            }
        }
        return time;
    }
};