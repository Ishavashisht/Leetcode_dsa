class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int count=0;
        int lastEnd=INT_MIN;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0]>lastEnd){
                lastEnd=pairs[i][1];
                count++;
            }
        }
        return count;
    }
};