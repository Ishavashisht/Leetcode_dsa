class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited, vector<bool>&inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        for(int&v:adj[u]){
            if(!visited[v]&& dfs(adj,v,visited,inRecursion))return true;
            else if(inRecursion[v]==true)return true;

        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>>adj;
        for(vector<int>&vec:prerequisites){
            int u=vec[0];
            int v=vec[1];
            //v->u
adj[v].push_back(u);

        }
        vector<bool>visited(numCourses,false);
        vector<bool>inRecursion(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]&& dfs(adj,i,visited,inRecursion))return false;

        }
        return true;
    }
};