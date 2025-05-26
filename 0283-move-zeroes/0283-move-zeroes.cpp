class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zerotracker=0;
        for(int nonzero=0;nonzero<nums.size();nonzero++){
            if(nums[nonzero]!=0){
                swap(nums[nonzero],nums[zerotracker]);
            zerotracker++;
            }
                
        }
       
    }
};