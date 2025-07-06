class Solution {
public:
   void dfs(int curr,int n,vector<int>&res){
    if(curr>n)return;
    res.push_back(curr);
    for(int i=0;i<=9;i++){
    if(curr*10+i>n)break;
    dfs(curr*10+i,n,res);
   }}
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i=1;i<=9;i++){
            dfs(i,n,res);
        }
        return res;
    }
};