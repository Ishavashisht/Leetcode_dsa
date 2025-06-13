class Solution {
public:
    bool canForm(vector<int>&nums,int maxDiff,int p){
        int count = 0;
        int i = 0;
        int n = nums.size();
        
        while (i < n - 1) {
            if (abs(nums[i + 1] - nums[i]) <= maxDiff) {
                count++;
                i += 2; // Skip both used indices
            } else {
                i++;
            }
        }
        
        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
      // int high=nums.size()-1;
        int ans=0;
    int high = nums.back() - nums.front();
    while(low<=high){
        int mid=(low+high)/2;
        if(canForm(nums,mid,p)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
    }
};