class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        for(int i = 1; i < travel.size(); i++){
            travel[i] += travel[i-1];
        }

        unordered_map<char,int> last;
        int ans = 0;

        for(int i = 0; i < garbage.size(); i++){
            for(char c: garbage[i]){
                last[c] = i;
            }
            ans += garbage[i].size();
        }

        string types = "MPG";
        for(auto c: types){
            ans += last[c] == 0 ? 0 :travel[last[c]-1];
        }
        return ans;
    }
};