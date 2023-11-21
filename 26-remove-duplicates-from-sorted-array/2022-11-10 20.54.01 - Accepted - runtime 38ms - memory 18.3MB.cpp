class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 1;
        for(int read = 1; read < nums.size(); read++){
            if(nums[read-1] != nums[read]){
                nums[write] = nums[read];
                write++;
            }
        }
        return write;
    }
};