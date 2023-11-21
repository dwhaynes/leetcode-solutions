class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> temp = {0};
        temp.insert(temp.end(),flowerbed.begin(),flowerbed.end());
        temp.push_back(0);
        for(int i = 1; i < temp.size() - 1; i++){
            if(temp[i] == 0 && temp[i-1]==0 && temp[i+1]==0){
                temp[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};