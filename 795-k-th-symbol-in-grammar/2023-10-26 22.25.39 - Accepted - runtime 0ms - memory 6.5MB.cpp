class Solution {
    int recurse(int n, int k){
        if(n == 1) return 0;
        int nodes = pow(2,n-1);
        if(k > nodes/2) return 1-recurse(n,k-nodes/2);
        return recurse(n-1,k);
    }
public:
    int kthGrammar(int n, int k) {
        return recurse(n,k);
    }
};