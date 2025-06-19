class Solution {
public:
    bool topologicalSort(unordered_map<int,vector<int>>&adj,int &numCourses,vector<int>&indegree){
queue<int>q;
int count=0;
for(int i=0;i<numCourses;i++){
    if(indegree[i]==0){
        q.push(i);
    
    }
}

while(!q.empty()){
    int u=q.front();
    q.pop();
      count++;
    for(int&v:adj[u]){
        indegree[v]--;
        if(indegree[v]==0){
            
q.push(v);
        }
      

    }
    if(count==numCourses)return true;//cycle not detected so able to complete it
    
}
return  false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();

     unordered_map<int,vector<int>>adj;
     vector<int>indegree(numCourses,0);
     for(vector<int>vec: prerequisites){
        int u=vec[0];
        int v=vec[1];
        adj[u].push_back(v);
        indegree[v]++;
     }
return topologicalSort(adj,numCourses,indegree);
    }
};