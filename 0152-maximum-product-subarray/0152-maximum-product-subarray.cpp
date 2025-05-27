class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxP=nums[0],currP=nums[0];
       for(int i=1;i<nums.size();i++){
        currP=max(nums[i],currP*nums[i]);
        maxP=max(maxP,currP);
       } 
       return maxP;
    }
};