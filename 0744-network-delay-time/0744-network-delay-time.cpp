class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(vector<int>&vec:times){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({wt,v});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>res(n+1,INT_MAX);
        res[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto&vec:adj[node]){
                int dist=vec.first;
                int adjNode=vec.second;
                if(d+dist<res[adjNode]){
                    res[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,res[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};