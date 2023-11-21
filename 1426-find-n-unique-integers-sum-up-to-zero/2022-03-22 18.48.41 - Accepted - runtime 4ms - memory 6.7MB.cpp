class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int val = 1;
        int sum = 0;
        while(n > 0){
            if(n==1){
                if(sum == 0){
                    res.push_back(0);
                }else{
                    res.push_back(-sum);
                }
                n--;
            }else{
                sum+=val;
                res.push_back(val);
                n--;
                val++;
            }
        }
        return res;
    }
};