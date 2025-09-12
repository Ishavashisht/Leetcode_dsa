class Solution {
public:
    bool isVowels(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    bool doesAliceWin(string s) {
        int count=0;
        for(char ch:s){
            if(isVowels(ch)){
                count++;
            }
            if(count%2!=0){
                return true;
            }
        }
        return false;
    }
};