class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>lastIndex;
        int start=0,end=0;
        for(int i=0;i<s.size();i++){
            lastIndex[s[i]]=i;
        }
        vector<int>res;
        for(int i=0;i<s.length();i++){
            end=max(end,lastIndex[s[i]]);
            if(i==end){
                res.push_back(end-start+1);
                start=i+1;
            }
        }
        return res;
    }
};