class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
for(char ch:s){
if(ch=='('){ 
low++;// low=1  →low=0 ->low=1
high++;//  high=1 high=2 ->high=3
}
else if(ch==')' ){
low--; //low =0 low=0-1=-1 // reset to low=0
high--;  //high=1 
}
else if(ch=='*'){
low--; //low=0
high++; //high=2
}
if(low<0)low=0;
if(high<0) return false;
}
return low==0; //return true

    }
};