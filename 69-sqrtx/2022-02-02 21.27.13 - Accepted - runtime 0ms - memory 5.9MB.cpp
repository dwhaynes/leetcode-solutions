class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        double x0 = double(x);
        double x1 = (x0 + x/x0)/2;
        while(fabs(x0-x1) >=1.0){
            x0 = x1;
            x1 = (x0 + x/x0)/2;
        }
        return int(x1);
    }
};