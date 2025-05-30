class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;int high=*max_element(nums.begin(),nums.end());
        while(low<high){
        int mid=low+(high-low)/2;
        int total=0;
        for(int num:nums){
            total+=(num+mid-1)/mid;
        }
            if(total<=threshold){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        
    
    return low;
    }
};