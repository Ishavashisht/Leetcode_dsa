class Solution {
public:
    bool solveUsingRecursion(vector<int>&arr,int index,int sum,int target){
        if(index>= arr.size()){
            return 0;
        }
        if(sum>target){
            return 0;
        }
        if(sum==target){
            return true;
        }
        //include //exclude
        int include=solveUsingRecursion(arr,index+1,sum+arr[index],target);
        int exclude=solveUsingRecursion(arr,index+1,sum,target);
        
        return include||exclude;
    }
    bool solveUsingMem(vector<int>&arr,int index,int sum,int target,vector<vector<int> >&dp){
        if(index>= arr.size()){
            return 0;
        }
        if(sum>target){
            return 0;
        }
        if(sum==target){
            return true;
        }
        //check if it already exist 
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        //include //exclude
        int include=solveUsingMem(arr,index+1,sum+arr[index],target,dp);
        int exclude=solveUsingMem(arr,index+1,sum,target,dp);
        
        return dp[index][sum]=(include||exclude);
    }
    bool solveUsingTabulation(vector<int>&arr,int target){
        int n=arr.size();
        vector<vector<int> >dp(n+2,vector<int>(target+1,0));
       //base case analyzes 
        for(int row=0;row<=n;row++){
            dp[row][target]=1;//hr row pe jao and target wale uspe 1 rkh dena 
        }
        for(int index=n-1;index>=0;index--){
            for(int s=target;s>=0;s--){
                bool include=0;
                //include tbhi krugi jab target se chota hoga index so
                if(s+arr[index]<=target){
                    //jab bhi tum dp m convert kr dete ho  u have to make sure jo bhi
                    //index access krne ki koshish kr rhe ho vo value ho
                    //agr vo invalid ho toh sochu ki ek extra condition toh nhi lgani pdegi 
                 include=dp[index+1][s+arr[index]];
                }
                bool exclude=dp[index+1][s];
                 dp[index][s]=(include||exclude );
            }
        }
        return dp[0][0];
    }
    bool solveUsingTabulationSO(vector<int>&arr,int target){
        int n=arr.size();
        //step1 //row wise array bane h 
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);
        curr[target]=1;
        next[target]=1;
        for(int index=n-1;index>=0;index--){
            for(int s=target;s>=0;s--){
                bool include=0;
                //include tbhi krugi jab target se chota hoga index so
                if(s+arr[index]<=target){
                    //jab bhi tum dp m convert kr dete ho  u have to make sure jo bhi
                    //index access krne ki koshish kr rhe ho vo value ho
                    //agr vo invalid ho toh sochu ki ek extra condition toh nhi lgani pdegi 
                 include=next[s+arr[index]];
                }
                //next==index+1
                bool exclude=next[s];
                 curr[s]=(include||exclude );
            }
            //shifting
            next=curr;
        }
        return next[0];
    }
    bool canPartition(vector<int>& nums) {
        int index=0;
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        if(totalSum &1){
            //odd cannot be partioned 
            return false;
        }
        int target=totalSum/2;
        int currSum=0;
        //vector<vector<int> >dp(nums.size()+1,vector<int>(target+1,-1));
        //  bool ans=solveUsingTabulation(nums,target);
         bool ans=solveUsingTabulationSO(nums,target);
        //bool ans=solveUsingRecursion(nums,index,currSum,target);
        //bool ans=solveUsingMem(nums,index,currSum,target,dp);
        return ans;
    }
};