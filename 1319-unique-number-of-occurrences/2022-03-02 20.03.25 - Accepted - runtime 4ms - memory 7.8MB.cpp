class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<bool> seen = vector<bool>(arr.size(),false);
        int count = 1;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++){
            if(arr[i-1] == arr[i]){
                count++;
            }else if(!seen[count]){
                seen[count]=true;
                count = 1;
            }else{
                return false;
            }
        }
        if(arr[n-1] != arr[n-2] && seen[1]) return false;
        return true;
    }
};