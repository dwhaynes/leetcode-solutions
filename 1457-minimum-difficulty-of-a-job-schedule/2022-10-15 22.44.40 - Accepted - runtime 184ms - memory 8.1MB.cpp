class Solution {
    vector<vector<int>> memo;
    vector<int> jobDifficulty;
    int minDiff(int i, int daysLeft){
        if(memo[i][daysLeft] != -1) return memo[i][daysLeft];
        
        if(daysLeft == 1) return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
        
        int res = INT_MAX;
        int dailyMaxJobDiff = 0;
        for(int j = i; j < jobDifficulty.size() - daysLeft + 1; j++){
            dailyMaxJobDiff = max(dailyMaxJobDiff, jobDifficulty[j]);
            res = min(res, dailyMaxJobDiff + minDiff(j+1, daysLeft-1));
        }
        memo[i][daysLeft] = res;
        return res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->jobDifficulty = jobDifficulty;
        int n = jobDifficulty.size();
        if(n < d) return -1;
        memo = vector<vector<int>>(n,vector<int>(d+1,-1));
        return minDiff(0,d);
    }
};