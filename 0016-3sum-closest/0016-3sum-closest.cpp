class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
      
        int closestSum=nums[0]+nums[1]+nums[2];
       for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
           
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];  // Recalculate sum

                // Update closestSum if the current sum is closer to the target
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }
            if(sum>target){
               k--;
            }
            else if(sum<target){
                j++;
            }
            else{
            return sum;
            }
        }
       }
        return closestSum;
    }
};