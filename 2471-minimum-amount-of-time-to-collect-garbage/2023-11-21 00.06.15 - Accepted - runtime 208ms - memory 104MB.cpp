class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> distance(travel.size()+1,0);
        distance[1] = travel[0];
        for(int i = 1; i < travel.size(); i++){
            distance[i+1] = distance[i] + travel[i];
        }
        unordered_map<char,int> last;
        unordered_map<char,int> count;
        for(int i = 0; i < garbage.size(); i++){
            for(char c: garbage[i]){
                count[c]++;
                last[c] = i;
            }
        }
        char types[3] = {'M','P','G'};
        int ans = 0;
        for(auto c: types){
            if(count[c])
            ans += count[c] + distance[last[c]];
        }
        return ans;
    }
};