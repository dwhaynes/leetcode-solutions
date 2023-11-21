class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int freqp[101] = {}, freqn[101] = {}, fa, fb;
        for(auto n: nums){
            if(n > 0) freqp[n]++;
            else freqn[-n]++;
        }
        sort(nums.begin(), nums.end(),[&](int a, int b){
            fa = a > 0 ? freqp[a] : freqn[-a];
            fb = b > 0 ? freqp[b] : freqn[-b];
            return fa == fb ? b < a : fa < fb;
        });
        return nums;
    }
};