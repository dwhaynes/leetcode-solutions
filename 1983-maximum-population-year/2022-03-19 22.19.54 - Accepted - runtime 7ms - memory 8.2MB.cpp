class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> pop = vector<int>(101,0);
        vector<int> cumpop;
        for(auto log: logs){
            pop[log[0] - 1950]++;
            pop[log[1] - 1950]--;
        }
        partial_sum(pop.begin(),pop.end(),back_inserter(cumpop));
        auto it = max_element(cumpop.begin(),cumpop.end());
        return distance(cumpop.begin(), it) + 1950;
    }
};