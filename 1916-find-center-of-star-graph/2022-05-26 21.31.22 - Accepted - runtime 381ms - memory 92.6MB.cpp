class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> hist;
        for(auto e: edges){
            hist[e[0]]++;
            hist[e[1]]++;
        }
        int maxkey = -1;
        int maxvalue = -1;
        for(auto [key,value]: hist){
            if(value > maxvalue){
                maxvalue = value;
                maxkey = key;
            }
        }
        return maxkey;
    }
};