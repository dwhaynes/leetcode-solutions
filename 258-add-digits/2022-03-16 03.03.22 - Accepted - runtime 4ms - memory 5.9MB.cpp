class Solution {
public:
    int addDigits(int num) {
        int oldsum = num;
        while(oldsum > 9){
            int newsum = 0;
            while(oldsum){
                int digit = oldsum%10;
                oldsum/=10;
                newsum+=digit;
            }
            oldsum = newsum;
        }
        return oldsum;
    }
};