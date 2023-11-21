class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int r = minutesToTest/minutesToDie +1;
        int p = (int) ceil(log(buckets)/log(r));
        return p;
    }
};