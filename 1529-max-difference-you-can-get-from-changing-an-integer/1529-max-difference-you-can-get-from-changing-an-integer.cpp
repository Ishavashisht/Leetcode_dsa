class Solution {
public:
   string replaceString(string s,char fromDigit,char toDigit){
    for(char&ch:s){
        if(ch==fromDigit){
            ch=toDigit;
        }
    }
    return s;
   }
    int maxDiff(int num) {
        string original=to_string(num);
        string maxStr=original;
        string minStr=original;
        for(char ch:original){
            if(ch!='9'){
                maxStr=replaceString(original,ch,'9');
                break;
            }
        }
        if(original[0]!='1'){
            minStr=replaceString(original,original[0],'1');
        }
        else{
            for(int i=1;i<original.size();i++){
                if(original[i]!='1'&& original[i]!='0')
{
    minStr=replaceString(original,original[i],'0');
      break;
}            }
        }
        int a=stoi(maxStr);
        int b=stoi(minStr);
        return a-b;
    }
};