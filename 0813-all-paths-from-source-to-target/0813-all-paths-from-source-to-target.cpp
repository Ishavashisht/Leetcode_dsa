class Solution {
public:
   void dfs(vector<vector<int>>& graph,int u,int v,vector<int>&path,vector<vector<int>>&res){
    path.push_back(u);
    if(u==v)res.push_back(path);
    else{
        for(int&ngb:graph[u]){
dfs(graph,ngb,v,path,res);
        }
    }
    path.pop_back();
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        vector<vector<int>>res;
        int n=graph.size();
        int source=0;
        int target=n-1;
        dfs(graph,source,target,path,res);
        return res;
    }
};