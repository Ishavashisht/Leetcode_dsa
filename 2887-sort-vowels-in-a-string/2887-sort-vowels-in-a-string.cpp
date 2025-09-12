class Solution {
public:
  bool isVowels(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='O'||ch=='U'||ch=='I';

  }
    string sortVowels(string s) {
        vector<char>vowels;
        for(char ch:s){
            if(isVowels(ch)){
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(),vowels.end());
       int idx=0;
        for(char &ch:s){
          if(isVowels(ch)){
             ch=vowels[idx++];
          }
        }
       return s;
    }
    
};