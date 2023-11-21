class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int startingIndex = 0;
        int presentSubarrayScore = 0;
        int n = cardPoints.size();
        int requiredSubarrayLength = n-k;
        int minSubarrayScore;
        int totalScore = accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        minSubarrayScore = totalScore;
        
        if(k == n) return totalScore;
        
        for(int i = 0; i < n; i++){
            presentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startingIndex + 1;
            if(presentSubarrayLength == requiredSubarrayLength){
                minSubarrayScore = min(minSubarrayScore,presentSubarrayScore);
                presentSubarrayScore -= cardPoints[startingIndex++];
            }
        }
        return totalScore-minSubarrayScore;
    }
};