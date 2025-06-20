class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty())return 0;
int maxNum=*max_element(nums.begin(),nums.end());  //maxNum=4
vector<int>freq(maxNum+1,0); // freq[2]=2 //freq[3]=3 //freq[4]=1 
for(int num:nums){
freq[num]++;
}
vector<int>points(maxNum+1,0); //points[2]=2*2=4 //points[3]=3*3=9 //points[4]=4*1=4 
for(int i=0;i<=maxNum;i++){
points[i]=i*freq[i];
} //points=[0,0,4,9,4]
vector<int>dp(maxNum+1,0);
dp[0]=0;
dp[1]=max(points[0],points[1]); 
for(int i=2;i<=maxNum;i++){  
dp[i]=max(dp[i-1],(dp[i-2]+points[i]));
}
return dp[maxNum]; 

    }
};