class Solution {
public:
    int mySqrt(int x) {
        unsigned long long i = 0;
        while (i*i < (unsigned long long)x) i++;
        if(i*i > (unsigned long long)x) --i;
        return (int)i;
    }
};