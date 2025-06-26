class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
int count=0;
int val=0;
int bitPos=0;
for(int i=n-1;i>=0;i--){
if(s[i]=='0'){
count++;
}
else {
if(bitPos<31){
int add=1<<bitPos;
if(val+add<=k){
val+=add;
count++;
}}}
if(s[i]=='1' || s[i]=='0'){
bitPos++; 
}
}
return count; 
}

    
};