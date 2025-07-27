class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        int l=0,r=0;
        while(r<nums.size()-1){
            int farthest=0;
            for(int index=l;index<=r;index++){
                farthest=max(farthest,index+nums[index]);
            }
            l=r+1;
            r=farthest;
            count++;
        }
        return count;
    }
};