class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int sz = flowerbed.size();
        for(int i = 0; i < sz; i++){
            if(flowerbed[i] == 0){
                bool leftClear = (i == 0) || (flowerbed[i-1] == 0);
                bool rightClear = (i == sz-1) || (flowerbed[i+1] == 0);
                if(leftClear && rightClear){
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};