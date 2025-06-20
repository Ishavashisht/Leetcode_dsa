class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>prefixIndex;
int prefixSum=0;
int maxLen=0;
prefixIndex[0]=-1; 
for(int i=0;i<nums.size();++i){//i=0 //i=1// i=2 i=3 //i=4  //i=5 
if(nums[i]==0){  //
prefixSum+=-1; 
}
else{
prefixSum+=1; //prefixSum=0 
}
if(prefixIndex.find(prefixSum)!=prefixIndex.end()){
int len=i-prefixIndex[prefixSum];   //  1-(-1)=2 // 2-0=2  // 4-0=4  // 5-(-1)=6
maxLen=max(maxLen,len); //maxLen=2 //max(2,4)=maxLen=4 //maxlen=max(4,6)=6 
}
else{
prefixIndex[prefixSum]=i;
}
}
return maxLen;// 6 

    }
};