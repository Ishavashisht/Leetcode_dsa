class Solution {
public:
int maxCycle=-1;
    void DFS(vector<int>&edges,int u,vector<bool>&vis,vector<int>&inRecursion,int depth){
        vis[u]=true;
        inRecursion[u]=depth;
        int nxt=edges[u];
        if(nxt!=-1){
            if(!vis[nxt]){
                DFS(edges,nxt,vis,inRecursion,depth+1);
            }
            else if(inRecursion[nxt]!=-1){
                maxCycle=max(maxCycle,depth-inRecursion[nxt]+1);
            }
        }
        inRecursion[u]=-1;
    }
    int longestCycle(vector<int>& edges) {
        int V=edges.size();
      
         
        vector<bool>vis(V,false);
        vector<int>inRecursion(V,-1);
       
        for(int i=0;i<V;i++){
            if(!vis[i] ) DFS(edges,i,vis,inRecursion,0);
               
            }
            return maxCycle;
    }
};