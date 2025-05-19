class Solution {
public:
    int solveUsingRecursion(vector<int>& nums,int curr,int prev){
        //base case 
        if(curr>=nums.size()){
            return 0;
        }
        //include 
        int include=0;
        if(prev==-1||nums[curr]>nums[prev]){
            include=1+solveUsingRecursion(nums,curr+1,curr);
        }
        int exclude=0+solveUsingRecursion(nums,curr+1,prev);
        int ans=max(include,exclude);
        return ans;
    }
    int solveUsingMem(vector<int>& nums,int curr,int prev,vector<vector<int> >&dp){
         if(curr>=nums.size()){
            return 0;
        }
        //check weather it already exist 
        //index shifting
        //prev ko prev +1 isliye kiska becoz prev -1 h toh code out of bound chle jaege toh prev+1 kr k prev zero k equsl ho jaega 
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        //include 
        int include=0;
        if(prev==-1||nums[curr]>nums[prev]){
            include=1+solveUsingMem(nums,curr+1,curr,dp);
        }
        int exclude=0+solveUsingMem(nums,curr+1,prev,dp);
        dp[curr][prev+1]=max(include,exclude);
        return dp[curr][prev+1];
    }
    int solveUsingTabulation(vector<int>& nums){
        //create dp array
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int>(n+1,0));

        for(int curr_index=n-1;curr_index>=0;curr_index--){
          for(int prev_index=curr_index-1;prev_index>=-1;prev_index--){
          
          int include=0;
        if(prev_index==-1||nums[curr_index]>nums[prev_index]){
            //copy krne k baad dp m convert krna hota h 
            //iske baad ek baar current index check kr lo

            include=1+dp[curr_index+1][curr_index+1];
        }
        int exclude=0+dp[curr_index+1][prev_index+1];
        dp[curr_index][prev_index+1]=max(include,exclude);
        
          }  
        }
         return dp[0][0];//idr shifting ko handle krna h toh prev -1+1=0
    }
    int solveUsingTabulationSO(vector<int>& nums){
          int n=nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
       
        for(int curr_index=n-1;curr_index>=0;curr_index--){
          for(int prev_index=curr_index-1;prev_index>=-1;prev_index--){
          
          int include=0;
        if(prev_index==-1||nums[curr_index]>nums[prev_index]){
            //copy krne k baad dp m convert krna hota h 
            //iske baad ek baar current index check kr lo

            include=1+nextRow[curr_index+1];
        }
        int exclude=0+nextRow[prev_index+1];
        currRow[prev_index+1]=max(include,exclude);
        
          }  
          //shifting
          nextRow=currRow;
        }
         return nextRow[0];//idr shifting ko handle krna h toh prev -1+1=0
    }
    int solveUsingBS(vector<int>& nums){
        vector<int>ans;
        //initial state 
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                //just bada number exist krta hai
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                //replace 
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        int n=nums.size();
        //vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
        //int ans=solveUsingRecursion(nums,curr,prev);
        //int ans=solveUsingMem(nums,curr,prev,dp);
        //int ans=solveUsingTabulation(nums);
        //int ans=solveUsingTabulationSO(nums);
        int ans=solveUsingBS(nums);
        return ans;
    }
};