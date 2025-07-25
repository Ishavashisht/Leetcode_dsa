class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 1; 
        
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && word[j] == word[i]) { 
                j++;
            }
            
            int groupSize = j - i; 
            
            if (groupSize > 1) {
                count += (groupSize - 1); 
            }
            
            i = j; 
        }
        
        return count;
    }
};
