class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int minsum = 0;
        int start = 0;
        int n = cardPoints.size();
        int best = total;
        int wanted = n-k;
        if(k == n) return total;
        for(int i = 0; i < n; i++){
            minsum += cardPoints[i];
            int len = i - start + 1;
            if(len == wanted){
                best = min(best,minsum);
                minsum-= cardPoints[start++];
            }
        }
        return total-best;
    }
};