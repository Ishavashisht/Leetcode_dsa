class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
     vector<vector<int>>ans;
     
     sort(nums.begin(),nums.end());
     int sum=0;
     for(int i=0;i<nums.size();i++){
         int j=i+1,k=nums.size()-1;
         if (i > 0 && nums[i] == nums[i - 1]) continue;
        while(j<k){
sum=nums[i]+nums[j]+nums[k];
if(sum<0){
    j++;
}
else if(sum>0){
    k--;
}
else {
    ans.push_back({nums[i], nums[j], nums[k]});

                    // Move j and k to the next unique elements
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
    }
        }
     }
     return ans;
    }
};