class Solution {
public:
    char kthCharacter(int k) {
       string word="a";
       while(word.length()<k){
        string next="";
           for (char ch : word) {
        if(ch=='z')next+='a';
        else
        next+=(ch+1);
       }
       word+=next; 
    }
    return word[k-1];
    }
};