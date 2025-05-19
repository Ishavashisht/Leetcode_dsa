class Solution {
public:
    string triangleType(vector<int>& nums) {
        // vector<string>ans={"equilateral","isosceles","scalene","none"};
        if (nums.size() != 3) return "none";
        sort(nums.begin(),nums.end());
        int sum=0;
            if(nums[0]+nums[1]<=nums[2])
                return "none";
            if(nums[0]==nums[1]&& nums[1]==nums[2]){
                return "equilateral";
            }
            
            if(nums[0]==nums[1]||nums[1]==nums[2]){
                return "isosceles";
            }
            
        
            else
            return "scalene";
    }
      
    
     
    
};