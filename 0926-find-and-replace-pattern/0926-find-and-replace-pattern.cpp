class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
         auto matchesPattern = [](const string& word, const string& pattern) -> bool {
        unordered_map<char,char>map_pattern_to_word;
        unordered_map<char,char>map_word_to_pattern;
        for(int i=0;i<word.length();i++){
            char p=pattern[i];
            char w=word[i];
            if(map_pattern_to_word.count(p)&& map_pattern_to_word[p]!=w){
                return false;
            }
            if(map_word_to_pattern.count(w)&& map_word_to_pattern[w]!=p){
                return false;
            }
            map_pattern_to_word[p]=w;
            map_word_to_pattern[w]=p;
        }
        return true;
         };
         for(const string&word:words){
            if(matchesPattern(word,pattern)){
                res.push_back(word);
            }
         }
return res;
    }
};