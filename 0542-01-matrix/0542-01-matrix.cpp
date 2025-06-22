class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int, int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int new_i = i + dir.first;
                int new_j = j + dir.second;
            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && ans[new_i][new_j]==INT_MAX){
                
                    ans[new_i][new_j]=ans[i][j]+1;
                    q.push({new_i,new_j});
                }
            }
        }
return ans;
    }
};