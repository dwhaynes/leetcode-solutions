class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        long maxHeight = max(horizontalCuts[0],h-horizontalCuts.back());
        for(int i = 1; i < n; i++){
            maxHeight = max(maxHeight,(long) horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        long maxWidth = max(verticalCuts[0],w-verticalCuts.back());
        for(int i = 1; i < m; i++){
            maxWidth = max(maxWidth,(long) verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return (int) ((maxWidth*maxHeight)%1000000007);
    }
};