class Solution {
    int reverse(int n){
        n = (0xAAAAAAAA & n) >> 1 | (0x55555555 & n) << 1;
        n = (0xCCCCCCCC & n) >> 2 | (0x33333333 & n) << 2;
        n = (0xF0F0F0F0 & n) >> 4 | (0x0F0F0F0F & n) << 4;
        n = (0xFF00FF00 & n) >> 8 | (0x00FF00FF & n) << 8;
        n = (0xFFFF0000 & n) >> 16 | (0x0000FFFF & n) << 16;
        return n;
    }
    
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[this](const int& i, const int& j){
            int ri = reverse(i);
            int rj = reverse(j);
            return ri > rj;
        });
        return nums;
    }
};