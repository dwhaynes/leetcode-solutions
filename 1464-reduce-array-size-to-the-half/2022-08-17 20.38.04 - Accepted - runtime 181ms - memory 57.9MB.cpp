class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> counts;
        int curRun = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i-1]){
                curRun++;
                continue;
            }
            counts.push_back(curRun);
            curRun=1;
        }
        counts.push_back(curRun);
        sort(counts.begin(),counts.end());
        reverse(counts.begin(),counts.end());
        
        int removed = 0;
        int sz = 0;
        for(auto count: counts){
            removed+=count;
            sz++;
            if(removed >= arr.size()/2) break;
        }
        return sz;
    }
};